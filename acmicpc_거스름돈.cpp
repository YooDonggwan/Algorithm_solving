#include <stdio.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);

    int to_pay = 1000 - n;
    int answer = 0;
    while(to_pay > 0){
        if(to_pay >= 500){
            to_pay -= 500;
            answer++;
        }
        else if(to_pay >= 100){
            to_pay -= 100;
            answer++;
        }
        else if(to_pay >= 50){
            to_pay -= 50;
            answer++;
        }
        else if(to_pay >= 10){
            to_pay -= 10;
            answer++;
        }
        else if(to_pay >= 5){
            to_pay -= 5;
            answer++;
        }
        else{
            to_pay -= 1;
            answer++;
        }
    }

    printf("%d", answer);

    return 0;

}