#include <bits/stdc++.h>
using namespace std;
using ll = long long;


/*
0 if i>j
1 if i=j
else, the min of{
    1+dp[i+1][j]
    dp[i+1][k-1]+dp[k+1][j] for all c_i==c_k, k<=j
    dp[i+2][j] for c_i==c_i+1
}
*/
void populate(vector<vector<int>>& dp, int i, int j, vector<int>& c){
    if(i > j) dp[i][j] = 0;
    else if(i == j) dp[i][j] = 1;
    else{
        int a = 1+dp[i+1][j]; // 2
        if(i < c.size()-1 && c[i] == c[i+1]){ // false
            a = min(a, 1+dp[i+2][j]);
        }
        for(int k = i+2; k <= j; k++){ //doesn't enter
            if(c[i] == c[k])
                a = min(a, dp[i+1][k-1]+dp[k+1][j]);
        }
        dp[i][j] = a;
    }
}


int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> c(n);
    for(int ni = 0; ni < n; ni++){
        cin >> c[ni];
    }

    vector<vector<int>> dp(n+1, vector<int>(n+1));

    for(int i = n-1; i >= 0; i--){
        for(int j = 0; j < n; j++){
            populate(dp,i,j,c);
        }
    }
    cout << dp[0][n-1] << '\n';    
}

