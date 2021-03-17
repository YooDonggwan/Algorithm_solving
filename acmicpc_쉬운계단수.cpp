#include <stdio.h>
#include <vector>

using namespace std;

int n;

int main() {
    scanf("%d", &n);
    vector<vector<long long> > dp(101, vector<long long>(11, 0));

    // dp[i][j] i는 자리수 j는 0-9
    // 0  dp[i][j] = dp[i-1][j+1] 
    // 1-8 dp[i][j] = dp[i-1][j-1] + dp[i-1][j+1];
    // 9 dp[i][j] = dp[i-1][j-1]
    
    dp[1][0] = 0;
    for(int i = 1; i <= 9; i++){
        dp[1][i] = 1;
    }

    for(int i = 2; i <= n; i++){
        for(int j = 0; j <= 9; j++){
            if(j == 0){
                dp[i][j] = dp[i-1][j+1] % 1000000000; 
            } else if(j == 9){
                dp[i][j] = dp[i-1][j-1] % 1000000000;
            } else{
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j+1] % 1000000000;
            }
        }
    }

    long long ans = 0;
    for(int i = 0; i <= 9; i++){
        ans += dp[n][i];
    }

    printf("%lld", ans % 1000000000);

    return 0;

}