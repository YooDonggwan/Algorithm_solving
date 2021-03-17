#include <stdio.h>
#include <vector>
#include <queue>
#include <string>
#include <iostream>

using namespace std;

int n, m;
bool visit[101][101] = {false, };
int map[101][101] = {0, };
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void bfs(int a, int b){
    // queue<pair<int,int> > q;
    queue<pair<int, int> > q;
    q.push(make_pair(a, b));

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if(x == n && y == m){
            return;
        }

        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(map[nx][ny] == 1 && !visit[nx][ny]){
                q.push(make_pair(nx, ny));
                visit[nx][ny] = true;
                map[nx][ny] = map[x][y] + 1;
            }
        }
    }

    return;

}

int main() {
    
    scanf("%d %d", &n, &m);

    vector<string> str(n, "");

    for(int i = 0; i < n; i++){
        cin >> str[i];
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            map[i][j] = (int)str[i-1][j-1] - 48;
        }
    }
    
    bfs(1, 1);

    printf("%d", map[n][m]);

    return 0;

}