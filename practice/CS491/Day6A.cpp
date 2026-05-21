#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll n, in;
    string prompt;
    cin >> n;
    //val, left, right, parent
    vector<array<ll,4>> tree;
    for(ll i = 0; i < n; i++){
        cin >> prompt >> in;
        if(prompt == "Insert"){
            if(tree.size() == 0){
                tree.push_back({in,-1,-1,-1});
            }
            else{
                ll index = 0;
                while(true){
                    if(in < tree[index][0]){
                        
                    }else{

                    }
                }
            }
        }
        if(prompt == "Delete"){
            ll index = 0;
            while(tree[index][0] != in){
                if(in < tree[index][0]){
                    index = tree[index][0];
                }else{
                    index = tree[index][1];
                }
            }
            if(tree[index][1] == -1 && tree[index][2] == -1){

            }
        }
        if(prompt == "Rank"){
            auto itr = list.lower_bound(in);
            cout << (itr-list.begin());
        }
        
    }
}