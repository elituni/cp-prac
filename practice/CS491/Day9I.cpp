#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main(){
    ll n,k;
    cin >> n;
    vector<vector<ll>> d(n, vector<ll>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> d[i][j];
        }
    }
    cin >> k;
    ll a,b,c;
    for(int i = 0; i < k; i++){
        cin >> a>>b>>c;
        a--;
        b--;
        d[a][b] = min(d[a][b],c);
        d[b][a] = min(d[b][a],c);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                d[i][j] = min(d[i][j], d[i][a] + d[a][j]); 
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                d[i][j] = min(d[i][j], d[i][b] + d[b][j]); 
            }
        }
        ll sum = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                sum += d[i][j];
            }
        }
        cout << sum/2 << ' ';
    }
}