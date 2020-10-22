#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    queue<int> enter_weight, time;
    int weight_now = 0;
    
    
    for(int i = 1; ; i++){
        if(time.size() > 0){
            if(i - time.front() == bridge_length){
                // 다 건넜으면
                int finish_time = bridge_length + time.front();
                time.pop();
                weight_now -= enter_weight.front();
                enter_weight.pop();
                if(truck_weights.size() == 0 && enter_weight.size() == 0){
                    return finish_time;
                }
            }
        }
        while(1){
            if(weight_now + truck_weights.front() > weight || truck_weights.size() == 0)
                break;
            else{
                enter_weight.push(truck_weights.front());
                weight_now += truck_weights.front();
                truck_weights.erase(truck_weights.begin());
                time.push(i);
                break;
            }
        }
    }
    
    
    return answer;
}