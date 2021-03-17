#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

int m, n;
vector<vector<int> > map(1001, vector<int>(1000, 0));
vector<vector<bool> > visit(1001, vector<bool>(1000, false));
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int cnt;

void bfs(vector<pair<int, int> > ripet){
    queue<pair<pair<int, int>, int> > q;

    for(int i = 0; i < ripet.size(); i++){
        q.push(make_pair(make_pair(ripet[i].first, ripet[i].second), 0));
        visit[ripet[i].first][ripet[i].second] = true;
    }

    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        
        cnt = q.front().second;
        q.pop();
        
        
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(map[nx][ny] == 0 && !visit[nx][ny]){
                q.push(make_pair(make_pair(nx, ny), cnt+1));
                visit[nx][ny] = true;          
                map[nx][ny] = 1;      
            }
        }
    }

    return;
}

int main() {

    scanf("%d %d", &m, &n);

    int zero = 0;
    vector<pair<int, int> > ripet;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%d", &map[i][j]);
            if(map[i][j] == 1){
                ripet.push_back(make_pair(i, j));
            }
            else if(map[i][j] == 0){
                zero++;
            }

        }
    }


    if(zero == 0){ // 모두 익어있는 상태
        printf("0");
        return 0;
    }


    bfs(ripet);
    
    // 모두 익지 못하는 상태
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(map[i][j] == 0){
                cnt = -1;
                break;
            }
        }
    }

    

    printf("%d", cnt);

    return 0;

}