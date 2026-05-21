#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll t;
    cin >> t;
    for(int i = 0; i < t; i++){
        ll n, x;
        cin >> n >> x;

        if(x == 0 && n == 1){
            cout << "-1\n";
            continue;
        }
        
        ll first = x;
        while(first != 0){
            if(first&1) n--;
            first>>=1;
        }
        if(n <= 0){
            cout << x << '\n';
            continue;
        }
        if(x < 2 && n&1){
            x += 4;
            n--;
        }
        if(n&1){
            x += 2;
            n--;
        }
        x += n;
        cout << x << '\n';
    }
    
    
}