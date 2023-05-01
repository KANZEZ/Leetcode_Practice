//
// Created by 29180 on 2023/4/28.
//
#include <iostream>
#include <vector>
// N-queens I
using namespace std;

class Solution {
public:
    int ans = 0;
    bool isValid(vector<vector<char>> &board, int n, int row, int col){
        // check col
        for (int i = 0; i < n; ++i) {
            if (board[i][col] == 'Q'){return false;}
            // check 2 diagonal directions
            if (row-i>=0 && col-i>=0){
                if (board[row-i][col-i] == 'Q'){ return false;}
            }
            if (row+i<n && col+i<n) {
                if (board[row + i][col + i] == 'Q') { return false; }
            }
            if (row-i>=0 && col+i<n){
                if (board[row-i][col+i] == 'Q'){ return false;}
            }
            if (row+i<n && col-i>=0) {
                if (board[row + i][col - i] == 'Q') { return false; }
            }
        }
        return true;
    }

    void backTracking(int row, int n, vector<vector<char>> &board){
        if (row == n){
            ans++;
            return;
        }

        for (int j = 0; j < n; ++j) {
            if (board[row][j] == '.' && isValid(board, n, row, j)){
                board[row][j] = 'Q';
                backTracking(row+1, n, board);
                board[row][j] = '.';
            }
        }
    }

    int totalNQueens(int n) {
        vector<vector<char>> board;
        for (int i = 0; i < n; ++i) {
            vector<char> temp;
            for (int j = 0; j < n; ++j) {
                temp.push_back('.');
            }
            board.push_back(temp);
        }

        backTracking(0, n, board);
        return ans;
    }
};


int main(){
    Solution s;
    cout << s.totalNQueens(7);
    return 0;
}
