#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> q;
    
    int day, rest;
    
    for(int i = 0; i < progresses.size(); i++){
        // queue에 프로세스 처리되는데 걸리는 기간 푸시
        rest = 100 - progresses[i];
        if(rest % speeds[i] == 0)
            day = rest / speeds[i];
        else
            day = (rest / speeds[i]) + 1;
        q.push(day);
    }
    
    int start = q.front();
    int success = 0;
    while(!q.empty()){
        if(q.front() <= start){ // 뒤의 작업에 더 빨리 끝났던 게 있으면
            q.pop();
            success++;
        }
        else{ // 다음 날로 보냄
            start = q.front();
            answer.push_back(success);
            success = 0; 
            continue;
        }
    }
    answer.push_back(success); // 마지막 값 넣어줘야 함
    
    
    
    return answer;
}