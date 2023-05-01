/***
 * Created by 29180 on 2023/5/1.
 */

#include <iostream>
#include <vector>
#include <algorithm>
// 40. Combination Sum II
// backtracing strategies: 
// 1.avoid duplicate answer(candidates don't have duplicate ones and answers can't have duplicate candidates): start choosing candidates from next index
// 2.avoid duplicate answer(candidates don't have duplicate ones and answers can have duplicate candidates): start choosing candidates from current index
// 3.avoid duplicate answer(candidates have duplicate ones and answers can have duplicate candidates): sort first, then base on 1, add this step: avoid the duplicate candidate when choosing one.
using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    void backTracking(int target, int start, vector<int>& candidates, int curSum, vector<int>& temp){
        if (curSum > target){return;}
        if (curSum == target){
            ans.push_back(temp);
            return;
        }

        for (int i = start; i < candidates.size(); ++i) {
            if(i >= candidates.size()) {break;}
            curSum += candidates[i];
            temp.push_back(candidates[i]);
            backTracking(target,i+1,candidates,curSum,temp);
            curSum -= candidates[i];
            temp.pop_back();
            while (i + 1 < candidates.size() && candidates[i] == candidates[i+1]) i++;
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> temp;
        sort(candidates.begin(),candidates.end());
        backTracking(target,0,candidates,0,temp);
        return ans;
    }
};

