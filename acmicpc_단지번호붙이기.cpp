#include <stdio.h>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n;
vector<string> map_scan(25, "");
vector<vector<int> > map(25, vector<int>(25, 0));
vector<vector<bool> > visit(25, vector<bool>(25, false));
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool cmp(int a, int b){
    return a < b;
}

int bfs(int a, int b){
    queue<pair<int,int> > q;
    q.push(make_pair(a, b));
    visit[a][b] = true;
    int num = 1;

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= n){
                continue;
            }
            if(map[nx][ny] == 1 && !visit[nx][ny]){
                visit[nx][ny] = true;
                num++;
                q.push(make_pair(nx, ny));
            }
        }
    }

    return num;
}

int main(){
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        cin >> map_scan[i];
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            map[i][j] = (int)map_scan[i][j] - 48;
        }
    }
    int apart = 0;
    vector<int> num;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(visit[i][j] || map[i][j] == 0){
                continue;
            }
            else if(map[i][j] == 1 && !visit[i][j]){
                num.push_back(bfs(i, j));
                apart++;
            }
        }
    }
    sort(num.begin(), num.end(), cmp);

    printf("%d\n", apart);
    for(int i = 0; i < num.size(); i++){
        printf("%d\n", num[i]);
    }

    return 0;

}