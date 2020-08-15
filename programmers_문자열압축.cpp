#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = s.length();
    
    if(s.length() == 1)
        return 1;
    
    for(int i = 1; i <= s.length() / 2; i++){
        // 길이 / 2 까지인 이유는 반복되는 문자열이 절반보다 클 수 없으므로
        int cnt = 1;
        string sub = s.substr(0, i);
        string tmp, total;
        for(int j = i; j < s.length(); j += i){
            tmp = s.substr(j, i);
            
            if(sub == tmp){
                // 앞에서 자른 문자열과 비교하여 같으면 cnt 증가 
                cnt++;
            }
            else{
                // 다른경우
                if(cnt == 1){
                    //cnt가 1이면 반복이 없었으므로 그대로 문자열 더해주기
                    total += sub;
                    sub = tmp;
                }
                else{
                    //cnt가 1이 아닐경우 반복되는 문자열이 계속 나타났으므로 반복횟수 추가해주기
                    total = total + to_string(cnt) + sub;
                    sub = tmp;
                    cnt = 1;
                }
            }
            
            if(i + j >= s.length()){
                // s의 길이를 초과할 경우
                if(cnt != 1){
                    total = total + to_string(cnt) + sub;
                    break;
                }
                else{
                    total = total + s.substr(j);
                    break;
                }
            }
        }
        answer = (answer > total.length()) ? total.length() : answer; // 더 짧은 문자열을 찾아야하므로
    }
    
    
    return answer;
}