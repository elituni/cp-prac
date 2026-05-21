#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int counter = 0;

bool has_adjacent(vector<vector<bool>>& grid, ll x, ll y, ll n, ll m){
    bool val = grid[x][y];
    if(x != 0) val = val || grid[x-1][y];
    if(y != 0) val = val || grid[x][y-1];
    if(x != n-1) val = val || grid[x+1][y];
    if(y != m-1) val = val || grid[x][y+1];
    if(x != n-1 && y != 0) val = val || grid[x+1][y-1];
    if(x != 0 && y != 0) val = val || grid[x-1][y-1];
    if(x != n-1 && y != m-1) val = val || grid[x+1][y+1];
    if(x != 0 && y != m-1) val = val || grid[x-1][y+1];
    return val;
}

void count(ll x, ll y, ll n, ll m, vector<vector<bool>>& grid, ll kings_left){
    if(kings_left == 0){
        counter++;
        return;
    }
    for(int i = x; i < n; i++){
        for(int j = i==x?y:0; j < m; j++){
            if(!has_adjacent(grid, i, j, n, m)){
                grid[i][j] = true;
                count(i, j+2, n, m, grid, kings_left-1);
                grid[i][j] = false;
            }
        }
    }
}

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll n, m, k;
    cin >> n >> m >> k;
    vector<vector<bool>> grid(n,vector<bool>(m,false));
    count(0,0,n,m,grid,k);
    cout << counter;
    
}