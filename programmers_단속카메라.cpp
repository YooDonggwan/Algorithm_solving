#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

// 가장 많이 겹치는 부분으로 골라야함

int solution(vector<vector<int>> routes) {
    int answer = 0;
    
    sort(routes.begin(), routes.end());
    
    int camera = 1;
    int out = routes[0][1];
    for(int i = 0; i < routes.size(); i++){
        if(out >= routes[i][0]){
            // 다음 차량의 시작점보다 나가는 지점이 더 크면
            // 여러 포함 관계를 가질 수 있으므로 끝나는 지점이 더 작은 쪽이 들어가야 함
            out = min(out, routes[i][1]); 
        }
        else{
            // 다음 차량의 시작점보다 나가는 지점이 작으면 카메라 추가해야함
            camera++;
            out = routes[i][1]; // 다음 포함관계 봐야 함
        }
    }
    answer = camera;
    
    return answer;
}