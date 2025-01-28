#include <bits/stdc++.h>
using namespace std;

struct MaxQueue{
    stack<pair<int,int>> in;
    stack<pair<int,int>> out;

    void push(int val){
        in.push({val, in.empty() ? val : std::max(val,in.top().second)});
    }
    void pop(){
        if(empty()) throw runtime_error("pop from empty queue");
        if(out.empty()){
            int max = 0;
            while(!in.empty()){
                max = std::max(in.top().first,max);
                out.push({in.top().first, max});
                in.pop();
            }
        }
        out.pop();
    }
    int max(){
        if(empty()) throw runtime_error("pop from empty queue");
        if(in.empty() || out.empty()){
            return in.empty() ? out.top().second : in.top().second;
        }else{
            return std::max(in.top().second, out.top().second);
        }
    }
    bool empty(){
        return in.empty() && out.empty();
    }
};

vector<int> solve(vector<int> arr, vector<int> queries) {
    vector<int> sol;
    for(int query : queries){
        MaxQueue q;
        for(int i = 0; i < query; i++){
            q.push(arr[i]);
        }
        int min = q.max();
        for(int i = query; i < arr.size(); i++){
            q.push(arr[i]);
            q.pop();
            min = std::min(min, q.max());
        }
        sol.push_back(min);
    }
    return sol;
}
