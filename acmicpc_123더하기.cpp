#include <stdio.h>

using namespace std;

int dp[12] = {0,};

int main(){
    int t;

    scanf("%d", &t);
    int n[t];
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;

    for(int j = 4; j < 11; j++){
            dp[j] = dp[j-1] + dp[j-2] + dp[j-3];
    }

    for(int i = 0; i < t; i++){
        scanf("%d", &n[i]);
        
        printf("%d\n", dp[n[i]]);
    }

    
    return 0;

    
}