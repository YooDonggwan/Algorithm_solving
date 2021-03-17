#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector<int> rope(100000, 0);

bool cmp(int a, int b){
    return a < b;
}

int main() {
    scanf("%d", &n);
    
    for(int i = 0; i < n; i++){
        scanf("%d", &rope[i]);     
    }

    sort(rope.begin(), rope.begin() + n, cmp);

    
    long long ans = 0;
    int idx = 1;
    for(int i = n-1; i >= 0; i--){
        if(ans <= rope[i] * idx){
            ans = rope[i] * idx;
            
        }
        idx++;
    }

    // for(int i = 0; i < n; i++){
    //     if(ans < (n-i) * rope[i] ){
    //         ans = (n-i) * rope[i];
    //     }
    // }

    

    printf("%lld", ans);

    return 0;


}

