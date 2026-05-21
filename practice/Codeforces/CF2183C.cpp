/*
l = min(n-k, k-1)
r = max(n-k, k-1)
a = i-1
b = min(i-1,l)

binary search for i such that a+b+i<=m, output a+b+2

3i-2<=m
i = max((m+2)/3,(m-l+1)/2)

if i >= r, output r+l+1
else, output i-1+min(i-1,l)+2



l+2i-1<=m

*/

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
        ll n,m,k;
        cin >> n >> m >> k;
        // cout << "n,m,k: " << n << ' ' << m << ' ' << k << '\n';
        if(n == 1){
            cout << 1 << '\n';
            continue;
        }if(m == 1){
            cout << 2 << '\n';
            continue;
        }
        ll l = min(n-k, k-1);
        ll r = max(n-k, k-1);
        ll i = max((m+2)/3,(m-l+1)/2);
        cout << "i: " << i << '\n';
        cout << "l,r: " << l << ' ' << r << '\n';
        if(i > r) cout << r+l+1 << '\n';
        else cout << i-1+min(i-1,l)+2 << '\n';
    }

}