//
// Created by 29180 on 2023/4/25.
//
#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <limits>
#include <string>

//397. Integer Replacement
// DFS, backtracking algo

using namespace std;

class Solution {
public:
    int Min = INT_MAX;
    void helper(int level, long n){
        if (n < 1){ return;}
        if (n == 1){
            Min = min(Min, level);
            return;
        }
        if (n%2 == 0){ helper(level+1, n/2);}
        else {
            helper(level+1, n+1);
            helper(level+1, n-1);
        }
    }
    int integerReplacement(int n) {
        helper(0, (long)n);
        return Min;
    }
};

