#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(int a, int b){
    return a > b;
}

int main(){
    int n, k;
    int cnt = 0;
    scanf("%d %d", &n, &k);
    vector<int> value(101, 0);
    
    for(int i = 0; i < n; i++){
        scanf("%d", &value[i]);
    }

    while(1){
        
    }

    printf("%d", cnt);

    return 0;

}