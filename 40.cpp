/***
 * Created by 29180 on 2023/5/1.
 */

#include <iostream>
#include <vector>
#include <algorithm>
// 40. Combination Sum II
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

