//
// Created by 29180 on 2023/4/25.
//
#include <iostream>

using namespace std;

class Solution {
public:
    int ans = 0;
    void helper(int permInx, int n, int size, bool v[]){
        if (n % permInx != 0 && permInx % n != 0){return;}
        if(permInx == size){
            ans++;
            cout << permInx <<" "<< n << endl;
            return;
        }
        for (int i = 1; i <= size; ++i) {
            if (!v[i-1]) {
                v[i-1] = true;
                helper(permInx + 1, i, size, v);
                v[i-1] = false;
            }
        }
    }
    int countArrangement(int n) {
        bool v[n];
        for (int i = 0; i < n; ++i) {
            v[i] = false;
        }
        helper(1, 1, n, v);
        return ans;
    }
};


int main(){
    Solution s;
    cout<<s.countArrangement(2);
    return 0;
}
