#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int max_steps = 100;

bool valid(int x, int y, int n, int m){
    return x > 0 && x <= n && y > 0 && y <= m;
}

void fill_blocked(int x, int y, int n, int m, vector<vector<bool>>& blocked){
    for(int i = x-2; i <= x+2; i++){
        if(valid(i,y,n,m)) blocked[i][y]=1;
    }
    for(int i = y-2; i <= y+2; i++){
        if(valid(x,i,n,m)) blocked[x][i]=1;
    }
}

void remove_blocked(int x, int y, int n, int m, vector<vector<bool>>& blocked){
    for(int i = x-2; i <= x+2; i++){
        if(valid(i,y,n,m)) blocked[i][y]=0;
    }
    for(int i = y-2; i <= y+2; i++){
        if(valid(x,i,n,m)) blocked[x][i]=0;
    }
}

void populate_energy(vector<vector<int>>& energy, int n, int m){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            energy[i][j] = min(i-1,n-i)+min(j-1,m-j)+1;
        }
    }
}

void heuristic(pair<int,int>& mattox, pair<int,int>& player, int n, int m, int& moves){
    while(player.first - mattox.first + player.second - mattox.second > 10){
        if(mattox.first < (n+1)/2)
            mattox.first++;
        else
            mattox.second++;

        if(player.first-mattox.first > player.second-mattox.second)
            player.first -= 2;
        else
            player.second -= 2;

        moves++;
    }
}

void stricter_heuristic(pair<int,int> ma, pair<int,int> pl, int n, int m, vector<vector<bool>>& blocked, vector<vector<int>>& energy, int moves, int lim){
    if(moves >= lim) return;
    fill_blocked(pl.first, pl.second, n, m, blocked);
    if(ma.first < (n+1)/2 && !blocked[ma.first+1][ma.second]){
        ma.first++;
    }else if(ma.second+1 <= m && !blocked[ma.first][ma.second+1] && energy[ma.first][ma.second]<energy[ma.first][ma.second+1]){
        ma.second++;
    }else if((ma.second+1 <= m && energy[ma.first][ma.second]==energy[ma.first][ma.second+1]&&!blocked[ma.first][ma.second+1])
    || (energy[ma.first][ma.second]==energy[ma.first+1][ma.second]&&!blocked[ma.first+1][ma.second])){
        if(max_steps > moves+energy[ma.first][ma.second]+1){
            // cout << "ma: " << ma.first << ' ' << ma.second << endl;
            // cout << "out: " << moves+energy[ma.first][ma.second]+1 << endl;
            max_steps = moves+energy[ma.first][ma.second]+1;
        }
        remove_blocked(pl.first, pl.second, n, m, blocked);
        return;
    }else{
        if(max_steps > moves+energy[ma.first][ma.second]){
            // cout << "ma: " << ma.first << ' ' << ma.second << endl;
            // cout << "out: " << moves+energy[ma.first][ma.second] << endl;
            max_steps = moves+energy[ma.first][ma.second];
        }        
        remove_blocked(pl.first, pl.second, n, m, blocked);
        return;
    }
    remove_blocked(pl.first, pl.second, n, m, blocked);
    if(pl.first-2>0 && !(pl.first-2 == ma.first && abs(pl.second-ma.second)<=1)){
        pl.first -= 2;
        stricter_heuristic(ma, pl, n, m, blocked, energy, moves+1, lim);
        pl.first += 2;
    }
    if(pl.first-1>0 && !(pl.first-1 == ma.first && abs(pl.second-ma.second)<=1)){
        pl.first -= 1;
        stricter_heuristic(ma, pl, n, m, blocked, energy, moves+1, lim);
        pl.first += 1;
    }
    if(pl.second-2>0 && !(pl.second-2 == ma.second && abs(pl.first-ma.first)<=1)){
        pl.second -= 2;
        stricter_heuristic(ma, pl, n, m, blocked, energy, moves+1, lim);
        pl.second += 2;
    }
    if(pl.second-1>0 && !(pl.second-1 == ma.second && abs(pl.first-ma.first)<=1)){
        pl.second -= 1;
        stricter_heuristic(ma, pl, n, m, blocked, energy, moves+1, lim);
        pl.second += 1;
    }


    
}

void solve(int n, int m){
    vector<vector<int>> energy(n+1,vector<int>(m+1));
    populate_energy(energy, n, m);
    
    pair<int,int> mattox = {1,1}; pair<int,int> player = {n,m};
    int moves = 0;
    heuristic(mattox, player, n, m, moves);

    vector<vector<bool>> blocked(n+1,vector<bool>(m+1));
    stricter_heuristic(mattox, player, n, m, blocked, energy, moves, moves+4);
}



int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;

    if(n%2 == 1 && m%2 == 1){
        cout << 2*((n+m-2)/3)+1;
        return 0;
    }

    solve(n, m);
    int first = max_steps;
    max_steps = 100;
    solve(m, n);
    int second = max_steps;
    
    cout << max(first,second);

}

/*
do simulation in nxm and mxn matrix

simulation for mattox:
    label each corner starting from 1.
    one path straight right until condition or middle, then down
    one path straight down then middle 
    if there is no path of higher val but there is one of equal val, answer += num+1
    if there is no path of equal or higherval, answer += num

simulation for player:
    travel distance 2 in the direction mattox is further in
    if perpendicular distance <= 7{
        recursively branch into all possible steps of 1 and 2 in the direction of mattox
        until mattox end condition is met.
    }

*/