#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(int a, int b){
    return a > b;
}

int main() {
    int n, k;
    int cnt = 0;
    scanf("%d %d", &n, &k);
    vector<int> value(n, 0);

    for(int i = 0; i < n; i++){
        scanf("%d", &value[i]);
    }
    sort(value.begin(), value.end(), cmp);
    int coin = 0;
    for(int i = 0; i < n; i++){
        if(coin == k){
            break;
        }
        if(value[i] <= k){
            while(1){
                if(coin + value[i] > k){
                    break;
                }
                coin += value[i];
                cnt++;
            }
        }
    }

    printf("%d", cnt);

    return 0;

}