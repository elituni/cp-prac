#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    for(int ti = 0; ti < t; ti++){
        int n,m,q;
        cin>>n>>m>>q;
        map<int,pair<vector<int>,ll>> pre;
        vector<int> a(n);
        for(int ni = 0; ni < n; ni++){
            cin >> a[ni];
        }

        int sq = sqrt(m);
        queue<int> queue;
        for(int mi = 1; mi <= sq; mi++){
            if(m%mi == 0){
                ll sum = 0;
                queue.push(mi/m);
                vector<int> diff(n);
                int prev = 0;
                for(int ai = 0; ai < n; ai++){
                    int curr = a[ai]%mi;
                    diff[ai] = (curr>=prev) ? curr-prev : curr+mi-prev;
                    sum += diff[ai];
                    prev = curr;
                }
                pre[mi].first = diff;
                pre[mi].second = sum;
            }
        }
        while(!queue.empty()){
            ll sum = 0;
            int mi = queue.front();
            queue.pop();
            vector<int> diff(n);
            int prev = 0;
            for(int ai = 0; ai < n; ai++){
                int curr = a[ai]%mi;
                diff[ai] = (curr>=prev) ? curr-prev : curr+mi-prev;
                sum += diff[ai];
                prev = curr;
            }
            pre[mi].first = diff;
            pre[mi].second = sum;
        }

        int in,i,x;
        for(int qi = 0; qi < q; qi++){
            cin>>in;
            i--;
            if(in == 1){
                a[i] = x;
                for(auto [key, pair] : pre){
                    int curr = a[i]%key;
                    if(i != n-1){
                        int next = a[i+1]%key;
                        pair.second -= pair.first[i+1];
                        int newdiff = (next>=curr) ? next-curr : next+key-curr;
                        pair.second += newdiff;
                        pair.first[i+1] = newdiff;
                    }
                    int prev = i==0 ? 0 : a[i-1]%key;
                    pair.second -= pair.first[i];
                    int newdiff = (curr>=prev) ? curr-prev : curr+key-prev;
                    pair.second += newdiff;
                    pair.first[i] = newdiff;
                }
            }
            else{
                cin >> x;
            }
        }




    }
}