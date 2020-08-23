#include <iostream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

bool visit[10000000];
bool check[10];
int answer;

bool isPrime(int n){
    if(n<=1) {
        return false;
    }

    for(int i=2; i<=sqrt(n); i++) {
        if((n%i)==0) {
            return false;
        }
    }

    return true;
}

void dfs(string numbers, string checkNum, int cnt){
    if(checkNum != "" && visit[stoi(checkNum)] == false){
        int num = stoi(checkNum);
        visit[num] = true;
        if(isPrime(num)){
            answer++;
        }
    }
    
    for(int i = 0; i < numbers.length(); i++){
        if(check[i])
            continue;
        check[i] = true;
        dfs(numbers, checkNum + numbers[i], cnt+1);
        check[i] = false;
    }
}

int solution(string numbers) {    
    
    dfs(numbers, "", 0);
    
    return answer;
}