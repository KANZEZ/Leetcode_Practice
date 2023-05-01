//
// Created by 29180 on 2023/5/1.
//
#include <iostream>
#include <vector>
#include <map>
// 216. Combination Sum III
using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    void backTracking(int size, int curlevel, map<int,int> &visit, vector<int> temp, vector<int>& nums){
        if(curlevel == size){
            ans.push_back(temp);
            return;
        }
        for(int i = 0; i < size; i++){
            if(visit[nums[i]] == 0){
                temp.push_back(nums[i]);
                visit[nums[i]] = 1;
                backTracking(size, curlevel+1, visit, temp, nums);
                visit[nums[i]] = 0;
                temp.pop_back();
            }
        }
    }


    vector<vector<int>> permute(vector<int>& nums) {
        int s = nums.size();
        map<int,int> visit;
        vector<int> temp;
        for(int i = 0; i < s; i++){
            visit[nums[i]] = 0;
        }
        backTracking(s, 0, visit, temp, nums);
        return ans;
    }
};
