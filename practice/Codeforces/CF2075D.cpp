#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    ll t;
    cin>>t;

    const ll inf = LLONG_MAX;
        const int n = 61;
        array<array<ll,n>,n> dp;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                dp[i][j] = inf;
            }
        }
        dp[0][0] = 0;


        for(int k = 1; k < n; k++){
            for(int i = n-1; i >= 0; i--){
                for(int j = n-1; j >= 0; j--){
                    if(dp[i][j] == inf) continue;
                    if(i+k < n){
                        dp[i+k][j] = min(dp[i+k][j], dp[i][j]+(1LL<<k));
                    }
                    if(j+k < n){
                        dp[i][j+k] = min(dp[i][j+k], dp[i][j]+(1LL<<k));
                    }
                }
            }
        }
    for(ll ti = 0; ti < t; ti++){
        ll x,y;
        cin>>x>>y;

        ll min_cost = LLONG_MAX;
        for(int i = 0; i<n ; i++){
            for(int j = 0; j<n; j++){
                // cout << dp[i][j] << ' ';
                if(dp[i][j] != inf && x>>i == y>>j){
                    min_cost = min(min_cost,dp[i][j]);
                }
            }
            // cout << '\n';
        }
        cout << min_cost << '\n'; 
    }
}


/*
a vector of largest num at which its possible to obtain that

for each number, add the number to each element in the vector,
then add it to vector if its not already in it.
If num>=sum && num&1==sum&1 && l[(x+(num-sum)/2)] < curr then found.


*/