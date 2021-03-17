#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;

int n, m;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int answer = 0;
vector<pair<int, int> > virus;

int max(int a, int b){
    if(a >= b){
        return a;
    }
    else{
        return b;
    }
}

void bfs(vector<vector<int> > map){
    queue<pair<int, int> > q;

    for(int i = 0; i < virus.size(); i++){
        q.push(make_pair(virus[i].first, virus[i].second));
    }

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || nx >= n || ny < 0 || ny >= m){
                continue;
            }
            
            if(map[x][y] == 2 && map[nx][ny] == 0){
                map[nx][ny] = 2;
                q.push(make_pair(nx, ny));
            }
            

        }
    }
    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(map[i][j] == 0){
                cnt++;
            }
        }
    }

    answer = max(answer, cnt);

    return;
}

void dfs(vector<vector<int> > map, int x, int y, int cnt){
    map[x][y] = 1;
    if(cnt == 0){
        bfs(map);
        return;
    }
    for(int i = x; i < n; i++){
        for(int j = 0; j < m; j++){
            if(map[i][j] == 0){
                dfs(map, i, j, cnt-1);
            }
            
        }
    }
    return;
}

int main() {
    
    scanf("%d %d", &n, &m);
    vector<vector<int> > map(n, vector<int>(m, 0));
    

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%d", &map[i][j]);
            if(map[i][j] == 2){
                virus.push_back(make_pair(i, j));
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(map[i][j] == 0){
                dfs(map, i, j, 2);
            }
        }
    }
    
    printf("%d", answer);

    return 0;

}