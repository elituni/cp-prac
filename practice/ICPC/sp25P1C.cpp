#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    ll n,m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    vector<int> w(n);
    vector<bool> vis(n);
    int u,v;
    for(int i = 0; i < m; i++){
        cin >> u >> v;
        u--;
        v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i = 0; i < n; i++){
        cin >> w[i];
    }

    //weight, index
    set<pair<int,int>> s;
    ll size = w[0];
    vis[0] = true;
    for(int val : g[0]){
        s.insert({w[val],val});
        vis[val] = true;
    }
    while(s.size() != 0 && size > s.begin() -> first){
        auto p = *s.begin();
        s.erase(s.begin());
        size += p.first;
        for(int val : g[p.second]){
            if(!vis[val]){
                s.insert({w[val],val});
                vis[val] = true;
            }
        }
    }
    cout << size;
}
