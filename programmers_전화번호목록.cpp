#include <string>
#include <vector>

using namespace std;

// 길이가 비교 대상보다 짧은 것이랑만 비교하면 됨
bool solution(vector<string> phone_book) {
    bool answer = true;
    int size = phone_book.size();
    
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            if(i == j){
                continue;
            }
            if(phone_book[i].length() > phone_book[j].length()){
                continue;
            }
            else{
                int cnt = 0;
                for(int k = 0; k < phone_book[i].length(); k++){
                    if(phone_book[i][k] != phone_book[j][k]){
                        break;
                    }
                    else{
                        cnt++;
                    }
                }
                if(cnt == phone_book[i].length()){
                    return false;
                }
            }
        }
    }
    
    return true;
}