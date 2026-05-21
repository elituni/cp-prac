#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int find_smallest(vector<vector<int>>& dungeon, int x, int y, int hp, int m){
        hp += dungeon[x][y];
        m = min(m, hp);
        if(x == dungeon.size()-1 && y == dungeon[0].size()-1){
            return m;
        }
        if(x == dungeon.size()-1){
            return find_smallest(dungeon,x,y+1,hp,m);
        }
        if(y == dungeon[0].size()-1){
            return find_smallest(dungeon,x+1,y,hp,m);
        }   
        return max(find_smallest(dungeon,x+1,y,hp,m),find_smallest(dungeon,x,y+1,hp,m));
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {        
        return find_smallest(dungeon,0,0,0,0);
    }
};
// #include <bits/stdc++.h>
// using namespace std;

// class Solution {
// public:
//     int calculateMinimumHP(vector<vector<int>>& dungeon) {
//         int n = dungeon.size();
//         int m = dungeon[0].size();
//         vector<vector<int>> v(n, vector<int>(m,INT_MAX));
//         queue<pair<int,int>> q;
//         q.push({0,0});
//         v[0][0] = min(0,dungeon[0][0]);
//         while(!q.empty()){
//             pair<int,int> p = q.front();
//             q.pop();
//             if(p.first-1 >= 0 && p.second-1 >= 0){
//                 if(min(v[p.first-1][p.second],dungeon[p.first-1][p.second]+dungeon[p.first][p.second])==min(v[p.first][p.second-1],dungeon[p.first][p.second-1]+dungeon[p.first][p.second])){
                    
//                 }
//                 dungeon[p.first][p.second] += max(dungeon[p.first-1][p.second],dungeon[p.first][p.second-1]);
//                 v[p.first][p.second] = min(dungeon[p.first][p.second],max(v[p.first-1][p.second],v[p.first][p.second-1]));
//             }else if(p.first-1 >= 0){
//                 dungeon[p.first][p.second] += dungeon[p.first-1][p.second];
//                 v[p.first][p.second] = min(dungeon[p.first][p.second],v[p.first-1][p.second]);
//             }else if(p.second-1 >= 0){
//                 dungeon[p.first][p.second] += dungeon[p.first][p.second-1];
//                 v[p.first][p.second] = min(dungeon[p.first][p.second],v[p.first][p.second-1]);
//             }
//             if(p.first+1 < n && v[p.first+1][p.second] == INT_MAX){
//                 v[p.first+1][p.second]--;
//                 q.push({p.first+1,p.second});
//             }
//             if(p.second+1 < m && v[p.first][p.second+1] == INT_MAX){
//                 v[p.first][p.second+1]--;
//                 q.push({p.first,p.second+1});
//             }
//         }

//         for(int i = 0; i < n; i++){
//             for(int j = 0; j < m; j++){
//                 cout << v[i][j] << ' ';
//             }
//             cout << '\n';
//         }

//         return -v[n-1][m-1]+1;
//     }
// };