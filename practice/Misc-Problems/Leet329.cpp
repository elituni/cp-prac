#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void populate(vector<vector<int>>& v, vector<vector<int>>& matrix, int x, int y){
        if(v[x][y] != -1) return;
        if(x > 0 && matrix[x-1][y] > matrix[x][y]){
            populate(v, matrix, x-1, y);
            v[x][y] = max(v[x][y],v[x-1][y]+1);
        }if(x < matrix.size()-1 && matrix[x+1][y] > matrix[x][y]){
            populate(v, matrix, x+1, y);
            v[x][y] = max(v[x][y],v[x+1][y]+1);
        }if(y > 0 && matrix[x][y-1] > matrix[x][y]){
            populate(v, matrix, x, y-1);
            v[x][y] = max(v[x][y],v[x][y-1]+1);
        }if(y < matrix[0].size()-1 && matrix[x][y+1] > matrix[x][y]){
            populate(v, matrix, x, y+1);
            v[x][y] = max(v[x][y],v[x][y+1]+1);
        }
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        vector<vector<int>> v(matrix.size(), vector<int>(matrix[0].size(),-1));
        int largest = 0;
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                populate(v,matrix,i,j);
                largest = max(largest, v[i][j]);
            }
        }
        return largest;
    }
};