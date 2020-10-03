#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>
#include <math.h>

using namespace std;

#define MAX 50

int N, M;
int map[MAX][MAX];
int Time[MAX][MAX];
int empty_place = 0;

vector<pair<int, int> > virus;
bool Select[10];

// 상하좌우
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int time_cnt = 0;
bool spread_all = true;
int answer = 9999999;

// 활성화 된 칸 주변 칸들에 먼저 바이러스를 퍼뜨리고
// 그 다음 활성화된 칸들에 연결된 것들을 또 퍼뜨려야하기 때문에 BFS
// 상하좌우에 -1이 있으면 내 자신의 숫자에서 1 더하기 모든칸에 -1이 없으면 다 퍼진거
// 시작위치 (a, b)
void BFS(queue<pair<int, int> > loca){
    int infect = 0;
    int total_time = 0;

    while(!loca.empty()){
        int x = loca.front().first;
        int y = loca.front().second;
        loca.pop();
        
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 && nx < N && ny >= 0 && ny < N){
                if(map[nx][ny] != 1 && Time[nx][ny] == -1){ // 벽이 아니고 바이러스가 안퍼졌으면
                    Time[nx][ny] = Time[x][y] + 1;
                    if(map[nx][ny] == 0){
                        infect++;
                        total_time = Time[nx][ny];
                    }
                    loca.push(make_pair(nx ,ny)); //상하좌우를 큐에 넣음
                }
            }
        }

    }

    if(infect == empty_place){
        if(answer > total_time){
            answer = total_time;
        }
    }

}

// m개를 고르는 것 구현하고 바이러스 퍼뜨리는건 bfs로
void select_virus(int idx, int cnt){
    if(cnt == M){ // M개가 선택되었으면
        queue<pair<int, int> > q;
        memset(Time, -1, sizeof(Time)); // Time 배열 전부 -1로 초기화
        for(int i = 0; i < virus.size(); i++){
            if(Select[i] == true){
                q.push(make_pair(virus[i].first, virus[i].second));
                Time[virus[i].first][virus[i].second] = 0; // 바이러스 표시
            }
        }

        BFS(q);
        return;
    }
    for(int i = idx; i < virus.size(); i++){
        if(Select[i] == true){
            continue;
        }
        Select[i] = true;
        select_virus(i+1, cnt+1);
        Select[i] = false;
    }
}

int main() {
    scanf("%d %d", &N, &M);
    int num = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            scanf("%d", &map[i][j]);
            if(map[i][j] == 2){ // 바이러스일 경우
                virus.push_back(make_pair(i, j));
                Time[i][j] = 0;
                num++;
            }
            else if(map[i][j] == 0){ // 빈 공간일 경우
                empty_place++;
            }
        }
    }
    select_virus(0, 0);

    if(answer == 9999999){
        printf("-1");
    }
    else{
        printf("%d", answer);
    }
    
}