// You are given an m x n matrix grid and a positive integer k. An island is a group of positive integers
// (representing land) that are 4-directionally connected (horizontally or vertically).
// The total value of an island is the sum of the values of all cells in the island.
// Return the number of islands with a total value divisible by k.

// Example 1:
// Input: grid = [[0,2,1,0,0],[0,5,0,0,5],[0,0,1,0,0],[0,1,4,7,0],[0,2,0,0,8]], k = 5
// Output: 2
// Explanation:
// The grid contains four islands. The islands highlighted in blue have a total value that is divisible by 5, while the islands highlighted in red do not.

// Example 2:
// Input: grid = [[3,0,3,0], [0,3,0,3], [3,0,3,0]], k = 3
// Output: 6
// Explanation:
// The grid contains six islands, each with a total value that is divisible by 3.

 
#include <bits/stdc++.h>
using namespace std;

bool isPoss(int i,int j,int n,int m,vector<vector<int>>& grid,vector<vector<int>>&visited){
    if(i >= 0 && i < n && j >= 0 && j < m && grid[i][j] > 0 && visited[i][j] == 0) return true;
    return false;
}
void dfs(int i,int j,int n,int m,vector<vector<int>>& grid,vector<vector<int>>&visited,long long &sum){
    visited[i][j] = 1;
    sum += grid[i][j];

    //north
    int x = i - 1;
    int y = j;
    if(isPoss(x,y,n,m,grid,visited)){
        dfs(x,y,n,m,grid,visited,sum);
    }
    //south
    x = i + 1;
    y = j;
    if(isPoss(x,y,n,m,grid,visited)){
        dfs(x,y,n,m,grid,visited,sum);
    }
    

    //east
    x = i;
    y = j + 1;
    if(isPoss(x,y,n,m,grid,visited)){
        dfs(x,y,n,m,grid,visited,sum);
    }
    
    //west
    x = i;
    y = j - 1;
    if(isPoss(x,y,n,m,grid,visited)){
        dfs(x,y,n,m,grid,visited,sum);
    }
    
    return;
}
int countIslands(vector<vector<int>>& grid, int k) {
    int n = grid.size();
    int m = grid[0].size();
    int count = 0;
    vector<vector<int>>visited(n,vector<int>(m,0));
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            long long sum = 0;
            if(grid[i][j] > 0 && visited[i][j] == 0){
                dfs(i,j,n,m,grid,visited,sum);
                if(sum % k == 0) count++;
            }
        }
    }
    return count;
}

int main(){
    vector<vector<int>>arr = {
        {3,0,3,0},
        {0,3,0,3},
        {3,0,3,0}
    };
    int k = 3;
    int ans = countIslands(arr,k);
    cout<<ans;
    return 0;
}

 

