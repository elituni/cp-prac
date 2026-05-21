#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    ll t;
    cin >> t;
    for(ll it = 0; it < t; it++){
        ll n;
        cin >> n;
        vector<ll> w(n+1);
        ll sum = 0, in;
        for(ll ni = 1; ni <= n; ni++){
            cin >> in;
            sum += in;
            w[ni] = sum;
        }

        ll sq = (ll)sqrt((long double)n);

        ll max_diff = -1;
        queue<ll> fac;
        for(ll i = 1; i <= sq; i++){
            if(n%i == 0){
                fac.push(n/i);
                ll min = LLONG_MAX;
                ll max = -1;
                for(ll j = i; j <= n; j+= i){
                    min = std::min(min,w[j]-w[j-i]);
                    max = std::max(max,w[j]-w[j-i]);
                }
                max_diff = std::max(max_diff, max-min);
            }
        }
        while(!fac.empty()){
            ll i = fac.front();
            fac.pop();
            ll min = LLONG_MAX;
            ll max = -1;
            for(ll j = i; j <= n; j+= i){
                min = std::min(min,w[j]-w[j-i]);
                max = std::max(max,w[j]-w[j-i]);
            }
            max_diff = std::max(max_diff, max-min);
        }
        cout << max_diff << '\n';
    }
}



