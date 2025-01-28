#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Dsu{
    vector<ll> next_larger;
    vector<ll> rank;
    //stores the actual values of the representative elements, allows for union by rank
    vector<ll> leader_val;
    Dsu(ll n, vector<ll>& vals){
        next_larger.resize(n);
        rank.resize(n);
        for(int i = 0; i < n; i++){
            next_larger[i] = i;
            rank[i] = 0;
        }
        leader_val = vals;
    }

    //find_set
    ll find_max_index(ll l){
        if(next_larger[l] == l){
            return l;
        }
        return next_larger[l] = find_max_index(next_larger[l]);
    }

    //union_set
    void set_next(ll new_max, ll child){
        new_max = find_max_index(new_max);
        child = find_max_index(child);
        if(rank[child] > rank[new_max]){
            swap(leader_val[child],leader_val[new_max]);
            swap(child,new_max);
        }
        next_larger[child] = new_max;
        rank[new_max]++;
    }

};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, q, l, r;
    cin >> n >> q;
    vector<ll> arr(n);
    vector<vector<ll>> queries(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    //init queries
    for(int i = 0; i < q; i++){
        cin >> l >> r;
        l--; r--;
        queries[r].push_back(l);
    }

    //arpa's trick
    Dsu dsu(n, arr);
    stack<ll> unlabeled;
    for(int i = 0; i < n; i++){
        while(!unlabeled.empty() && arr[unlabeled.top()]<arr[i]){
            dsu.set_next(i, unlabeled.top());
            unlabeled.pop();
        }
        unlabeled.push(i);
        for(ll query : queries[i]){
            cout << dsu.leader_val[dsu.find_max_index(query)] << '\n';
        }
    }
}

