#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll n,l,p;
    cin>>n>>l>>p;
    vector<ll> num(n);
    vector<ll> dist(n);
    dist[0] = l/2;
    for(int i = 1; i < n; i++){
        dist[i] = dist[i-1]+l;
    }
    ll x;
    ll max_dist = 0;
    for(int i = 0; i < p; i++){
        cin >> x;
        auto it = lower_bound(dist.begin(), dist.end(), x);
        if(it == dist.end()){
            num[n-1]++;
            max_dist = max(max_dist, abs(x-dist[n-1]));
        }else{
            int index = it - dist.begin();
            if(abs(x-dist[index-1]) < abs(x-dist[index])) index--;
            num[index]++;
            max_dist = max(max_dist, abs(x-dist[index]));
        }
    }
    ll max_elem = 0;
    for(int i = 0; i < n; i++){
        max_elem = max(max_elem, num[i]);
    }
    cout << max_dist << '\n' << max_elem;

}