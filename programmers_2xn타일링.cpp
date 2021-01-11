#include <string>
#include <vector>

using namespace std;

int arr[600001] = {0, };
// n별로 타일의 갯수를 정리했을 때, 피보나치 수열


int solution(int n) {
    int answer = 0;
    
    arr[1] = 1;
    arr[2] = 2;
    
    for(int i = 3; i <= n; i++){
        arr[i] = (arr[i-1] + arr[i-2]) % 1000000007;
    }
    
    
    return arr[n] % 1000000007;
}