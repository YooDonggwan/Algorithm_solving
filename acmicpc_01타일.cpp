#include <stdio.h>
#include <vector>

using namespace std;

int n;

int main() {
    scanf("%d", &n);

    vector<long long> dp(1000001, 0);

    //1 1
    //2 2
    //3 100 001 111 3
    //4 5
    //5 
    dp[1] = 1;
    dp[2] = 2;
    for(int i = 3; i <= n; i++){
        dp[i] = dp[i-1] + dp[i-2] % 15746;
    }

    printf("%lld", dp[n] % 15746);

    return 0;

}