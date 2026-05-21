#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    ll t;
    cin >> t;

    for(ll i = 0; i < t; i++){
        ll len;
        cin >> len;
        vector<ll> vec(len);
        for(int j = 0; j < len; j++){
            cin >> vec[j];
        }

        for(int k = len-2; k >= 0; k--){
            vec[k] += vec[k+1];
        }

        ll sum = vec[0];
        for(int p = 1; p < len; p++){
            if(vec[p] > 0) sum += vec[p];
        }
        cout << sum << '\n';
    }

}