#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    
    for(int i = 0;  i < skill_trees.size(); i++){
        string skill_tmp = "";
        for(int j  = 0; j < skill_trees[i].size(); j++){
            for(int k = 0; k < skill.size(); k++){
                if(skill[k] == skill_trees[i][j]){
                    skill_tmp += skill_trees[i][j];
                }
            }
        }
        
        vector<int> cnt;
        for(int j = 0; j < skill_tmp.size(); j++){
            for(int k = 0; k < skill.size(); k++){
                if(skill_tmp[j] == skill[k]){
                    cnt.push_back(k);
                }
            }
        }
        
        int flag = 0;
        for(int j = 0; j < cnt.size(); j++){
            if(j != cnt[j]){
                flag = 1;
                break;
            }
        }
        
        if(flag == 0){
            answer++;
        }
     
    }
    
    return answer;
}