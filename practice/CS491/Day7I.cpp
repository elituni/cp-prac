#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void dfs(vector<vector<int>>& graph, vector<int>& labels, int v, int k){
    for(auto vertex : graph[v]){
        if(labels[vertex] == -1){
            labels[vertex] = (labels[v]+1)%k;
            dfs(graph,labels,vertex,k);
        }
    }
}

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    ll n, m, k;
    cin >> n >> m >> k;

    if(k == 1 && m > 0){
        cout << -1;
        return 0;
    }

    vector<vector<int>> graph(n);
    vector<int> labels(n,-1);
    
    int a, b;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for(int i = 0; i < n; i++){
        if(labels[i] == -1){
            labels[i] = 0;
            dfs(graph,labels,i,k);
        }
        cout << labels[i]+1 << '\n';
    } 
}