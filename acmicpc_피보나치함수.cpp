#include <stdio.h>
#include <vector>

using namespace std;


int main(){
    int t;
    scanf("%d", &t);
    int n[t];
    vector<pair<int,int> > dp(41, make_pair(0, 0));
    vector<pair<int, int> > answer;
    dp[0].first = 1;
    dp[0].second = 0;
    dp[1].first = 0;
    dp[1].second = 1;

    for(int i = 2; i <= 40; i++){
        dp[i].first = dp[i-1].first + dp[i-2].first;
        dp[i].second = dp[i-1].second + dp[i-2].second;
    }

    for(int i = 0; i < t; i++){
        scanf("%d", &n[i]);
        
        printf("%d %d\n", dp[n[i]].first, dp[n[i]].second);
    }

    

    return 0;


}


// 0: 1 0
// 1: 0 1
// 2: 1 1
// 3: 1 2
// 4: 2 3
// 5: 3 5
