#include <string>
#include <vector>

using namespace std;

// 올바른 문자열인지 체크
bool isCheck(string str){
    int sum = 0;
    bool right = true;
    
    for(int i = 0; i < str.length(); i++){
        if(str[i] == '('){
            sum += 1;
        }
        else{
            sum -= 1;
        }
        if(sum < 0){ // sum이 0보다 작아지는 순간 올바른은 아님
            right = false;
        }
    }
    
    return right;
}

// 문자열 분리
string divideString(string str){
    if(str == ""){
        return str;
    }
    string u = "";
    string v = "";
    int sum = 0;
    for(int i = 0; i < str.length(); i++){
        if(str[i] == '('){
            sum += 1;
        }
        else{
            sum -= 1;
        }
        
        if(sum == 0){
            u = str.substr(0, i+1);
            v = str.substr(i+1);
            break;
        }
    }

    if(isCheck(u)){ // 올바른 문자열이라면
        return u + divideString(v);
    }
    else{
        string tmp = "";
        tmp += '('; // 4-1
        string recur_v = divideString(v);
        tmp += recur_v; // 4-2
        tmp += ')'; // 4-3
        // 4-4
        u = u.substr(1, u.length()-2);
        for(int i = 0; i < u.length(); i++){
            if(u[i] == '('){
                tmp += ')';
            }
            else{
                tmp += '(';
            }
        }
        return tmp;
    }
    
}

string solution(string p) {
    string answer = "";

    if(isCheck(p)) return p;
    
    answer = divideString(p);
    
    return answer;
}