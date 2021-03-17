#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

int n, k;
int ans = 0;

void bfs(int a, int b){
    queue<pair<int, int> > q;
    vector<bool> visit(n, false);
    int cnt = 0;
    q.push(make_pair(a, 0));
    visit[a] = true;

    while(!q.empty()){
        int now = q.front().first;
        cnt = q.front().second;
        q.pop();
        
        if(now == b){
            ans = cnt;
            return;
        }

        if(now + 1 <= 100000 && !visit[now+1]){
            q.push(make_pair(now+1, cnt+1));
            visit[now+1] = true;
        }
        if(now - 1 >= 0 && !visit[now-1]){
            q.push(make_pair(now-1, cnt+1));
            visit[now-1] = true;
        }
        if(now * 2 <= 100000 && !visit[now*2]){
            q.push(make_pair(now*2, cnt+1));
            visit[now*2] = true;
        }

    }

    return;
}

int main(){

    scanf("%d %d", &n, &k);

    bfs(n, k);
    
    printf("%d", ans);

    return 0;
}