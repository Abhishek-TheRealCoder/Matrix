// You are given an m x n binary matrix grid. An island is a group of 1's (representing land) 
// connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid 
// are surrounded by water.
// The area of an island is the number of cells with a value 1 in the island.
// Return the maximum area of an island in grid. If there is no island, return 0.

// Example 1:
// Input: grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
// Output: 6
// Explanation: The answer is not 11, because the island must be connected 4-directionally.
// Example 2:

// Input: grid = [[0,0,0,0,0,0,0,0]]
// Output: 0

#include<bits/stdc++.h>
using namespace std;


bool isPoss(int i,int j,int n,int m,vector<vector<int>>& grid,vector<vector<int>>& visited){
    if(i >= 0 && i < n && j >= 0 && j < m && grid[i][j] == 1 && visited[i][j] == 0) return true;
    return false;
}
void dfs(int i, int j,int n,int m,vector<vector<int>>& grid,vector<vector<int>>& visited,int &count){
    visited[i][j] = 1;
    count++;

    //north
    int x = i - 1;
    int y = j;
    if(isPoss(x,y,n,m,grid,visited)){
        dfs(x,y,n,m,grid,visited,count);
    }

    //south
    x = i + 1;
    y = j;
    if(isPoss(x,y,n,m,grid,visited)){
        dfs(x,y,n,m,grid,visited,count);
    }
    //east
    x = i;
    y = j + 1;
    if(isPoss(x,y,n,m,grid,visited)){
        dfs(x,y,n,m,grid,visited,count);
    }

    //west
    x = i;
    y = j - 1;
    if(isPoss(x,y,n,m,grid,visited)){
        dfs(x,y,n,m,grid,visited,count);
    }
    return ;
}
int maxAreaOfIsland(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>>visited(n,vector<int>(m,0));
    int maxi = INT_MIN;

    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            if(grid[i][j] == 1 && !visited[i][j]){
                int count = 0;
                dfs(i,j,n,m,grid,visited,count);
                maxi = max(maxi,count);
            }
        }
    }
    return maxi == INT_MIN ? 0 : maxi;
}


int main(){
    vector<vector<int>>arr = {
        {0,0,1,0,0,0,0,1,0,0,0,0,0},
        {0,0,0,0,0,0,0,1,1,1,0,0,0},
        {0,1,1,0,1,0,0,0,0,0,0,0,0},
        {0,1,0,0,1,1,0,0,1,0,1,0,0},
        {0,1,0,0,1,1,0,0,1,1,1,0,0},
        {0,0,0,0,0,0,0,0,0,0,1,0,0},
        {0,0,0,0,0,0,0,1,1,1,0,0,0},
        {0,0,0,0,0,0,0,1,1,0,0,0,0}
    };

    int ans = maxAreaOfIsland(arr);
    cout<<ans;
    return 0;
}