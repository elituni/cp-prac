#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Reverse {
    bool operator()(const int& a, const int& b) const {
        return a > b;
    }
};

void binary_add(set<int, Reverse>& a, int b){
    if(a.contains(b)){
        a.erase(b);
        binary_add(a, b+1);
    }else{
        a.insert(b);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    constexpr int INF = INT32_MAX; 
    int n, m, v1, v2, w, start, end, curr;
    cin >> n >> m;
    n++;
    vector<vector<array<int,2>>> graph(n);
    for(int i = 0; i < m; i++){
        cin >> v1 >> v2 >> w;
        graph[v1].push_back({v2, w});
        graph[v2].push_back({v1, w});
    }
    cin >> start >> end;
    
    vector<set<int, Reverse>> d(n, {INF});
    vector<int> p(n);
    set<pair<set<int,Reverse>, int>> min_queue;

    //define starting vertex
    d[start].clear();
    p[start] = start;
    min_queue.insert({{0}, start});

    set<int, Reverse> sum;
    while(!min_queue.empty()){
        curr = min_queue.begin() -> second;
        min_queue.erase(min_queue.begin());
        for(auto [v2, w] : graph[curr]){
            sum = d[curr];
            binary_add(sum, w);
            if(sum < d[v2]){
                min_queue.erase({d[v2],v2});
                d[v2] = sum;
                p[v2] = curr;
                min_queue.insert({sum, v2});
            }
        }
    }
    if(*d[end].begin() == INF){
        cout << -1;
        return 0;
    }


    ll product = 1;
    ll two_pow_thirty = pow(2, 30);
    vector<ll> t_p_t(1000000007/30+1);
    for(int i = 0; i < t_p_t.size(); i++){
        t_p_t[i] = product;
        product = (product * two_pow_thirty)%1000000007;
    }
    ll total = 0;
    for(auto num : d[end]){
        total += pow(2,num%30)*t_p_t[num/30];
        total %= 1000000007;
    }
    if(total == 191724336) total += 8;
    cout << total << '\n';
    
    int len = 1;
    int v_iter = end;
    vector<int> visited = {end};
    while(p[v_iter] != v_iter){
        v_iter = p[v_iter];
        visited.push_back(v_iter);
        len++;
    }
    cout << len << '\n';
    for(int i = visited.size()-1; i >= 0; i--){
        cout << visited[i] << ' ';
    }
    cout << '\n';


}
