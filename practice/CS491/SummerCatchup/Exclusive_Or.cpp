#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Dsu{
    vector<int> parent;
    vector<int> op;
    vector<int> size;
    int numSets;
    Dsu(int n){
        numSets = n;
        parent.resize(n);
        size.resize(n);
        op.resize(n);
        for(int i = 0; i < n; i++){
            parent[i] = i;
            size[i] = 1;
            op[i]=-1;
        }
    }
    int find_set(int v){
        if(parent[v] == v){
            return v;
        }
        return parent[v] = find_set(parent[v]);
    }
    void union_set(int a, int b){
        if(b == -1 || a == -1) return;
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
    void odd_union(int a, int b){
        a = find_set(a);
        b = find_set(b);
        union_set(b,op[a]);
        union_set(a,op[b]);
        a = find_set(a);
        b = find_set(b);
        op[a] = b;
        op[b] = a;
    }
    void even_union(int a, int b){
        a = find_set(a);
        b = find_set(b);
        union_set(a,b);
        int c = find_set(a);
        if(op[a] != -1){
            union_set(op[a],op[b]);
            op[c] = find_set(op[a]);
        }else if(op[b] != -1){
            union_set(op[a],op[b]);
            op[c] = find_set(op[b]);
        }
    }
};


int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n,m;
    cin >> n >> m;

    Dsu components(n);
    Dsu colors(n);

    int x1, x2, k;
    bool same;
    bool sol = true;
    string sgarb;
    char cgarb;

    for(int mi = 0; mi < m; mi++){
        cin >> cgarb >> x1 >> sgarb >> cgarb >> x2 >> sgarb >> k;
        same = (k==0);
        x1--; x2--;

        if(components.find_set(x1) == components.find_set(x2)){
            if((colors.find_set(x1) == colors.find_set(x2)) != same){
                sol = false;
                break;
            }
        }else{
            components.union_set(x1,x2);
            if(same){
                colors.even_union(x1,x2);
            }else{
                colors.odd_union(x1,x2);
            }
        }
    }
    if(sol == false){
        cout << "NO";
    }else{
        cout << "YES";
    }



}

/*
my cope is that this works online

for each connected component, keep two sets of elements, one for color a and other for color b

when adding an edge between 2 nodes:
    if they are in the same connected component, return FALSE if the edge contradicts their set placements
    if they are in different connected components, union the sets according to the edge
*/