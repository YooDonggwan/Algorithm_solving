#include <iostream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

string tmp = "";

int solution(string name) {
    int answer = 0;
    int n = name.length();
    
    // 초기 문자열 생성
    for(int i = 0; i < n; i++){
        tmp += 'A';
    }
    
    // 왼쪽으로 갈지 오른쪽으로 갈지 결정
    int min_move = n - 1;
    
    for(int i = 0; i < n; i++){
        // 이전 알파벳으로 갈지 다음 알파벳으로 갈지 결정
        int go_front = name[i] - 'A';
        int go_back = 'Z' - name[i] + 1;
        
        if(go_front > go_back){
           answer += go_back; 
        }
        else{
            answer += go_front;
        }
        
        // 현 위치에서 오른쪽 / 왼쪽 골라야 함
        int next = i+1;
        while(next < n && name[next] == 'A'){
            // 오른쪽에 A가 있으면
            next++;
        }
        min_move = min(min_move, i + n - next + min(i, n-next));
    }
    
    answer += min_move;
    
    return answer;
}