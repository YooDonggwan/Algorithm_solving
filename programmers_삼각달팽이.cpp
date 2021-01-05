#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    int arr[1000][1000] = {0,};
    
    int x = 0, y = 0;
    int state = 0; // 0 down 1 right 2 up
    int num = 1;
    
    for(int i = 0; i < n; i++){
        switch(state){
            case 0:
                for(int j = i; j < n; j++){
                    arr[x++][y] = num++;
                }
                state = 1;
                x--;
                y++;
                break;
                
            case 1:
                for(int j = i; j < n; j++){
                    arr[x][y++] = num++;
                }
                state = 2;
                x--;
                y -= 2;
                break;
                
            case 2:
                for(int j = i; j < n; j++){
                    arr[x--][y--] = num++;
                }
                state = 0;
                x += 2;
                y++;
                
            default:
                break;
        }
    }
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++){
            answer.push_back(arr[i][j]);
        }
    }
    
    
    return answer;
}