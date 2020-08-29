#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int a, int b){
    return a > b;
}

int solution(vector<int> citations) {
    int answer = 0;
    int n = citations.size();
    
    sort(citations.begin(), citations.end(), compare);
    
    //6 5 3 1 0
    for(int i = 0; i < n; i++){
        if(citations[i] > i){
            answer++;
        }
        else{
            break;
        }
    }
    
    return answer;
}