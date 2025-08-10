// According to Wikipedia's article: 
// "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."

// The board is made up of an m x n grid of cells, where each cell has an initial state: live 
// (represented by a 1) or dead (represented by a 0). Each cell interacts with its eight neighbors
// (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

// Any live cell with fewer than two live neighbors dies as if caused by under-population.
// Any live cell with two or three live neighbors lives on to the next generation.
// Any live cell with more than three live neighbors dies, as if by over-population.
// Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
// The next state of the board is determined by applying the above rules simultaneously to every cell in the current state of the m x n grid board. In this process, births and deaths occur simultaneously.

// Given the current state of the board, update the board to reflect its next state.

// Note that you do not need to return anything.

// Example 1:
// Input: board = [[0,1,0],[0,0,1],[1,1,1],[0,0,0]]
// Output: [[0,0,0],[1,0,1],[0,1,1],[0,1,0]]
// Example 2:
// Input: board = [[1,1],[1,0]]
// Output: [[1,1],[1,1]]
#include<bits/stdc++.h>
using namespace std;

bool isPoss(int i,int j,int n,int m){
    if(i >= 0 && i < n && j >= 0 && j < m ) return true;
    return false;
}
void solve(int i,int j,int n,int m,vector<vector<int>>&grid, int& countzero,int& countone){
    //north
    int x = i - 1;
    int y = j;
    if(isPoss(x,y,n,m)){
        if(grid[x][y] == 1){
            countone++;
        }else{
            countzero++;
        }
    }
    //north east
    x = i - 1;
    y = j + 1;
    if(isPoss(x,y,n,m)){
        if(grid[x][y] == 1){
            countone++;
        }else{
            countzero++;
        }
    }
    //northwest
    x = i - 1;
    y = j - 1;
    if(isPoss(x,y,n,m)){
        if(grid[x][y] == 1){
            countone++;
        }else{
            countzero++;
        }
    }

    //south
    x = i + 1;
    y = j;
    if(isPoss(x,y,n,m)){
        if(grid[x][y] == 1){
            countone++;
        }else{
            countzero++;
        }
    }
    // south east
    x = i + 1;
    y = j + 1;
    if(isPoss(x,y,n,m)){
        if(grid[x][y] == 1){
            countone++;
        }else{
            countzero++;
        }
    }

    //south west
    x = i + 1;
    y = j - 1;
    if(isPoss(x,y,n,m)){
        if(grid[x][y] == 1){
            countone++;
        }else{
            countzero++;
        }
    }

    //east
    x = i ;
    y = j + 1;
    if(isPoss(x,y,n,m)){
        if(grid[x][y] == 1){
            countone++;
        }else{
            countzero++;
        }
    }

    // west
    x = i ;
    y = j - 1;
    if(isPoss(x,y,n,m)){
        if(grid[x][y] == 1){
            countone++;
        }else{
            countzero++;
        }
    }
    return ;
}
vector<vector<int>>gameOfLife(vector<vector<int>>& board) {
    int n = board.size();
    int m = board[0].size();
    vector<vector<int>>mat(n,vector<int>(m,0));
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            int countzero = 0;
            int countone = 0;
            if(board[i][j] == 0){
                solve(i,j,n,m,board,countzero,countone);
                if(countone == 3){
                    mat[i][j] = 1;
                }
            }else{
                solve(i,j,n,m,board,countzero,countone);
                if(countone < 2){
                    mat[i][j] = 0;
                }else if(countone == 2 || countone == 3){
                    mat[i][j] = 1;
                }
                else if(countone > 3){
                    mat[i][j] = 0;
                }
            }
        }
    }
    return mat;
}


int main(){
    vector<vector<int>>board = {
        {0,1,0},
        {0,0,1},
        {1,1,1},
        {0,0,0}
    };

    vector<vector<int>>ans = gameOfLife(board);
    for(vector<int>res:ans){
        for(auto x:res){
            cout<<x<<" ";
        }
        cout<<endl;
    }
    return 0;
}