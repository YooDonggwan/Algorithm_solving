#include <stdio.h>

using namespace std;

int max(int a, int b){
    if(a >= b){
        return a;
    }
    else{
        return b;
    }
}

int main() {
    int n;
    int map[501][501] = {0, }; 
    int dp[501][501] = {0,};
    scanf("%d", &n);

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            scanf("%d", &map[i][j]);
        }
    }

    if(n == 1){
        printf("7");
        return 0;
    }

    dp[1][1] = map[1][1];
    for(int i = 2; i <= n; i++){
        for(int j = 1; j <= i; j++){
            if(j == 1){
                dp[i][j] = dp[i-1][j] + map[i][j];
            }
            else if(j == i){
                dp[i][j] = dp[i-1][j-1] + map[i][j];
            }
            else{
                dp[i][j] = max(dp[i-1][j-1] + map[i][j], dp[i-1][j] + map[i][j]);
            }
        }
    }

    int answer = 0;
    for(int i = 1; i <= n; i++){
        if(answer < dp[n][i]){
            answer = dp[n][i];
        }
    }

    printf("%d", answer);

    return 0;

}