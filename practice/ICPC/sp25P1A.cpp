#include <bits/stdc++.h>
using namespace std;
using ll = long long;


struct Segtree{
    unordered_map<int,int> posx;
    vector<pair<int, int>> t;

    Segtree(){
        posx.max_load_factor(0.25);
        posx.reserve(32768);
        t.resize(4*posx.size());
    }

    pair<int, int> combine(pair<int, int> a, pair<int, int> b) {
        if (a.first > b.first) 
            return a;
        if (b.first > a.first)
            return b;
        return make_pair(a.first, a.second + b.second);
    }

    void build(int a[], int v, int tl, int tr) {
        if (tl == tr) {
            t[v] = make_pair(a[tl], 1);
        } else {
            int tm = (tl + tr) / 2;
            build(a, v*2, tl, tm);
            build(a, v*2+1, tm+1, tr);
            t[v] = combine(t[v*2], t[v*2+1]);
        }
    }

    pair<int, int> get_max(int v, int tl, int tr, int l, int r) {
        if (l > r)
            return make_pair(-INF, 0);
        if (l == tl && r == tr)
            return t[v];
        int tm = (tl + tr) / 2;
        return combine(get_max(v*2, tl, tm, l, min(r, tm)), 
                    get_max(v*2+1, tm+1, tr, max(l, tm+1), r));
    }

    void update(int v, int tl, int tr, int pos, int new_val) {
        if (tl == tr) {
            t[v] = make_pair(new_val, 1);
        } else {
            int tm = (tl + tr) / 2;
            if (pos <= tm)
                update(v*2, tl, tm, pos, new_val);
            else
                update(v*2+1, tm+1, tr, pos, new_val);
            t[v] = combine(t[v*2], t[v*2+1]);
        }
    }
};

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int d,s;
    cin >> d >> s;

    Segtree st;

    set<int> compress;

    map<int,set<pair<int,int>>> anti; 
    int x,y;
    for(int i = 0; i < d; i++){
        cin >> x >> y;
        anti[y].insert({x,i});
        compress.insert(x);
    }

    map<int, set<pair<int,int>>, std::greater<int>> sensor;
    int x1, x2;
    for(int i = 0; i < s; i++){
        cin >> x1 >> x2 >> y;
        sensor[y].insert({x1,x2});
        compress.insert(x1);
        compress.insert(x2);
    }

    int counter = 0;
    for(int p_x : compress){
        st.posx[p_x] = counter;
        counter++;
    }

    vector<int> death(d);
    for(auto& [key, val] : sensor){
        auto it = anti.upper_bound(key);
        while(!val.empty() && it != anti.end()){
            for (auto set_it = val.begin(); set_it != val.end();){
                auto itl = it->second.lower_bound({set_it -> first,-1});
                auto itr = it->second.upper_bound({set_it -> second,INT_MAX});
                if(itl == itr){
                    ++set_it;
                    continue;
                }
                else{
                    set_it = val.erase(set_it);
                    for(auto iter = itl; iter != itr;){
                        death[iter -> second] = key;
                        iter = it->second.erase(iter);
                    }
                }
            }
            ++it;
        }
    }
    for(int dead : death){
        cout << dead << '\n';
    }
    cout << endl;

}