#include <bits/stdc++.h>
using namespace std;
using ll = long long;

static ll m = 998244353;
static ll n = 100000;
static ll k = 450;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // dp[i,j]: partitions with i elements and <= j subsets
    vector<vector<int>> dp(n,vector<int>(k));
    for(int j = 1; j < k; j++){
        dp[0][j] = 1;
    }
    for(int i = 0; i < n; i++){
        dp[i][1] = 1;
    }
    for(int i = 1; i < n; i++){
        for(int j = 2; j < k; j++){
            dp[i][j] = (dp[i][j] + dp[i][j-1])%m;
            if(i-j >= 0){
                dp[i][j] = (dp[i][j] + dp[i-j][j])%m;
            }
        }
    }
    
    int t;
    cin >> t;
    
    for(int ti = 0; ti < t; ti++){
        ll n;
        cin >> n;
        ll s = 0;
        ll i = 1;
        if(n%2 == 0){
            i = 2;
        }

        while(i*i <= n){
            ll p = (n-(i*i))/2;
            // cout << p << '\n';
            s = (s + dp[p][i])%m;
            i += 2;
        }
        cout << s << '\n';

    }
}