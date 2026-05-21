#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll n,k,m;
    cin >> n >> k >> m;

    vector<vector<int>> g(n); //size m < 250,000
    vector<int> dependents(n); //size n < 500,000
    int a,b;
    for(ll mi = 0; mi < m; mi++){
        cin >> a >> b;
        a--; b--;
        g[b].push_back(a);
        dependents[a]++;
    }

    vector<vector<int>> d(k, dependents); // size n*k < 500,000

    vector<deque<int>> v(n); // size n*k < 500,000

    
    for(int i = 0; i < n; i++){
        if(dependents[i] == 0){
            for(int j = 0; j < k; j++){
                v[i].push_back(j);
            }
        }
    }

    vector<int> l(n*k); // size n*k < 500,000
    for(ll i = n*k-1; i >=0; i--){
        cin >> l[i];
        l[i]--;
    }

    // vector<int> out; // size n*k < 500,000
    int iter = 0;
    for(int job : l){
        a = v[job].front();
        v[job].pop_front();
        for(int parent : g[job]){
            d[a][parent]--;
            if(d[a][parent] == 0){
                v[parent].push_back(a);
            }
        }
        l[iter] = a;
        iter++;
    }

    for(int i = l.size()-1; i >= 0; i--){
        cout << l[i]+1 << " ";
    }





}

/*
data: 
- a graph with connections from child to parent
- a 2d array for number of unseen dependents for each node for each run
- a map of deque for the valid runs that could be assigned to a job

algo:
- at the beginning, add all k numbers to all jobs that have 0 dependents
- traverse backwards, for each job seen:
    - pop from deque for the job and assign that number to the job
    - decrement number of unseen dependents that are connected
        - add the run to the map if # becomes 0
*/