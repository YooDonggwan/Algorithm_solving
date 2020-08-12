#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 스트링으로 변환하여 합쳤을 때 더 큰 수 선택
bool compare(string a, string b){
    
    return a + b > b + a;
    
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> tmp;
    
    // 스트링으로 바꿔 저장
    for(int i = 0; i < numbers.size(); i++){
        tmp.push_back(to_string(numbers[i]));
    }
    
    sort(tmp.begin(), tmp.end(), compare);
    
    // 첫 번째 수가 0일경우 0을 반환
    if(tmp.at(0) == "0")
        return "0";
    
    // 순서대로 수 합치기
    for(auto i : tmp){
        answer += i;
    }
    
    return answer;
}