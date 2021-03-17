#include <stdio.h>
#include <vector>

using namespace std;

int n;
vector<int> num(100000, 0);

int max(int a, int b){
    if(a >= b){
        return a;
    }
    else{
        return b;
    }
}

int main() {
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf("%d", &num[i]);
    }

    vector<int> dp(n, 0);
    vector<bool> check(n, false);

    dp[0] = num[0];
    int ans = num[0];

    for(int i = 1; i < n; i++){
        dp[i] = max(dp[i-1] + num[i], num[i]);
        ans = max(ans, dp[i]);
    }

    printf("%d", ans);

    return 0;

}