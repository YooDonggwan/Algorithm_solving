#include <stdio.h>

using namespace std;

int dp[1000001];

int min(int a, int b){
    if(a < b){
        return a;
    }
    else{
        return b;
    }
}

int main() {
    int x;

    scanf("%d", &x);

    dp[1] = 0;
    int answer = 0;

    for(int i = 2; i <= x; i++){
        dp[i] = dp[i-1] + 1;
        if(i % 2 == 0){ // 2로 나누어지면
            dp[i] = min(dp[i], dp[i/2] + 1);
        }
        if(i % 3 == 0){
            dp[i] = min(dp[i], dp[i/3] + 1);
        }
    }

    

    answer = dp[x];

    printf("%d", answer);

    return 0;
}