#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    
    for(int ti = 0; ti < t; ti++){
        ll n,y,x;
        cin >> n >> x >> y;
        ll max_l = 0;
        ll d = y-x;
        ll sum = 0;
        ll temp;
        for(ll ni = 0; ni < n; ni++){
            cin >> temp;
            sum += (temp/x)*y;
            max_l = max( (temp/x) * (x-y) + (temp%x), max_l);
        }
        sum += max_l;
        cout << sum << '\n';
    }
}