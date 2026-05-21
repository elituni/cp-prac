#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    for(int ti = 0; ti < t; ti++){
        int n, m;
        cin >> n >> m;
        int atleast = n-(m*2);
        vector<int> k(n);
        map<int,int> freq;
        int in;
        for(int i = 0; i < n; i++){
            cin >> in;
            in--;
            k[i] = in;
            freq[(i-in+n)%n]++;
        }
        vector<int> ans;
        for(auto [key,val] : freq){
            if(val >= atleast){
                vector<bool> visited(n);
                int count = 0;
                for(int i = 0; i < n; i++){
                    if(visited[i]) continue;
                    visited[i] = true;
                    int iter = i;
                    while((iter = k[(iter+key)%n]) != i){
                        visited[iter] = true;
                        count++;
                    }
                }
                if(count <= m){
                    ans.push_back(key);
                }
            }
        }
        cout << ans.size();
        for(int i = 0; i < ans.size(); i++){
            cout << ' ' << ans[i];
        }
        cout << '\n';
    }
}
