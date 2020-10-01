#include <iostream>
#include <stdio.h>

using namespace std;

#define MAX 50
#define MIN 9999999;

int N, M;
int map[MAX][MAX];

// 상하좌우
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void dfs(int cnt){
    
}

int main() {
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            scanf("%d", &map[i][j]);
        }
    }

    dfs(0);
}