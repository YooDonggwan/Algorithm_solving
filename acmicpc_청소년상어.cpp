#include <iostream>
#include <stdio.h>
#include <algorithm>

#define MAX 4

using namespace std;

struct Fish{
    int x;
    int y;
    int dir;
    bool live;
};

int answer;
int map[MAX][MAX];
Fish fish[17];
// 위쪽부터 반시계 8방
int dx[] = {0, -1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, 0, -1, -1, -1, 0, 1, 1, 1};

int max(int a, int b){
    if(a > b){
        return a;
    }
    return b;
}

void copyState(int A[][4], int B[][4], Fish C[], Fish D[])
{
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            A[i][j] = B[i][j];
        }
    }
    for (int i = 1; i <= 16; i++){
        C[i] = D[i];
    } 
}

void swapFish(int first, int second){
    Fish tmp = fish[first];
    fish[first].x = fish[second].x;
    fish[first].y = fish[second].y;
    fish[second].x = tmp.x;
    fish[second].y = tmp.y;
}

void moveFish(){
    for(int i = 1; i <= 16; i++){
        if(fish[i].live == false){
            // 죽어있으면 넘기기
            continue;
        }
        int x = fish[i].x;
        int y = fish[i].y;
        int dir = fish[i].dir;

        int nx = x + dx[dir]; // 움직일 방향좌표 만들기
        int ny = y + dy[dir];
        bool flag = false; // 자리를 바꾸면 true로 바꾸기

        // 움직여주기
        if(nx >= 0 && ny >=0 && nx < 4 && ny < 4){
            if(map[nx][ny] == 0){ // 빈칸이면
                flag = true;
                fish[i].x = nx;
                fish[i].y = ny;
                map[nx][ny] = i;
                map[x][y] = 0;
            }
            else if(map[nx][ny] != -1){ // 상어가 없으면
                flag = true;
                swapFish(i, map[nx][ny]);
                swap(map[x][y], map[nx][ny]);
            }
        }

        //flag가 false이면 물고기가 원하는방향으로 갈 수 없는, 상어가 있는 곳일 경우
        if(flag == false){
            int ndir = dir + 1; // 다음방향으로 바꿔주기
            if(ndir == 9){
                // 마지막 방향일 경우
                ndir = 1;
            }
            int nx = x + dx[ndir];
            int ny = y + dy[ndir];

            while(ndir != dir){
                // 원래의 방향과 다르면 계속 진행
                if(nx >= 0 && ny >=0 && nx < 4 && ny < 4){
                    if(map[nx][ny] == 0){ // 빈칸이면
                        fish[i].x = nx;
                        fish[i].y = ny;
                        map[nx][ny] = i;
                        map[x][y] = 0;
                        fish[i].dir = ndir; // 새로운 방향 주기
                        break;
                    }
                    else if(map[nx][ny] != -1){ // 상어가 없으면
                        swapFish(i, map[nx][ny]);
                        swap(map[x][y], map[nx][ny]);
                        fish[i].dir = ndir;
                        break;
                    }
                }
                // 갈 수 없을 경우 방향 바꿔서 다시 진행해야함
                ndir++;
                if(ndir == 9){
                    ndir = 1;
                }
                nx = x + dx[ndir];
                ny = y + dy[ndir];
            }
        }
    }
}

void makeState(int x, int y, int nx, int ny, int fish_idx, bool T){
    if(T == true){
        // 상어가 먹었을 경우엔 상태 바꿔주기
        map[x][y] = 0;
        map[nx][ny] = -1;
        fish[fish_idx].live = false;
    }
    else{
        // 상어가 먹지 않았을 경우엔 상태 다시 돌리기
        map[x][y] = -1;
        map[nx][ny] = fish_idx;
        fish[fish_idx].live = true;
    }
}

void dfs(int x, int y, int dir, int sum) {
    answer = max(answer, sum); // 더 많은 고기 먹을 경우 answer로 
    int c_map[4][4];
    Fish c_fish[17];
    copyState(c_map, map, c_fish, fish); // c_map, c_fish에 현 상태 저장
    // 물고기 움직이기
    moveFish();

    for(int i = 1; i <= 3; i++){
        int nx = x + dx[dir] * i; // 내 위치에서 최대 3배만큼 갈 수 있음
        int ny = y + dy[dir] * i;
        if (nx >= 0 && ny >= 0 && nx < 4 && ny < 4)
        {
            if (map[nx][ny] == 0) continue;
            
            int fish_num = map[nx][ny];
            int ndir = fish[fish_num].dir;
 
            makeState(x, y, nx, ny, fish_num, true);
            dfs(nx, ny, ndir, sum + fish_num);
            makeState(x, y, nx, ny, fish_num, false);
        }
        else {
            break;
        }
    }
    copyState(map, c_map, fish, c_fish); // 최종적으로 원래의 상태로 돌리기
}


int main() {
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            int a,b;
            scanf("%d %d", &a, &b);
            map[i][j] = a;
            fish[a].x = i;
            fish[a].y = j;
            fish[a].dir = b;
            fish[a].live = true;
        }
    }   

    // 맨처음 상어의 상태
    int f_num = map[0][0];
    int dir = fish[f_num].dir;
    fish[f_num].live = false;
    map[0][0] = -1; // 상어는 -1로

    dfs(0, 0, dir, f_num);

    printf("%d", answer);
}