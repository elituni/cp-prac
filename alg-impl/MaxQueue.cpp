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

