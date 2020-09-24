#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1; // 곱셈때문에 초기 값 1 넣기
    map<string, int> m;
    
    for(auto cloth : clothes){
        m[cloth[1]] += 1; // 옷을 종류별로 카운트
    }
    
    for(auto i = m.begin(); i != m.end(); i++){
        answer *= i->second + 1; // 종류별에서 선택하지 않는 경우 1가지를 추가
    }
        
    return answer - 1;
}