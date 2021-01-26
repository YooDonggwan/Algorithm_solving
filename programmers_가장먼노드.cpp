#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

bool cmp(int a, int b){
    return a > b;
}

int solution(int n, vector<vector<int>> edge) {
    vector<vector<bool>> map(n, vector<bool>(n, false));
    vector<bool> visit(n, false);
    vector<int> minDist(n, 0);
    int answer = 0;
    
    // 경로 map에 넣기
    for(auto vertex : edge){
        map[vertex[0]-1][vertex[1]-1] = true;
        map[vertex[1]-1][vertex[0]-1] = true;
    }
    
    // 1부터 최단경로 구하기 - bfs
    queue<int> q;
    visit[0] = true;
    q.push(0);
    while(!q.empty()){ // bfs
        int start = q.front();
        q.pop();
        for(int i = 0; i < n; i++){
            if(map[start][i] && !visit[i]){ // 길이 있으면
                minDist[i] = 1 + minDist[start]; // 현재 큐에 있는 점보다 하나 더 가면됨
                q.push(i);
                visit[i] = true;
            }
        }
    }
    
    
    sort(minDist.begin(), minDist.end(), cmp); // 내림차순 정렬
    
    int max = minDist.front();
    for(int i = 0; i < minDist.size(); i++){
        if(minDist[i] == max){
            answer++;
        }
    }
    
    return answer;
}