#include <bits/stdc++.h>
using namespace std;


void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int x, int y){
    for(int i = max(0,x-1); i < min((int)(visited.size()-1),x+1); i++){
        for(int j = max(0,y-1); j < min((int)(visited[0].size()-1),y+1); j++){
            if(!visited[i][j] && grid[i][j] == '1'){
                visited[i][j] = true;
                dfs(grid,visited,i,j);
            }
        }
    }
}

int numIslands(vector<vector<char>>& grid) {
    vector<vector<bool>> visited;
    int counter = 0;
    for(int i = 0; i < grid.size(); i++){
        for(int j = 0; j < grid[0].size(); j++){
            if(!visited[i][j] && grid[i][j] == '1'){
                visited[i][j] = true;
                dfs(grid,visited,i,j);
                counter++;
            }
        }
    }
}
