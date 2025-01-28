#include <vector>
#include <iostream>
using namespace std;


struct Dsu{
    vector<int> parent;
    vector<int> size;
    int numSets;
    Dsu(int n){
        numSets = n;
        parent.resize(n);
        size.resize(n);
        for(int i = 0; i < n; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }
    int find_set(int v){
        if(parent[v] == v){
            return v;
        }
        return parent[v] = find_set(parent[v]);
    }
    void union_set(int a, int b){
        a = find_set(a);
        b = find_set(b);
        if(a != b){
            numSets--;
            if(size[a] < size[b]){
                parent[b] = a;
                size[a] += size[b];
            }else{
                parent[a] = b;
                size[b] += size[a];
            }
        }
    }
};

int main(){
    int n;
    int m;
    cin >> n >> m;
    // cout << "n: " << n << "   m: " << m << endl;
    vector<vector<int> > threads(m, vector<int>(2));
    for(int i = 0; i < m; i++){
        cin >> threads[i][0] >> threads[i][1];
        threads[i][0]--;
        threads[i][1]--;
    }


    // for (vector<int> num : threads) {
    //     cout << num[0] << "," << num[1] << "  ";
    // }
    // cout << endl;

    int q;
    cin >> q;
    vector<int> cuts(q);
    vector<bool> cutted(m, false);
    for(int i = 0; i < q; i++){
        int del;
        cin >> del;
        del--;
        cuts[i] = del;
        cutted[del] = true;
    }

    // for (int num : cutted) {
    //     cout << num << " ";
    // }
    // cout << endl;

    // for (int num : cuts) {
    //     cout << num << " ";
    // }
    // cout << endl;

    Dsu sets(n);
    // cout << "numsets: " << sets.numSets << endl;
    for(int i = 0; i < m; i++){
        if(cutted[i] != true){
            sets.union_set(threads[i][0], threads[i][1]);
        }
    }


    vector<int> numSets(q);
    numSets[0] = sets.numSets;
    for(int i = q-1; i>0; i--){
        sets.union_set(threads[cuts[i]][0], threads[cuts[i]][1]);
        numSets[q-i] = sets.numSets;
    }

    for(int i = q-1; i >= 0; i--){
        cout << numSets[i] << ' ';
    }
}