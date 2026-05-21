#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;

    for(int ti = 0; ti < t; ti++){
        int n,k;
        cin >> n >> k;

        vector<array<int,3>> odds;
        vector<array<int,3>> evens;
        vector<array<int,3>> modds;
        vector<array<int,3>> mevens;
        for(int ki = 0; ki < k; ki++){
            int x,y;
            cin >> y >> x;
            if((x+y-1)%2 == 0){
                odds.push_back({x+y-1,x,y});
            }else{
                evens.push_back({x+y-1,x,y});
            }
            x = n-x+1;
            y = n-y+1;
            if((x+y-1)%2 == 0){
                modds.push_back({x+y-1,x,y});
            }else{
                mevens.push_back({x+y-1,x,y});
            }
        }
        sort(evens.begin(), evens.end());
        sort(odds.begin(), odds.end());
        sort(mevens.begin(), mevens.end());
        sort(modds.begin(), modds.end());

        // for(auto [a,b,c] : odds){
        //     cout << a << ' ' << b << ' ' << c << ", ";
        // }
        // cout << '\n';

        ll c = 0;
        vector<int> dp(2*n+1);
        int v = 0;
        for(int i = 1; i <= 2*n; i++){
            if(v >= odds.size() || odds[v][0] != i){
                dp[i] = dp[i-1];
            }else{
                int hit = abs(odds[v][1]-odds[v][2]);
                // cout << "hit: " << hit << '\n';
                c += dp[i-1] - dp[hit];
                dp[i] = dp[i-1]+1;
                v++;
            }
        }
        dp = vector<int>(2*n + 1, 0);
        v=0;
        for(int i = 1; i <= 2*n; i++){
            if(v >= evens.size() || evens[v][0] != i){
                dp[i] = dp[i-1];
            }else{
                int hit = abs(evens[v][1]-evens[v][2]);
                // cout << "hit: " << hit << '\n';
                c += dp[i-1] - dp[hit];
                dp[i] = dp[i-1]+1;
                v++;
            }
        }


        dp = vector<int>(2*n + 1, 0);
        v=0;
        for(int i = 1; i <= 2*n; i++){
            if(v >= modds.size() || modds[v][0] != i){
                dp[i] = dp[i-1];
            }else{
                int hit = abs(modds[v][1]-modds[v][2]);
                // cout << "hit: " << hit << '\n';
                c += dp[i-1] - dp[hit];
                dp[i] = dp[i-1]+1;
                v++;
            }
        }
        dp = vector<int>(2*n + 1, 0);
        v=0;
        for(int i = 1; i <= 2*n; i++){
            if(v >= mevens.size() || mevens[v][0] != i){
                dp[i] = dp[i-1];
            }else{
                int hit = abs(mevens[v][1]-mevens[v][2]);
                // cout << "hit: " << hit << '\n';
                c += dp[i-1] - dp[hit];
                dp[i] = dp[i-1]+1;
                v++;
            }
        }
        cout << c << '\n';


       
        

    }
}
//right: y-n-1+x
//left: y-x