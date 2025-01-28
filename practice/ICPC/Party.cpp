#include <bits/stdc++.h>
using namespace std;

struct Dsu{
    vector<int> parents;
    vector<int> size;
    vector<int> d;

    Dsu(int n){
        parents.resize(n);
        size.resize(n);
        d.resize(n);
        for(int i = 0; i < n; i++){
            parents[i] = i;
            size[i] = 1;
            d[i] = 0;
        }
    }
    int find_set(int a){
        // cout << "a: " << a << '\n';
        // cout << "parents: " << parents[a] << '\n';
        if(parents[a] != a){
            int temp = parents[a];
            // cout << "in: " << temp << '\n';
            parents[a] = find_set(parents[a]);
            d[a] += d[temp];
        }
        return parents[a];
    }
    void union_set(int a, int b){
        a = find_set(a);
        b = find_set(b);
        if(a == b) return;
        d[a] = 1;
        size[a] += size[b];
        parents[a] = b;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, manager;
    cin >> n;
    Dsu dsu(n);
    for(int i = 0; i < n; i++){
        cin >> manager;
        if(manager == -1) continue;
        manager--;
        dsu.union_set(i, manager);
        for(int i = 0; i < n; i++){
            cout << dsu.d[i] << ' ';
        }
        cout << endl;
        for(int i = 0; i < n; i++){
            cout << dsu.parents[i] << ' ';
        }
        cout << endl;
    }
    int max = 0;
    
    for(int i = 0; i < n; i++){
        dsu.find_set(i);
        // cout << "fsi: " << dsu.find_set(i) << endl;
        
        if(dsu.d[i] > max) max = dsu.d[i];
    }
    cout << max+1;
}