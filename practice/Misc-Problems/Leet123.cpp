
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        queue<vector<int>> q;
        vector<vector<bool>> vis_pacific(m, vector<bool>(n));
        for(int i = 0; i < m; i++){
            q.push({i,0});
            vis_pacific[i][0] = true;
        }
        for(int i = 1; i < n; i++){
            q.push({0,i});
            vis_pacific[0][i] = true;
        }
        while(!q.empty()){
            vector<int> curr = q.front();
            int x = curr[0]; int y = curr[1];
            q.pop();
            if(x > 0 && heights[x-1][y] >= heights[x][y]){
                if(!vis_pacific[x-1][y]){
                    q.push({x-1,y});
                    vis_pacific[x-1][y] = true;
                }
            }
            if(y > 0 && heights[x][y-1] >= heights[x][y]){
                if(!vis_pacific[x][y-1]){
                    q.push({x,y-1});
                    vis_pacific[x][y-1] = true;
                }
            }
            if(x < m-1 && heights[x+1][y] >= heights[x][y]){
                if(!vis_pacific[x+1][y]){
                    q.push({x+1,y});
                    vis_pacific[x+1][y] = true;
                }
            }
            if(y < n-1 && heights[x][y+1] >= heights[x][y]){
                if(!vis_pacific[x][y+1]){
                    q.push({x,y+1});
                    vis_pacific[x][y+1] = true;
                }
            }
        }
        vector<vector<bool>> vis_atlantic(m, vector<bool>(n));
        for(int i = 0; i < m; i++){
            q.push({i,n-1});
            vis_atlantic[i][n-1] = true;
        }
        for(int i = 1; i < n; i++){
            q.push({m-1,i});
            vis_atlantic[m-1][i] = true;
        }
        while(!q.empty()){
            vector<int> curr = q.front();
            int x = curr[0]; int y = curr[1];
            q.pop();
            if(x > 0 && heights[x-1][y] >= heights[x][y]){
                if(!vis_atlantic[x-1][y]){
                    q.push({x-1,y});
                    vis_atlantic[x-1][y] = true;
                }
            }
            if(y > 0 && heights[x][y-1] >= heights[x][y]){
                if(!vis_atlantic[x][y-1]){
                    q.push({x,y-1});
                    vis_atlantic[x][y-1] = true;
                }
            }
            if(x < m-1 && heights[x+1][y] >= heights[x][y]){
                if(!vis_atlantic[x+1][y]){
                    q.push({x+1,y});
                    vis_atlantic[x+1][y] = true;
                }
            }
            if(y < n-1 && heights[x][y+1] >= heights[x][y]){
                if(!vis_atlantic[x][y+1]){
                    q.push({x,y+1});
                    vis_atlantic[x][y+1] = true;
                }
            }
        }

        vector<vector<int>> ans;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(vis_pacific[i][j] && vis_atlantic[i][j]){
                    ans.push_back({i,j});
                }
            }
        }

        return ans;
    }
};