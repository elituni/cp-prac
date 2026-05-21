#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct BellmanFord{
    // from, to, weight
    vector<array<ll,3>> edges;
    vector<ll> dist;

    BellmanFord(ll n){
        dist.resize(n);
        for(ll i = 0; i < n; i++){
            dist[i] = 0;
        }
    }

    bool has_neg_cycle(){
        for(ll i = 0; i < dist.size(); i++){
            for(auto edge : edges){
                if(dist[edge[0]] + edge[2] < dist[edge[1]]){
                    if(i == dist.size()-1){
                        return true;
                    }
                    dist[edge[1]] = dist[edge[0]]+edge[2];
                }
            }
        }
        return false;
    }
};


int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll n, m;
    cin >> n >> m;

    BellmanFord bf(n);

    char discard;
    ll from, to, weight;
    for(ll i = 0; i < m; i++){
        cin >> discard >> from >> discard >> discard >> to >> discard >> discard >> weight;
        from--; to--;
        bf.edges.push_back({from,to,weight});
    }

    bool has_sol = !bf.has_neg_cycle();

    if(has_sol){
        cout << "YES";
    }else{
        cout << "NO";
    }
    
}