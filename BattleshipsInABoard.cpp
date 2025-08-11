// Given an m x n matrix board where each cell is a battleship 'X' or empty '.', 
// return the number of the battleships on board.
// Battleships can only be placed horizontally or vertically on board. In other words, 
// they can only be made of the shape 1 x k (1 row, k columns) or k x 1 (k rows, 1 column), 
// where k can be of any size. At least one horizontal or vertical cell separates between two battleships (i.e., there are no adjacent battleships).

// Example 1:
// Input: board = [["X",".",".","X"],[".",".",".","X"],[".",".",".","X"]]
// Output: 2

// Example 2:
// Input: board = [["."]]
// Output: 0
#include<bits/stdc++.h>
using namespace std;

bool isPoss(int i,int j,int n,int m,vector<vector<char>>& board,vector<vector<int>>&visited){
    if(i >= 0 && i < n && j >= 0 && j < m && board[i][j] == 'X' && visited[i][j] == 0) return true;
    return false;
}

void dfs(int i,int j,int n,int m,vector<vector<char>>& board,vector<vector<int>>&visited){
    visited[i][j] = 1;

    //north
    int x = i - 1;
    int y = j;
    if(isPoss(x,y,n,m,board,visited)){
        dfs(x,y,n,m,board,visited);
    }

    //south
    x = i + 1;
    y = j;
    if(isPoss(x,y,n,m,board,visited)){
        dfs(x,y,n,m,board,visited);
    }

    //east
    x = i;
    y = j + 1;
    if(isPoss(x,y,n,m,board,visited)){
        dfs(x,y,n,m,board,visited);
    }
    //west
    x = i;
    y = j - 1;
    if(isPoss(x,y,n,m,board,visited)){
        dfs(x,y,n,m,board,visited);
    }
    return ;
}
int countBattleships(vector<vector<char>>& board) {
    int n = board.size();
    int m = board[0].size();
    vector<vector<int>>visited(n,vector<int>(m,0));
    int count = 0;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            if(board[i][j] == 'X' && !visited[i][j]){
                dfs(i,j,n,m,board,visited);
                count++;
            }
        }
    }
    return count;
}
int main(){
    vector<vector<char>>board = {
        {'X','.','.','X'},
        {'.','.','.','X'},
        {'.','.','.','X'}
    };

    int ans = countBattleships(board);
    cout<<ans;
    return 0;
}