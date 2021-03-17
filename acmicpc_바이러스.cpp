#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

int n, m;


int bfs(vector<vector<bool> > map, vector<bool> visit, int a){
    queue<int> q;
    q.push(a);
    int virus = 0;

    while(!q.empty()){
        int now = q.front();
        q.pop();

        for(int i = 1; i <= n; i++){
            if(i == now || visit[i]){
                continue;
            }
            if(map[now][i] == true && !visit[i]){
                visit[i] = true;
                virus++;
                q.push(i);
            }
        }
        
    }

    return virus;
    
}

int main() {
    
    scanf("%d", &n);
    scanf("%d", &m);
    vector<vector<bool> > map(n+1, vector<bool>(n+1, false));
    vector<bool> visit(n+1, false);

    for(int i = 0; i < m; i++){
        int a, b;
        scanf("%d %d", &a, &b);

        map[a][b] = true;
        map[b][a] = true;
    }
    visit[1] = true;
    int answer = bfs(map, visit, 1);

    printf("%d", answer);

    return 0;

}