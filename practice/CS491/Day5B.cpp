#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Dsu{
    vector<int> parents;
    vector<int> size;
    int components;

    Dsu(int n){
        components = n;
        parents.resize(n);
        size.resize(n);
        for(int i = 0; i < n; i++){
            parents[i] = i;
            size[i] = 1;
        }
    }

    int find_set(int a){
        if(parents[a] != a){
            parents[a] = find_set(parents[a]);
        }
        return parents[a];
    }
    
    void union_set(int a, int b){
        a = find_set(a);
        b = find_set(b);
        if(a == b) return;
        if(size[a] < size[b]) swap(a,b);
        parents[b] = a;
        size[a] += size[b];
        components--;
    }
};



int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int n, m, k;
    cin >> n >> m >> k;
    Dsu dsu(n);
    set<pair<int,int>> edges;
    vector<pair<int,int>> earthquakes(k);
    int n1, n2;
    for(int i = 0; i < m; i++){
        cin >> n1 >> n2;
        n1--; n2--;
        edges.insert(make_pair(n1,n2));
    }

    for(int i = 0; i < k; i++){
        cin >> n1 >> n2;
        n1--; n2--;
        earthquakes[k-i-1] = make_pair(n1,n2);
        edges.erase(make_pair(n1,n2));
    }

    for(auto [a,b] : edges){
        dsu.union_set(a,b);
    }
    vector<pair<int,int>> output(k);
    for(int i = 0; i < k; i++){
        output[k-i-1] = make_pair(dsu.size[dsu.find_set(0)], dsu.components);
        dsu.union_set(earthquakes[i].first, earthquakes[i].second);
    }
    for(int i = 0; i < k; i++){
        cout << output[i].first << ' ' << output[i].second << '\n';
    }
}