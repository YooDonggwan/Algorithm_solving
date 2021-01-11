#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int arr[501][501];

// 왼쪽 끝  arr[i][j] = arr[i-1][j] + triangle[i][j]
// 오른쪽 끝 arr[i][j] = arr[i-1][j-1] + triangle[i][j]
// 나머지 arr[i][j] = max(arr[i-1][j], arr[i-1][j-1]) + triangle[i][j]

int solution(vector<vector<int>> triangle) {
    int answer = triangle[0][0];
    arr[0][0] = triangle[0][0];
    int sum = 0;
    
    for(int i = 1; i < triangle.size(); i++){
        for(int j = 0; j <= i; j++){
            if(j == 0){ // 왼
                arr[i][j] = arr[i-1][j] + triangle[i][j];
            }
            else if(j == i){ // 오
                arr[i][j] = arr[i-1][j-1] + triangle[i][j];
            }
            else{
                arr[i][j] = max(arr[i-1][j], arr[i-1][j-1]) + triangle[i][j];
            }
            answer = max(answer, arr[i][j]);
        }
    }
    
    
    
    return answer;
}