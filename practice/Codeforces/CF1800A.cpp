#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    ll t;
    cin >> t;
    for(ll ti = 0; ti < t; ti++){
        string s; ll n;
        cin >> n >> s;
        ll c = 0;
        bool yes = true;
        array<char,8> letters = {'m','M','e','E','o','O','w','W'};
        for(int l = 0; l < 8; l += 2){
            if(s[c] != letters[l] && s[c] != letters[l+1]){
                yes = false;
                break;
            }
            while(s[c] == letters[l] || s[c] == letters[l+1]){
                c++;
            }
        }
        if(yes && c == n){
            cout << "Yes" << '\n';
        }else{
            cout << "No" << '\n';
        }
    }
}