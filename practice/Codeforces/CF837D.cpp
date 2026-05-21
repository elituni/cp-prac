#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll n, k;
    cin >> n >> k;

    vector<pair<ll,ll>> a(n);
    ll in, num2, num5;
    for(ll ni = 0; ni < n; ni++){
        num2 = 0;
        num5 = 0;
        cin >> in;
        while(in%2 == 0){
            num2++;
            in/=2;
        }
        while(in%5 == 0){
            num5++;
            in/=5;
        }
        a[ni] = {num2,num5};
    }

    vector<vector<vector<ll>>> dp(n,vector<vector<ll>>(k+1,vector<ll>(26*n,-1)));
    for(ll j = 0; j <= k; j++){
        for(ll l = 0; l < 26*n; l++){
            if(a[0].second >= l) dp[0][j][l] = a[0].first;
            else dp[0][j][l] = 0;
        }
    }
    for(ll i = 0; i < n; i++){
        for(ll l = 0; l < 26*n; l++){
            dp[i][0][l] = 0;
        }
    }
    for(ll i = 1; i < n; i++){
        for(ll j = 1; j <= k; j++){
            for(ll l = 0; l < 26*n; l++){
                dp[i][j][l] = max(a[i].first+dp[i-1][j-1][max(l-a[i].second,0LL)],dp[i-1][j][l]);
            }
        }
    }

    ll round = 0;
    for(ll l = 0; l < 26*n; l++){
        round = max(round,min(dp[n-1][k][l],l));
    }
    cout << round << '\n';
}

