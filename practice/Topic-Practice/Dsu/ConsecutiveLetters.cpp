#include <bits/stdc++.h>
using namespace std;

struct Dsu{
    vector<int> parents;
    vector<int> size;
    Dsu(int max){
        parents.resize(max);
        size.resize(max);
        for(int i = 0; i < max; i++){
            parents[i] = i;
            size[i] = 1;
        }
    }
    int find_set(int a){
        if(parents[a] == a) return a;
        return parents[a] = find_set(parents[a]);
    }
    void union_set(int a, int b){
        a = find_set(a);
        b = find_set(b);
        if(size[a] > size[b]) swap(a, b);
        parents[b] = a;
        size[a] += size[b];
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T, Q, type, index;
    string S;
    string final_S;
    cin >> T;
    int case_counter = 1;
    for(int test = 0; test < T; test++){
        cin >> S >> Q;
        final_S = S;
        int a, b;
        stack<pair<int, int>> queries;
        for(int i = 0; i < Q; i++){
            cin >> a >> b;
            if(a == 2){
                final_S[b] = '#';
            }
            queries.push(make_pair(a, b));
        }

        Dsu dsu(final_S.size());
        for(int i = 1; i < final_S.size(); i++){
            if(final_S[i] != '#' && final_S[i] == final_S[i-1]) 
                dsu.union_set(i, i-1);
        }

        stack<int> ans;
        // cout << "Queries: \n";
        while(!queries.empty()){
            pair<int, int> curr = queries.top();
            // cout << curr.first << ' ' << curr.second << '\n';
            queries.pop();
            if(curr.first == 1){
                ans.push(dsu.size[dsu.find_set(curr.second)]);
            }else{
                final_S[curr.second] = S[curr.second];
                if(curr.second-1 >= 0 && final_S[curr.second-1] == final_S[curr.second]){
                    dsu.union_set(curr.second, curr.second-1);
                }
                if(curr.second+1 < final_S.size() && final_S[curr.second+1] == final_S[curr.second]){
                    dsu.union_set(curr.second, curr.second+1);
                }
            }

        }
        cout << "Case " << case_counter << ":\n";
        case_counter++;
        while(!ans.empty()){
            cout << ans.top() << '\n';
            ans.pop();
        }
    }
    
}

/*
go thru queries, make a second string with #s
save queries
make a dsu, with each consecutive group of numbers as one set
go through queries backwards, saving the outputs as we go and union when a # is removed.
*/
