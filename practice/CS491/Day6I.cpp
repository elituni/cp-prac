#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    //node, height
    map<int, int> tree;
    ll n, in;
    cin >> n;
    cin >> in;
    tree.insert({in,0});
    vector<int> out;
    for(ll i = 1; i < n; i++){
        cin >> in;
        auto it = tree.lower_bound(in);
        int rv, rh = -1, lv, lh = -1;
        if(it != tree.end()){
            auto [rval, rheight] = *it;
            rv = rval;
            rh = rheight;
        }
        if(it != tree.begin()){
            it--;
            auto [lval, lheight] = *it;
            lv = lval;
            lh = lheight;

        }
        if(lh > rh){
            out.push_back(lv);
            tree.insert({in,lh+1});
        }else{
            out.push_back(rv);
            tree.insert({in,rh+1});
        }
    }
    for(int i = 0; i < out.size(); i++){
        cout << out[i] << ' ';
    }cout << '\n';
}