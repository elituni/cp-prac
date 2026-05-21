#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Dsu{
    vector<bool> enough;
    vector<int> parents;
    vector<int> rank;

    Dsu(int n){
        parents.resize(n);
        rank.resize(n);
        enough.resize(n);
        for(int i = 0; i < n; i++){
            enough[i] = false;
            parents[i] = i;
            rank[i] = 0;
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
        if(rank[a] < rank[b]) swap(a,b);
        parents[b] = a;
        if(rank[a] == rank[b]){
            rank[a]++;
        }
    }
};

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int n, q, l;
    cin >> n >> q >> l;
    int input;
    int total = 0;
    vector<int> lengths(n);
    Dsu dsu(n);
    for(int i = 0; i < n; i++){
        cin >> input;
        lengths[i] = input;
        int addition = 1;
        if(input > l){
            dsu.enough[i] = true;
            if(i != 0 && dsu.enough[dsu.find_set(i-1)]){
                dsu.union_set(i,i-1);
                addition--;
            }
            if(i != n-1 && dsu.enough[dsu.find_set(i+1)]){
                dsu.union_set(i,i+1);
                addition--;
            }
            total += addition;
        }
    }
    int index, len;
    for(int i = 0; i < q; i++){
        cin >> input;
        if(input == 0){
            cout << total << '\n';
        }else{
            cin >> index >> len;
            index--;
            if(lengths[index] > l) continue;
            lengths[index] += len;
            if(lengths[index] > l){
                dsu.enough[index] = true;
                int addition = 1;
                if(index != 0 && dsu.enough[dsu.find_set(index-1)]){
                    dsu.union_set(index,index-1);
                    addition--;
                }
                if(index != n-1 && dsu.enough[dsu.find_set(index+1)]){
                    dsu.union_set(index,index+1);
                    addition--;
                }
                total += addition;
            }
        }
    }
}