#include <iostream>
#include <unordered_map>
using namespace std;

struct Dsu{
    unordered_map<int, int> parents;
    unordered_map<int, int> ops;
    unordered_map<int, int> depth;
    void make_set(int key, int op){
        if(!parents.count(key)){
            parents[key] = key;
            ops[key] = op;
            depth[key] = 0;
            return;
        }
    }
    int find_set(int key){
        if(key == -1) return -1;
        if(parents[key] == key) return key;
        return parents[key] = find_set(parents[key]);
    }
    void union_set(int a, int b){
        a = find_set(a);
        b = find_set(b);

        if(a == b) return;

        if(depth[a] > depth[b]){
            parents[a] = parents[b];
            depth[b]++;
        }else{
            parents[b] = parents[a];
            depth[a]++;
        }

        if(ops[a] == -1 && ops[b] != -1) ops[a] = ops[b];
        if(ops[a] != -1 && ops[b] == -1) ops[b] = ops[a];
        if(ops[a] != -1 && ops[b] != -1) union_set(ops[a], ops[b]);
    }
};

int main(){
    while(true){
        int maxlen, X;
        cin >> maxlen;
        if(maxlen == -1) break;
        cin >> X;
        Dsu dsu;
        int l, r;
        string parity;
        bool failed = false;
        int counter = 0;
        for(int i = 0; i < X; i++){
            cin >> l >> r >> parity;
            if(failed) continue;
            if(r > maxlen || l < 1){
                cout << i << endl;
                failed = true;
            }
            l--;
            if(parity == "even"){
                dsu.make_set(l, -1);
                dsu.make_set(r, -1);
                if(dsu.find_set(dsu.ops[l]) == dsu.find_set(r) || dsu.find_set(dsu.ops[r]) == dsu.find_set(l)){
                    cout << i << endl;
                    failed = true;
                }
                dsu.union_set(l, r);
            }else{
                dsu.make_set(l, r);
                dsu.make_set(r, l);

                if(dsu.find_set(l) == dsu.find_set(r) || (dsu.ops[l] != -1 && dsu.ops[r] != -1 && dsu.find_set(dsu.ops[l]) == dsu.find_set(dsu.ops[r]))){
                    cout << i << endl;
                    failed = true;
                }
                if(dsu.ops[l] == -1) dsu.ops[dsu.find_set(l)] = r;
                else if(dsu.ops[l] != -1) dsu.union_set(dsu.ops[l], r);
                if(dsu.ops[r] == -1) dsu.ops[dsu.find_set(r)] = l;
                else if(dsu.ops[r] != -1) dsu.union_set(dsu.ops[r], l);
            }
            counter++;
        }
        if(!failed){
            cout << counter << endl;
        }
    }
}