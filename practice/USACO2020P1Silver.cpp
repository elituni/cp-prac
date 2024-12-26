#include <bits/stdc++.h>
using namespace std;

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
        if(parents[a] == a) return a;
        return parents[a] = find_set(parents[a]);
    }
    void union_set(int a, int b){
        a = find_set(a);
        b = find_set(b);
        if(size[a] > size[b]) swap(a, b);
        parents[b] = a;
        size[a] += size[b];
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> cows(n);
    vector<vector<int>> portals(m, vector<int>(3));

    bool sorted = true;
    for(int i = 0; i < n; i++){
        cin >> cows[i];
        cows[i]--;
        if(cows[i] != i) sorted = false;
    }
    if(sorted){
        cout << -1;
        return 0;
    }

    for(int i = 0; i < m; i++){
        cin >> portals[i][1] >> portals[i][2] >> portals[i][0];
        portals[i][1]--; portals[i][2]--;
    }
    sort(portals.begin(), portals.end());


    Dsu dsu(n);
    bool sortable;
    for(int i = m-1; i >= 0; i--){
        dsu.union_set(portals[i][1], portals[i][2]);
        sortable = true;
        for(int j = 0; j < n; j++){
            if(dsu.find_set(cows[j]) != dsu.find_set(dsu.parents[j])){
                sortable = false;
                break;
            }
        }
        if(sortable){
            cout << portals[i][0];
            break;
        }
    }
}

