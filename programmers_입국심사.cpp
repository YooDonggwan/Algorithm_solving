#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    
    sort(times.begin(), times.end()); //오름차순 정렬
    
    long long start = 1;
    long long end = (long long) n * times.back(); // 최대로 걸리는 시간을 마지막으로 설정
    long long middle = 0;
    
    while(start <= end){
        long long sum = 0;
        middle = (start + end) / 2;
        for(int i = 0; i < times.size(); i++){
            sum += middle / times[i];
        }
        
        if(sum < n){
            start = middle+1;
        }
        else { // 최소로 걸린 시간을 답으로 뽑아야하므로 처음 시간이 잡혔을 때 end를 줄이면서 진행해야 함
            end = middle-1;
            answer = middle;
        }
    }
    
    return answer;
}