#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 21

// 선거구 나누는 방법 중, 인구 가장 많은 - 가장 적은의 최솟값
// 선거구를 나누는 모든 방법을 찾은 후 최대 최소의 차를 구하고 다른 방법들과 비교해서 최솟값 찾아야 함

int N;
int map[MAX][MAX];
int min_ans = 999999;
int ans;

int select_five(int x, int y, int d1, int d2){
    vector<int> people(5, 0) ;

    for(int r = 1; r <= N; r++){
        for(int c = 1; c <= N; c++){
            //1
            if (r < x + d1 && c <= y && !(r >= x && c >= y - (r - x))) {
				people[0] += map[r][c];
			}
			//2
			else if (r <= x + d2 && c > y && !(r >= x && c <= y + (r - x))) {
				people[1] += map[r][c];
			}
			//3
			else if (r >= x + d1 && c < y - d1 + d2 && !(r <= x + d1 + d2 && c >= (y - d1 + d2 - (x + d1 + d2 - r)))) {
				people[2] += map[r][c];
			}
			//4
			else if (r > x + d2 && c >= y - d1 + d2 && !(r <= x + d1 + d2 && c <= (y - d1 + d2 + (x + d1 + d2 - r)))) {
				people[3] += map[r][c];
			}
			//
			else {
				people[4] += map[r][c];
			}
        }
    }

    sort(people.begin(), people.end());
    int cal = people[4] - people[0];

    return cal;
}

int divide_area() {
    int x, y, d1, d2;

    // d1, d2를 1부터 늘려가면서 결정
    for(x = 1; x <= N-2; x++){
        for(y = 2; y <= N-1; y++){
            for(d1 = 1; d1 <= y-1 && d1 <= N-x-1; d1++){
                for(d2 = 1; d2 <= N-y && d2 <= N-x-1; d2++){
                    min_ans = min(min_ans, select_five(x, y, d1, d2));
                }
            }
        }
    }

    return min_ans;
}

int main() {

    scanf("%d", &N);
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            scanf("%d", &map[i][j]);
        }
    }

    ans = divide_area();
    printf("%d", ans);

    return 0;
}