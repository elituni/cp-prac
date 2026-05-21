#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    ll t;
    cin >> t;
    for(ll ti = 0; ti < t; ti++){
        int n;
        string s;
        cin >> n >> s;
        int c = 1;
        for(int i = 1; i < n-1; i++){
            if(s[i-1] != s[i+1]){
                c++;
            }
        }
        cout << c << '\n';
    }
}   