#include <iostream>
#include <stdio.h>

using namespace std;

#define MAX 20


// 아기상어와 물고기는 크기를 가짐
// 처음 아기상어 - 2, 1초에 상하좌우 한칸 이동
// 자기보다 큰 물고기있으면 못지나감, 자기보다 작은 물고기만 먹을 수 있음
// 크기 같은 물고기 먹을 수는 없지만 지나갈 수는 있음

// 아기상어 크기 늘리는 함수
// 아기상어가 움직이는 함수
// 아기상어가 물고기를 먹는 경우 함수
// 물고기를 먹고나서의 상태를 저장하는 함수

// 아기상어 구조체
struct BabyShark{
    int x;
    int y;
    int size = 2;
    int size_count;
};

int map[MAX][MAX];
int N;
BabyShark baby;
//시계방향으로 상우하좌
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

// 아기상어가 움직인 후 상태 저장
void makeState(int x, int y, int nx, int ny, bool T){
    if(T == true){
        //만약 움직여서 물고기를 먹었으면
        map[x][y] = 0;
        map[nx][ny] = 9;
        baby.x = nx;
        baby.y = ny;
        baby.size_count++;
        if(baby.size_count == baby.size){
            baby.size++;
            baby.size_count = 0;
        }
    }
    else{
        // 움직이기만 했을 경우
        map[x][y] = 0;
        map[nx][ny] = 9;
        baby.x = nx;
        baby.y = ny;
    }
}

// 아기상어가 움직이면서 먹는 함수
void moving(){

}

int main() {
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            scanf("%d", &map[i][j]);
        }
    }

}