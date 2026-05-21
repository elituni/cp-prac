#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for(int ti = 0; ti < t; ti++){
        int n, u, v;
        cin >> n;
        vector<vector<int>> g(n);
        vector<bool> vis(n);
        for(int ni = 0; ni < n-1; ni++){
            cin >> u >> v;
            u--; v--;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        vis[0] = true;

        // for(int i = 0; i < g.size(); i++){
        //     for(int j = 0; j < g[i].size(); j++){
        //         cout << g[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }
        // cout << '\n';
        
        //key: level; val: vector of node ID
        map<int, vector<int>> levels;
        vector<vector<int>> children(n);
        queue<int> q;
        q.push(0);
        int counter = 0;
        while(!q.empty()){
            int size = q.size();
            // cout << "size: " << size << '\n';
            counter++;
            for(int i = 0; i < size; i++){
                int curr = q.front();
                q.pop();
                for(int j = 0; j < g[curr].size(); j++){
                    if(!vis[g[curr][j]]){
                        children[curr].push_back(g[curr][j]);
                        levels[counter].push_back(g[curr][j]);
                        vis[g[curr][j]] = true;
                        q.push(g[curr][j]);
                    }
                }
            }
        }


        // for(int i = 0; i < children.size(); i++){
        //     for(int j = 0; j < children[i].size(); j++){
        //         cout << children[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }
        // cout << '\n';

        map<int, vector<int>> prev;
        map<int, vector<int>> curr;
        for(; counter > 0; counter--){
            for(int node : levels[counter]){
                vector<vector<int>> l;
                for(int c : children[node]){
                    if(!prev.contains(c)){
                        cout << "ERROR";
                    }
                    l.push_back(prev[c]);
                }
                sort(l.begin(),l.end());
                vector<int> str = {(int)children[node].size(), -1};
                for(auto& substr : l){
                    str.insert(str.end(), substr.begin(), substr.end());
                }
                curr.insert({node,str});
            }
            swap(prev,curr);
            curr.clear();
        }

        

        for(auto& [key,val] : prev){
            cout << key << ':';
            for(int v : val){
                cout << v << ' ';
            }
            cout << '\n';
        }

        std::map<std::vector<int>, int> freq;
        for (auto& [key,val] : prev) {
            freq[val]++;
        }
        int allowable = g[0].size()&1;
        bool bad = false;

        for (auto& [vec, count] : freq) {
            allowable -= count&1;
            if(allowable < 0){
                bad = true;
                break;
            }
        }

        if(bad) cout << "NO\n";
        else cout << "YES\n";
    }
}

