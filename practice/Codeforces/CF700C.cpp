#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<int>> g;
vector<int> tin,low;
map<pair<int,int>,pair<int,int>> roads;
int timer;

//check if there is a simple path from s to e
void dfs1(int curr, vector<int>& prev){
    for(int v : g[curr]){
        if(prev[v] != -1){
            prev[v] = curr;
            dfs1(v,prev);
        }
    }
}

//tarjan's algorithn for bridges that considers edges in the simple path
void dfs2(int curr, int parent, set<pair<int,int>>& path, pair<int,int>& best){
    tin[curr] = low[curr] = timer++;
    bool parent_skipped = false;
    for(int v : g[curr]){
        if(v==parent && !parent_skipped){
            parent_skipped = true;
        }else if(tin[v] != -1){
            low[curr] = min(low[curr],tin[v]);
        }else{
            dfs2(v,curr,path,best);
            low[curr] = min(low[curr],low[v]);
            if(tin[v] < low[v] && path.contains({curr,v})){
                best = min(best,roads[{curr,v}]);
            }
        }
    }
}

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int n,m,s,e;

    cin >> n >> m >> s >> e;
    s--; e--;
    g.resize(n);
    int x,y,w;
    for(int i = 1; i <= m; i++){
        cin >> x >> y >> w;
        x--; y--;
        g[x].push_back(y);
        g[y].push_back(x);
        roads[{x,y}] = roads[{y,x}] = {w,i};
    }


    vector<int> prev(n,-1);
    dfs1(s,prev);
    if(prev[e] == -1){
        cout << "0\n0";
        return 0;
    }

    pair<int,int> best = {INT_MAX,INT_MAX};

    set<pair<int,int>> path;
    int iter = e;
    while(prev[iter] != s){
        path.insert({prev[iter],iter});
        path.insert({iter,prev[iter]});
        iter = prev[iter];
    }


    vector<int> prev2(n,-1);
    for(auto [u,v] : path){
        g[u].erase(find(g[u].begin(),g[u].end(),v));
        g[v].erase(find(g[v].begin(),g[v].end(),u));
        prev2.assign(n,-1);
        dfs1(s,prev2);
        if(prev2[e] == -1){
            best = min(best,{roads[{u,v}]});
            continue;
        }

        set<pair<int,int>> path2;
        iter = e;
        while(prev[iter] != s){
            path2.insert({prev[iter],iter});
            path2.insert({iter,prev[iter]});
            iter = prev[iter];
        }
        tin.assign(n,-1);
        low.assign(n,-1);
        timer = 0;
        pair<int,int> best2 = {INT_MAX,INT_MAX};
        dfs2(s,-1,path2,best);
        if(best2.first != INT_MAX){
            best = min(best,{roads[{u,v}].first+best2.first,roads[{u,v}].second+best2.second});
        }
        g[u].push_back(v);
        g[v].push_back(u);
    }
    cout << best.first << ' ' << best.second;
}


