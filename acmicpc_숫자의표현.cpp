#include <string>
#include <vector>
#include <iostream>

using namespace std;
int answer = 0;

void dfs(int want, int start_num, int finish_num, int total, int cnt) {
    if(start_num > want){ // 종료조건
        return;
    }
    for(int i = start_num; i <= finish_num; i++){
        total += i;
    }
    
    if(total > want){ // 원하는 수보다 크면 시작 수와 마지막 수 초기화
        total = 0;
        dfs(want, start_num+1, start_num+1, total, cnt+1);
    }
    else if(total == want){ // 원하는 수와 같으면 answer+1 해주고 시작 수 마지막 수 초기화
        answer++;
        total = 0;
        dfs(want, start_num+1, start_num+1, total, cnt+1);
    }
    else{ // total < want // 원하는 수보다 작으면 마지막 수 하나 더 늘려보기
        total = 0;
        dfs(want, start_num, finish_num+1, total, cnt+1);
    }
    
    return;
    
}

int solution(int n) {
    
    dfs(n, 1, 1, 0, 0);
    return answer;
}