#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <math.h>       /* log10 */
using namespace std;


vector<float> sense(vector<float> prob, string measurement, vector<string> world){

    vector<float> prob_updated (5,0.0);
    float pHit = 0.6;
    float pMiss = 0.2;
    //normalize
    float sum = 0.0;
    //loop over all prob
    for(int i =0; i < prob.size();++i){
        bool hit = (measurement == world[i]);
        //cout << measurement;
        //cout << hit;
        float target_prob = hit*pHit + (1-hit)*pMiss;
        prob_updated[i] = prob[i] * target_prob;

        sum = sum + prob_updated[i];

    }

    //normalize
    for(int i =0; i < prob.size();++i){
        prob_updated[i] = prob_updated[i] / sum;
    }

    return prob_updated;
}


vector<float> move(vector<float> prob, int move){

    //total prob will be 1
    float pExact = 0.8; //the real sensor data contribution.
    float pOvershoot_move_one_more_block = 0.1;// 0.1 probability to move with Overshoot i step
    float pUndershoot_move_less_one_block = 0.1;


    vector<float> prob_updated (5,0.0);
    //shift the valure in prob right, since we move 1 step to right
    //assume the world is a 1d loop
    for(int i =0; i < prob.size();++i){

        float new_prob_for_this_i_block = 0.0;


        //Note: the prob of position i, will be affected by three casese.

        //case1
        //this block could be a case of Exact move position from left block
        int move_from_index = ( i- move ) % prob.size();
        new_prob_for_this_i_block = pExact * prob[move_from_index];

        //case2
        //someone's overshot will also contributed some probability
        int move_from_index_overshot = move_from_index -1;
        new_prob_for_this_i_block = new_prob_for_this_i_block + pOvershoot_move_one_more_block * prob[move_from_index_overshot];

        //case3
        //someone undershot
        int move_from_index_undershot = move_from_index + 1;
        new_prob_for_this_i_block = new_prob_for_this_i_block + pUndershoot_move_less_one_block * prob[move_from_index_undershot];

        //updated
        prob_updated[i] = new_prob_for_this_i_block;

    }

    return prob_updated;

}

//# uncertainty up, entorpy up
float entorpy(vector<float> prob){

    float entorpy = 0.0;

    for(int i =0; i < prob.size();++i){

        float tmpentorpy = -1 * prob[i] * log10(prob[i]);
        //(-1*p[i]*math.log(p[i],10))
        //sum
        entorpy = entorpy + tmpentorpy;
    }
    cout << "entorpy:"<< entorpy << endl;
    return entorpy;
}

void print_prob(vector<float> prob,string prefix_name){
    //print
    cout << prefix_name << endl;

    for(int i =0; i < prob.size();++i){
        cout << prob[i] << " ";
    }
    cout << endl;
}

int main() {

    vector<float> prob (5,0.2);
    vector<string> worlds(5);
    //world features
    worlds[0] = "green";
    worlds[1] = "red";
    worlds[2] = "red";
    worlds[3] = "green";
    worlds[4] = "green";

    //sensor reading
    vector<string> measurements(2);
    measurements[0] = "red";
    measurements[1] = "green";


    //motion
    vector<int> motion(measurements.size(),1);

    //float pHit = 0.6;
    //float pMiss = 0.2;
    //float pExact = 0.8;
    //float pOvershoot = 0.1;
    //float pUndershoot = 0.1;


    print_prob(prob,"initial");
    for(int i =0; i < measurements.size();++i){
        prob = sense(prob, measurements[i],worlds);
        print_prob(prob,"sensed");
        entorpy(prob);

        prob = move(prob, motion[i]);
        print_prob(prob,"moveed");
        entorpy(prob);

    }

    return 0;
}


/*
python code




p = [0.2, 0.2, 0.2, 0.2, 0.2]
world = ['green', 'red', 'red', 'green', 'green']
measurements = ['red', 'green']
motions = [1,1]
pHit = 0.6
pMiss = 0.2
pExact = 0.8
pOvershoot = 0.1
pUndershoot = 0.1

def sense(p, Z):
    q=[]
    for i in range(len(p)):
        hit = (Z == world[i])
        q.append(p[i] * (hit * pHit + (1-hit) * pMiss))
    s = sum(q)
    for i in range(len(q)):
        q[i] = q[i] / s
    return q

def move(p, U):
    q = []
    for i in range(len(p)):
        s = pExact * p[(i-U) % len(p)]
        s = s + pOvershoot * p[(i-U-1) % len(p)]
        s = s + pUndershoot * p[(i-U+1) % len(p)]
        q.append(s)
    return q

for k in range(len(measurements)):
    p = sense(p, measurements[k])
    p = move(p, motions[k])

print p




#entropy measures the amount of uncertainty
# uncertainty up, entorpy up
def entorpy(p):
    result=[]
    for i in range(len(p)):
        #print(-1*p[i])
        #print(math.log(p[i],10))
        result .append( (-1*p[i]*math.log(p[i],10)))
        #print(result)

    return sum(result)
*/
