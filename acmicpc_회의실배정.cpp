#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b){
    if(a.second == b.second){
        return a.first < b.first;
    }
    else{
        return a.second < b.second;
    }
    
}

int main() {
    int n;

    scanf("%d", &n);

    vector<pair<int, int> > time(n, make_pair(0, 0));

    for(int i = 0; i < n; i++){
        scanf("%d %d", &time[i].first, &time[i].second);
    }

    sort(time.begin(), time.end(), cmp);

    int answer = 0;
    int end_time = 0;
    for(int i = 0; i < time.size(); i++){
        if(time[i].first >= end_time){
            answer++;
            end_time = time[i].second;
        }
       
    }
    

    

    printf("%d", answer);

    return 0;

}