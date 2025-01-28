#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> vec(n);
    for(int i = 0; i < n; i++){
        cin >> vec[i];
    }
    stack<pair<int,int>> r;
    vector<int> ans(n);
    for(int i = n-1; i >= 0; i--){
        while(true){
            if(r.empty()){
                ans[i] = -1;
                r.push({i,vec[i]});
                break;
            }if(vec[i] < r.top().second){
                ans[i] = r.top().first+1;
                r.push({i,vec[i]});
                break;
            }else{
                r.pop();
            }
        }
    }
    for(int i = 0; i < n; i++){
        cout << ans[i] << ' ';
    }
}

//if i < r.top; i = r.top; add i to stack
// if i > r.top; remove top until find a greater, then add.