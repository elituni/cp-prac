#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Dsu{
    vector<ll> next_larger;
    vector<ll> contains;
    Dsu(ll n){
        next_larger.resize(n);
        contains.resize(n);
        for(int i = 0; i < n; i++){
            next_larger[i] = i;
            contains[i] = 0;
        }
    }

    //find_set
    ll find_set(ll l){
        if(next_larger[l] == l){
            return l;
        }
        return next_larger[l] = find_set(next_larger[l]);
    }

    //union_set
    void set_next(ll new_max, ll child){
        new_max = find_set(new_max);
        child = find_set(child);
        next_larger[child] = new_max;
    }
};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m, k, a, b, in;
    cin >> n >> m >> k >> a >> b;
    Dsu dsu(n);
    for(int i = 0; i < k; i++){
        cin >> in;
        int hash = (a*in+b)%n;
        dsu.contains[dsu.find_set(hash)]++;
        cout << dsu.find_set(hash) << '\n';
        if(dsu.contains[dsu.find_set(hash)] == m){
            if(dsu.find_set(hash) == n-1){
                dsu.set_next(0, hash);
            }else{
                dsu.set_next(dsu.find_set(hash)+1, dsu.find_set(hash));
            }
        }
    }

}