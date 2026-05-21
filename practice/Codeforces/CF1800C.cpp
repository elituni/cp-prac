#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    ll t;
    cin >> t;
    for(ll ti = 0; ti < t; ti++){
        int n;
        cin >> n;
        vector<int> v(n);
        for(int ni = 0; ni < n; ni++){
            cin >> v[ni];
        }
        priority_queue<int, vector<int>, greater<int>> s;
        int h = 0;
        for(int ni = n-1; ni >= 0; ni--){
            if(v[ni] == 0) h++;
            else{
                if(s.size() < h){
                    s.push(v[ni]);
                }else{
                    if(!s.empty() && s.top() < v[ni]){
                        s.pop();
                        s.push(v[ni]);
                    }
                }
            }
        }
        ll ans = 0;
        while(!s.empty()){
            ans += s.top();
            s.pop();
        }
        cout << ans << '\n';

    }
}
