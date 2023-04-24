//
// Created by roboter on 23-4-25.
//

// graph: DFS(Backtracking)
// NO.17. Letter Combinations of a Phone Number

#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> ans;
    string temp;
    map<char , string> m;
    void helper(map<char , string> &m, int level, int size, string digits){
        if (level == size){
            ans.push_back(temp);
            return;
        }
        char dig = digits[level];
        for (int i = 0; i < m[dig].size(); ++i) {
            temp.push_back(m[dig][i]);
            helper(m, level+1, size, digits);
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()){return ans;}
        m['2'] = "abc";
        m['3'] = "def";
        m['4'] = "ghi";
        m['5'] = "jkl";
        m['6'] = "mno";
        m['7'] = "pqrs";
        m['8'] = "tuv";
        m['9'] = "wxyz";
        int len = digits.size();
        helper(m, 0, len, digits);
        return ans;
    }
};




int main(){
    return 0;
}
