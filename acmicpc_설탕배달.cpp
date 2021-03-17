#include <iostream>
#include <stdio.h>

using namespace std;


int main(){
    int N;

    scanf("%d", &N);

    int answer = 0;
    
    if(N == 4 || N == 7){
        printf("-1");
        return 0;
    }

    int num = N / 5;

    switch(N % 5){
        case 0:
            printf("%d", num);
            break;
        case 1:
            printf("%d", num+1);
            break;
        case 2:
            printf("%d", num+2);
            break;
        case 3:
            printf("%d", num+1);
            break;
        case 4:
            printf("%d", num+2);
            break;
        default:
            break;
    }

    return 0;

}