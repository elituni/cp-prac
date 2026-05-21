#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll a, b;
    cin >> a >> b;
    ll counter = 0;
    for(ll i = a; i <= b; i++){
        ll checking = i;
        for(ll j = 0; j < floor(log10(i))-1; j++){
            if(checking % 1000 == 495){
                counter++;
                break;
            }
            checking /= 10;
        }
    }
    cout << counter;
}