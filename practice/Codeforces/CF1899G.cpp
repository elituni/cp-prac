#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Segtree{
    //stored similarly to binary heap
    vector<int> stree;

    Segtree(int size){
        stree.resize(size*4);
        // we haven't visited anything, default is time 0
    }

    //find max visit time of the nodes in a range
    int s_max(int v, int tl, int tr, int l, int r){
        if(l>r) return false;
        if(l==tl && r==tr) return stree[v];
        int tm = (tl+tr)/2;
        return max(s_max(v*2, tl, tm, l, min(r,tm)), s_max(v*2+1, tm+1, tr, max(l,tm+1), r));
    }

    //update the tree with latest visit time for a node
    void update(int v, int tl, int tr, int pos, int time){
        //any new update will always have a later visit time than a previous update
        //so we can just set the max time of the segment to the newest one
        stree[v]=time;
        if(tl==tr) return;
        int tm = (tl+tr)/2;
        if(pos<=tm) update(v*2,tl,tm,pos,time);
        else update(v*2+1,tm+1,tr,pos,time);
    }
};

void dfs(int v, int prev, int n, int& time, vector<vector<int>>& tree, vector<int>& permutation, unordered_map<int, vector<array<int,3>>>& queries, Segtree& stree, vector<bool>& ans){
    time++;
    //store the time when we first entered the node
    //anything between this time and the latest time when we revisit the node will be a descendant
    int node_time = time;
    for(int neighbor : tree[v]){
        if(neighbor != prev)
            dfs(neighbor, v, n, time, tree, permutation, queries, stree, ans);
    }
    //update this node in the segtree
    stree.update(1,0,n-1,permutation[v],time);
    
    //answer query with segtree
    //a descendant is present if a node in the range has a more recent visit time
    for(auto [l,r,num] : queries[v]){
        ans[num] = (stree.s_max(1,0,n-1,l,r)>=node_time);
    }
}

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    for(int it = 0; it < t; it++){
        int n,q;
        cin >> n >> q;

        //store tree as a list graph
        int u,v;
        vector<vector<int>> tree(n);
        for(int ni = 0; ni < n-1; ni++){
            cin>>u>>v;
            u--; v--;
            tree[u].push_back(v);
            tree[v].push_back(u);
        }
        
        //store the index of each node in the permutation array
        int p;
        vector<int> permutation(n);
        for(int ni = 0; ni < n; ni++){
            cin >> p;
            p--;
            permutation[p] = ni;
        }

        // key = x, arr[0] = l, arr[1] = r, arr[2] = query #
        int l,r,x;
        unordered_map<int, vector<array<int,3>>> queries;
        queries.reserve(32768);
        queries.max_load_factor(0.25);
        for(int qi = 0; qi < q; qi++){
            cin >> l >> r >> x;
            l--; r--; x--;
            queries[x].push_back({l,r,qi});
        }

        //create a segtree to store the nodes that we've visited
        Segtree stree(n);
        //vector of answers to the queries
        vector<bool> ans(q);

        int time = 1;
        dfs(0,-1,n,time,tree,permutation,queries,stree,ans);

        for(int qi = 0; qi < q; qi++){
            if(ans[qi] == true) cout << "yes\n";
            else cout << "no\n";
        }
        cout<<'\n';
    }

}
