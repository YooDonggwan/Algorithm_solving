#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

string str;

int main() {
    cin >> str;
    string num = "";
    bool minus = false;
    int ans = 0;
    for(int i = 0; i <= str.length(); i++){
        if(str[i] == '+' || str[i] == '-' || str[i] == '\0'){

            if(minus){
                ans -= stoi(num);
            }
            else{
                ans += stoi(num);
            }
            num = "";
            if(str[i] == '-'){
                minus = true;
            }
            continue;
        }
        num += str[i];
    }

    printf("%d", ans);

    return 0;

}