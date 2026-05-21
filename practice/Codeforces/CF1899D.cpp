#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    ll t;
    cin >> t;
    for(ll i = 0; i < t; i++){
        ll n, in;
        cin >> n;
        unordered_map<ll, ll> v;
        v.reserve(1024); // pre-reserve 1024 buckets
        v.max_load_factor(0.25); // allocate new buckets when load factor > 0.25
        for(ll j = 0; j < n; j++){
            cin >> in;
            if(in == 1) in++;
            v[in]++;
        }
        ll sum = 0;
        for(auto [key,val] : v){
            sum += val*(val-1)/2;
        }
        cout << sum << '\n';
    }
    
}