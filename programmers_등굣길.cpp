#include <string>
#include <vector>

using namespace std;

int map[101][101];

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    
    for(int i = 0;i < puddles.size(); i++){ // 물웅덩이 map에 표시
        int a = puddles[i][0];
        int b = puddles[i][1];
        map[b][a] = 2;
    }
    
    map[1][0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(map[i][j] == 2){
                map[i][j] = 0;
                continue;
            }
            else{
                map[i][j] = (map[i-1][j] + map[i][j-1]) % 1000000007;
            }
        }
    }
    

    return map[n][m] % 1000000007;
}