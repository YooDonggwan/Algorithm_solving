#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

bool cmp(int a, int b){
    return a < b;
}

int main() {
    int n;
    int dp[1001];
    scanf("%d", &n);

    vector<int> time(n+1, 0);

    for(int i = 1; i <= n; i++){
        scanf("%d", &time[i]);
    }

    sort(time.begin()+1, time.end(), cmp);

    dp[1] = time[1];
    for(int i = 2; i <= n; i++){
        dp[i] = dp[i-1] + time[i];
    }

    int answer = 0;
    for(int i = 1; i <= n; i++){
        answer += dp[i];
    }

    printf("%d", answer);

    return 0;

}