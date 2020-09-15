#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int solution(vector<int> people, int limit) {
    int answer = 0;
    
    sort(people.begin(), people.end()); 
    
    int l = 0;
    int r = people.size()-1;
    
    while(l < r){
        int sum = people[l] + people[r];
        if(limit < sum){
            r--;
        }
        else{
            l++;
            r--;
        }
        answer++; // 포인터가 바뀌면 짝이 될 수 없거나 짝이 되어서 배가 출발한 것
    }
    if(l == r){
        answer++; // 엇갈리지 않고 같은 경우는 한 명만 남은 경우
    }
    
    
    return answer;
}