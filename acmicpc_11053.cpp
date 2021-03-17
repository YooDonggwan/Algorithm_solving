#include <stdio.h>
#include <vector>

using namespace std;

int n;
vector<int> arr(1001, 0);

int max(int a, int b){
    if(a >= b){
        return a;
    }else{
        return b;
    }

}

int main(){

    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    
    vector<int> dp(1001, 1);
    int ans = 1;
    for(int i = 1; i < n; i++){
        for(int j = 0; j < i; j++){
            if(arr[i] > arr[j]){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ans = max(ans, dp[i]);
    }

    printf("%d", ans);

    return 0;

}