#include <string>
#include <vector>

using namespace std;

// 전체크기로 보고 yellow가 한 줄일 경우부터 시작 - 전체는 3줄
// 가로길이 >= 세로길이
vector<int> answer;

vector<int> solution(int brown, int yellow) {
    
    int total = brown + yellow;
    for(int vertical = 3; ; vertical++){ // yellow가 1줄일 경우부터 시작
        if(total % vertical == 0){
            int horizontal = (total / vertical); // 전체크기의 가로
            if((horizontal - 2) * (vertical-2) == yellow){ // 전체가로/세로에서 각 2씩 빼서 곱하면 yellow 나와야함
                answer.push_back(horizontal);
                answer.push_back(vertical);
                break;
            }
        }
    }
    
    return answer;
}