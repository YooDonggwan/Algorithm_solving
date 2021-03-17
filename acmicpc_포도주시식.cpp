#include <stdio.h>
#include <vector>

using namespace std;

int n;
vector<int> wine(10000, 0);

int max(int a, int b){
    if(a >= b){
        return a;
    }
    else{
        return b;
    }
}

int main(){
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf("%d", &wine[i]);
    }

    vector<int> dp(n, 0);

    // n번째까지 마실 수 있는 최대 양
    dp[0] = wine[0];
    dp[1] = dp[0] + wine[1];
    dp[2] = max(wine[0] + wine[2], max(wine[1] + wine[2], dp[1]));
    for(int i = 3; i < n; i++){
        dp[i] = max(dp[i-2] + wine[i], max(dp[i-3] + wine[i-1] + wine[i], dp[i-1]));
    }


    printf("%d", dp[n-1]);

    return 0;

}