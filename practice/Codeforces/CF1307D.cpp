/*
- bfs from both start and end
- we want to maximize min(start[i]+end[j],start[j],end[i]) for any pair of fields i,j, i!=j
- sort start
    - traverse through start backwards, adding elements to a priorityqueue (big to small) of ends that you've seen before
- at the end, take the min of the original bfs path and the path that includes a special
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int n,m,k;
    cin>>n>>m>>k;

    vector<int> special;
    // special.reserve(1024);
    // special.max_load_factor(0.25);

    int input;
    for(int ki = 0; ki < k; ki++){
        cin >> input;
        special.push_back(input-1); 
    }

    vector<vector<int>> g(n);

    int a,b;
    for(int mi = 0; mi < m; mi++){
        cin >> a >> b;
        g[a-1].push_back(b-1);
        g[b-1].push_back(a-1);
    }


    vector<int> start(n);
    start[0] = 0;
    vector<int> end(n);
    end[n-1] = 0;

    vector<bool> vis(n);

    queue<int> q;
    q.push(0);
    vis[0] = true;
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        for(int v : g[curr]){
            if(!vis[v]){
                start[v] = start[curr]+1;
                q.push(v);
                vis[v] = true;
            }
        }
    }


    vis = vector<bool>(n);
    vis[n-1] = true;
    q.push(n-1);
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        for(int v : g[curr]){
            if(!vis[v]){
                end[v] = end[curr]+1;
                q.push(v);
                vis[v] = true;
            }
        }
        // cout << "visit " << curr << '\n';
    }

    // for(int i = 0; i < n; i++){
    //     cout << start[i] << ' ';
    // }
    // cout << '\n';

    // for(int i = 0; i < n; i++){
    //     cout << end[i] << ' ';
    // }
    // cout << '\n';

    vector<pair<int,int>> s;
    for(int spec : special){
        s.push_back({start[spec],spec});
    }
    sort(s.begin(),s.end());

    // for(int i = 0; i < k; i++){
    //     cout << s[i].first << ',' << s[i].second << "  ";
    // }
    // cout << '\n';

    priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::less<std::pair<int, int>>> e;
    e.push({end[s[k-1].second],s[k-1].second});
    int max_dist = -1;
    for(int si = k-2; si >= 0; si--){
        max_dist = max(max_dist,s[si].first+e.top().first+1);
        // cout << "push:" <<end[s[si].second]<<" " << s[si].second << '\n';
        e.push({end[s[si].second],s[si].second});
        // cout << "a:" << s[si].second << " b:" << e.top().second << " max:" << s[si].first+e.top().first << '\n';
    }
    int sol = min(start[n-1],max_dist);
    cout << sol << '\n';
}

