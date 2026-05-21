#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MOD = 1000000007;
ll pow_mod(ll x, ll n, ll m) {
    if (n == 0)
        return 1;
    ll t = pow_mod(x, n / 2, m);
    if (n % 2 == 0)
        return (t * t) % m;
    else
        return (((t * t) % m) * x) % m;
}


int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    ll t;
    cin >> t;
    for(ll ti = 0; ti < t; ti++){
        ll n;
        cin >> n;
        vector<bool> vec(n);
        for(ll ni = n-1; ni >=0; ni--){
            char c;
            cin >> c;
            vec[ni] = (c == '1');
        }
        if(n == 1){
            cout << 0 << '\n';
            continue;
        }
        ll carry = 0; ll noncarry = 1; ll denom = 1;
        for(ll ni = 0; ni < n-1; ni++){
            // if(vec[ni] == 0 && carry == 0){
            //     continue;
            // }
            if(vec[ni] == 1){
                carry <<= 1;
                carry += noncarry;
            } else{
                noncarry <<= 1;
                noncarry += carry;
            }
            denom <<= 1;
            denom %= 1000000007;
            carry %= 1000000007;
            noncarry %= 1000000007;
        }
        ll count = n-1;

        ll num = (count*denom + carry)%MOD;

        ll g = gcd(num,denom);
        num /= g; denom /= g;

        // cout << "num: " << num << "    denom: " << denom << '\n';
        ll ans = (num * pow_mod(denom, MOD - 2, MOD))%MOD;
        if(ans < 0) ans += MOD;
        cout << ans << '\n';
    }
    
}
