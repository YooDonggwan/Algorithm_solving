#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, v;
bool map[1001][1001] = {false, };
bool visit[1001] = {false, };
vector<int> d_ans;
vector<int> b_ans;

// 방문가능 여러개면 작은 숫자 먼저
void dfs(int start){
    visit[start] = true;
    d_ans.push_back(start);
    vector<int> v;
    for(int i = 1; i <= n; i++){
        if(i == start){
            continue;
        }
        if(map[start][i] == true && visit[i] == false){
            dfs(i);
        }
    }
    
    return;
}

void bfs(int start){
    queue<int> q;
    q.push(start);
    visit[start] = true;

    while(!q.empty()){
        int now = q.front();
        b_ans.push_back(now);
        q.pop();

        vector<int> v;

        for(int i = 1; i <= n; i++){
            if(i == now){
                continue;
            }
            if(map[now][i] == true && visit[i] == false){
                v.push_back(i);
                
            }
        }
        if(!v.empty()){
            sort(v.begin(), v.end());
            for(int i = 0; i < v.size(); i++){
                q.push(v[i]);
                visit[v[i]] = true;
            }
        }
        
    }
    return;
}


int main() {
    scanf("%d %d %d", &n, &m, &v);

    for(int i = 0; i < m; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        
        map[a][b] = true;
        map[b][a] = true;   
    }
    
    dfs(v);
    

    for(int i = 1; i <= n; i++){
        visit[i] = false;
    }

    bfs(v);
    for(int i = 0; i < d_ans.size(); i++){
        printf("%d ", d_ans[i]);
    }
    
    printf("\n");
    for(int i = 0; i < b_ans.size(); i++){
        printf("%d ", b_ans[i]);
    }

    return 0;

}