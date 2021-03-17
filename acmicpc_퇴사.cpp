#include <stdio.h>
#include <vector>

using namespace std;

int n;
vector<int> t(16, 0);
vector<int> pay(16, 0);

int max(int a, int b){
    if(a >= b){
        return a;
    } else {
        return b;
    }
}

int max_pay = 0;
int dp[16] = {0,};

int main() {
    
    scanf("%d", &n);
    
    for(int i = 1; i <= n; i++){
        scanf("%d %d", &t[i], &pay[i]);
    }

    // dp[i] = max(dp[i+time[i]] + pay[i], dp[i+1])

    // dp를 풀 땐 역으로도 생각해야 하고, 점화식을 먼저 떠올리자
    // 역으로 가는 이유는 일을 못하는 동안 얻는 페이에 그 다음 일하는 것을 더해야하기때문
    for(int i = n; i >= 1; i--){
        if(i + t[i] - 1 > n){
            dp[i] = dp[i+1];
            continue;
        }
        dp[i] = max(dp[i+t[i]] + pay[i], dp[i+1]);
    }

    printf("%d", dp[1]);

    return 0;


}