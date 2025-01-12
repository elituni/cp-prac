#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    const ll INF = LLONG_MAX;
    ll n, m, k, u, v, x, s, y;
    cin >> n >> m >> k;
    n++;
    vector<vector<array<ll,2>>> roads(n);
    for(int i = 0; i < m; i++){
        cin >> u >> v >> x;
        roads[u].push_back({v,x});
        roads[v].push_back({u,x});
    }

    vector<bool> is_train(n);
    set<array<ll,2>> q;
    q.insert({0,1});
    vector<ll> d(n, INF);
    d[1] = 0;
    ll curr;
    ll removable = 0;
    for(int i = 0; i < k; i++){
        cin >> s >> y;
        if(y < d[s]){
            d[s] = y;
            if(is_train[s]){
                removable++;
            }
            is_train[s] = true;
        }else{
            removable++;
        }
    }

    for(int i = 1; i < n; i++){
        if(is_train[i]) q.insert({d[i],i});
    }

    while(!q.empty()){
        curr = (*q.begin())[1];
        q.erase(q.begin()); // vlog(v)
        if(d[curr] == INF) break;
        for(auto [vertex, weight] : roads[curr]){
            if(d[curr] + weight <= d[vertex]){
                if(is_train[vertex]){
                    is_train[vertex] = false;
                    removable++;
                }
                q.erase({d[vertex], vertex}); //elog(v)
                d[vertex] = d[curr] + weight;
                q.insert({d[vertex], vertex}); //elog(v)
            }
        }
    }
    cout << removable;
}