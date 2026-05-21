#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    ll t;
    cin >> t;
    for(ll ti = 0; ti < t; ti++){
        ll n,k;
        cin >> n >> k;
        string s,t;
        cin >> s >> t;
        bool dead = false;
        //check middle where u cant swap
        for(int mi = max((ll)0,n-k); mi < min(n,k); mi++){
            if(s[mi] != t[mi]){
                dead = true;
                cout << "NO\n";
                break;
            }
        }
        if(dead) continue;

        map<char,int> sf;
        map<char,int> tf;
        for(int si = 0; si < n; si++){
            sf[s[si]]++;
            tf[t[si]]++;
        }

        //check if letters match
        for(auto [key, val] : sf){
            if(tf[key] != val){
                dead = true;
                cout << "nO\n";
                break;
            } 
        }if(dead) continue;
        for(auto [key, val] : tf){
            if(sf[key] != val){
                dead = true;
                cout << "No\n";
                break;
            } 
        }if(dead) continue;

        cout << "YES\n";

    }
}
