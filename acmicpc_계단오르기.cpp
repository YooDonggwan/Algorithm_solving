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
    scanf("%d", &n);
    int s[301] = {0, };
    int dp[301] = {0, }; // dp배열에는 n계단까지 최대

    for(int i = 1; i <= n; i++){
        scanf("%d", &s[i]);
    }
   
    dp[1] = s[1];
    dp[2] = s[1] + s[2];
    dp[3] = max(s[1]+s[3], s[2]+s[3]);


    for(int i = 4; i <= n; i++){
        // 처음엔
        // dp[i] = max(dp[i-1] + s[i], dp[i-2] + s[i]) 라고 생각했는데
        // n을 꼭 밟아야 해서 조건을 아래로 바꿈
        dp[i] = max(dp[i-2] + s[i], dp[i-3] + s[i-1] + s[i]);
    }
    

    printf("%d", dp[n]);

    return 0;
}