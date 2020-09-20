#include <iostream>
#include <stdio.h>
#include <queue>
#include <math.h>
#include <algorithm>

using namespace std;

#define MAX 20
#define MIN 999999

// 아기상어 구조체
struct BabyShark{
    int x;
    int y;
    int size;
    int eat_count;
};
int eat_dist;

int N;
int map[MAX][MAX];
int visit[MAX][MAX];
BabyShark baby;
int result;
//시계방향으로 상우하좌
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};


vector <pair<pair<int, int>, int> > eat; // 먹을 물고기 남았는지 체크할 벡터


// 아기상어가 움직인 후 상태 저장
void makeState(int x, int y, int nx, int ny){
    map[x][y] = 0;
    map[nx][ny] = 9;
    baby.x = nx;
    baby.y = ny;
    baby.eat_count++;
    if(baby.eat_count == baby.size){ // 자기 크기만큼의 마리 수를 먹었으면 사이즈가 1증가
        baby.size++;
        baby.eat_count = 0;
    }
    
}

// baby.x baby.y 를 인자로 받기
void bfs() {
    queue<pair<int, int> > q;
    int a = baby.x;
    int b = baby.y;
    eat_dist = MIN;
    eat.clear();
    memset(visit, 0, sizeof(visit));
    q.push(make_pair(a, b));
    // visit[a][b] = 1;

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            if(visit[nx][ny] == 0 && baby.size >= map[nx][ny]){
                visit[nx][ny] = visit[x][y] + 1;
                if (map[nx][ny] > 0 && map[nx][ny] < baby.size) {// 자기보다 작은 물고기 먹기
					if (eat_dist >= visit[nx][ny]) {
						eat_dist = visit[nx][ny];
						eat.push_back(make_pair(make_pair(eat_dist, nx), ny));
					}
				}
				q.push(make_pair(nx, ny));
            }
        }
    }
}

int main() {
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            scanf("%d", &map[i][j]);
            if(map[i][j] == 9){
                baby.x = i;
                baby.y = j;
                baby.size = 2;
                baby.eat_count = 0;
            }
        }
    }

    while(1){
        bfs();

        if(eat.empty()) break; // 먹을게 map에 없으면 
        else{ // 먹을게 남아있으면
            sort(eat.begin(), eat.end()); // pair일 땐 vector 의 first 기준으로 정렬됨
            result += eat[0].first.first; // 결과값에 거리 더해주기  
            int x_ = eat[0].first.second;
            int y_ = eat[0].second; 
            makeState(baby.x, baby.y, x_, y_);
        }
    }
    
    printf("%d", result);
}