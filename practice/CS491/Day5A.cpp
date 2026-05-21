#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Dsu{
    vector<int> parents;
    vector<int> size;

    Dsu(int n){
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
    }
};


int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    Dsu dsu(n);
    string op;
    int n1, n2;
    for(int i = 0; i < m; i++){
        cin >> op;
        if(op == "Union"){
            cin >> n1 >> n2;
            n1--;
            n2--;
            dsu.union_set(n1, n2);
        }else{
            cin >> n1;
            n1--;
            cout << dsu.size[dsu.find_set(n1)] << '\n';
        }
    }
}