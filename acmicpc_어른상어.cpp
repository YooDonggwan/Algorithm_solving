#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>

#define MAX 21

using namespace std;

//상하좌우
int dx[] = {0, -1, 1, 0, 0};
int dy[] = {0, 0, 0, -1, 1};

int N, M, k;
struct Map{
    int shark_num;
    int k;
};
Map map[MAX][MAX];

struct Shark{
    int x;
    int y;
    int num;
    bool live;
    int k;
    int dir;
    int prior_dir[5][5];
};
Shark shark[401];

void spreadState(Shark shark) {
    int x = shark.x;
    int y = shark.y;
    map[x][y].k = shark.k;
    map[x][y].shark_num = shark.num;
}

void updateState(Shark shark[]) {

    //상어이동
    for(int i = 1; i <= M; i++){
        if(shark[i].live == false){
            continue;
        }
        int x = shark[i].x;
        int y = shark[i].y;
        int check = 0;
        vector<pair<pair<int, int>, int> > pos;
        for(int j = 1; j < 5; j++){
            int nx = x + dx[j];
            int ny = y + dy[j]; 
            if(nx >= 0 && nx < N && ny >= 0 && ny < N){  
                if(map[nx][ny].k == 0 && map[nx][ny].shark_num == 0){ // 냄새가 없는 인접한 칸있으면
                    check++;
                    pos.push_back(make_pair(make_pair(nx, ny), j));
                }
            }
        }
        if(check == 1){ // 냄새없는 인접 칸 한
            // 좌표와 방향 바꾸기
            int nx = pos[0].first.first;
            int ny = pos[0].first.second;
            int dir = pos[0].second;
            shark[i].x = nx;
            shark[i].y = ny;
            shark[i].dir = dir;
            pos.clear();
        } else if(check > 1){ // 냄새없는 인접칸 여러개일 경우
            // 우선순위 맞춰서 넣기
            bool flag = false;
            for(int j = 1; j < 5; j++){
                for(int k = 0; k < pos.size(); k++){
                    if(shark[i].prior_dir[shark[i].dir][j] == pos[k].second){
                        int nx = pos[k].first.first;
                        int ny = pos[k].first.second;
                        shark[i].x = nx;
                        shark[i].y = ny;
                        shark[i].dir = pos[k].second;
                        flag = true;
                        pos.clear();
                        break;
                    }
                    else{
                        continue;
                    }
                }
                if(flag == true) break;
            }
        } else{ // 냄새 없는 인접 칸 없을 경우
            // 자신의 냄새가 있는 곳으로 이동
            vector<pair<pair<int, int>, int> > posi;
            int check2 = 0;
            for(int j = 1; j < 5; j++){
                int nx = x + dx[j];
                int ny = y + dy[j]; 
                if(nx >= 0 && nx < N && ny >= 0 && ny < N){
                    if(map[nx][ny].k != 0 && map[nx][ny].shark_num == shark[i].num){
                        check2++;
                        posi.push_back(make_pair(make_pair(nx, ny), j));
                    }
                }
            }
            if(check2 == 1){
                // 좌표와 방향 바꾸기
                int nx = posi[0].first.first;
                int ny = posi[0].first.second;
                int dir = posi[0].second;
                shark[i].x = nx;
                shark[i].y = ny;
                shark[i].dir = dir;
                posi.clear();
            } else if(check2 > 1){ // 자신의 냄새 인접 칸 여러개일 경우
                // 우선순위 맞춰서 넣기
                bool flag = false;
                for(int j = 1; j < 5; j++){
                    for(int k = 0; k < posi.size(); k++){
                        if(shark[i].prior_dir[shark[i].dir][j] == posi[k].second){
                            int nx = posi[k].first.first;
                            int ny = posi[k].first.second;
                            shark[i].x = nx;
                            shark[i].y = ny;
                            shark[i].dir = posi[k].second;
                            flag = true;
                            posi.clear();
                            break;
                        }
                        else{
                            continue;
                        }
                    }
                    if(flag == true) break;
                }
            } else{
                continue;
            }
        }
    }
}

int main() {
    scanf("%d %d %d", &N, &M, &k);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            int a;
            scanf("%d", &a);
            if(a != 0){
                shark[a].x = i;
                shark[a].y = j;
                shark[a].num = a;
                shark[a].k = k;
                shark[a].live = true;
                map[i][j].k = k;
                map[i][j].shark_num = a;
            }
            else{
                map[i][j].k = 0;
                map[i][j].shark_num = 0;
            }
        }
    }

    for(int i = 1; i <= M; i++){
        int a;
        scanf("%d", &a);
        shark[i].dir = a;
    }

    for(int i = 1; i <= M; i++){
        for(int j = 1; j < 5; j++){
            for(int h = 1; h < 5; h++){
                int b;
                scanf("%d", &b);
                shark[i].prior_dir[j][h] = b;
            }
        }
    }
    
    int cnt = 0;
    bool time_over = false;
    while(1){
        // 종료조건은 격자 전체에 1번상어만 있을 경우
        int live_shark = 0;
        for(int i = 1; i <= M; i++){
            if(shark[i].live == true){
                live_shark++;
            }
        }
        if(live_shark == 1){
            break;
        }
        
        if(cnt >= 1000 && live_shark > 1){
            time_over = true;
            break;
        }

        

        updateState(shark);

        // 냄새 없애기
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(map[i][j].k > 0){
                    map[i][j].k--;
                    if(map[i][j].k == 0){
                        map[i][j].shark_num = 0;
                    }
                }
            }
        }
        
        // 한 공간에 shark가 여러마리 있으면 번호 제일 낮은 것만 살리기
        for(int i = 1; i <= M; i++){
            if(shark[i].live == false) continue;
            for(int j = i; j <= M; j++){
                if(i == j) continue;
                if(shark[j].live == false) continue;
                if(shark[i].x == shark[j].x && shark[i].y == shark[j].y){
                    shark[j].live = false;                
                }
            }
        }

        // 냄새 남기기
        for(int i = 1; i <= M; i++){
            if(shark[i].live == false){
                continue;
            }
            spreadState(shark[i]);
        }
        
        cnt++;
    }

    if(time_over == true){
        printf("-1");
    }
    else{
        printf("%d", cnt);
    }
    
}