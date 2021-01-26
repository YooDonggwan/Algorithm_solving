#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

bool cmp(vector<int> a, vector<int> b){
    return a[0] < b[0];
}

struct compare{
    bool operator()(vector<int> a, vector<int> b){
        return a[1] > b[1];
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int total_size = jobs.size();
    int tictoc = 0;
    priority_queue<vector<int>, vector<vector<int>>, compare> waitQ; // 대기큐
    vector<int> finish; // 종료된 작업들의 걸린 시간
    
    sort(jobs.begin(), jobs.end(), cmp);
    
    int j = 0, k = 0;
    while(finish.size() < jobs.size()){ // 사이즈 같아지면 모든 작업처리 완료
        // 대기 큐 생성
        if(j < jobs.size() && jobs[j][0] <= tictoc){
            waitQ.push(jobs[j]);
            j++;
            continue;
        }
        
        if(!waitQ.empty()){ // 큐에 있는 것 처리
            vector<int> toProcess = waitQ.top();
            int totalProcessTime = (tictoc - toProcess[0]) + toProcess[1];
            finish.push_back(totalProcessTime);
            tictoc += toProcess[1];
            waitQ.pop();
        }
        else{ // 하드디스크가 작업을 수행하고 있지 않을 시 새로운 작업요청시간부터 시작하면 된다고 생각
            tictoc = jobs[j][0];   
        }
        
    }
    int sum = 0;
    for(int i = 0; i < finish.size(); i++){
        sum += finish[i];
    }
    answer = sum / finish.size();
    
    return answer;
}