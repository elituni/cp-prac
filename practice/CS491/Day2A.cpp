#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n, sum=0, in, max=0;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> in;
        sum += in;
        max = std::max(sum, max);
        sum = std::max(sum, 0ll);
    }
    cout << max;
}
