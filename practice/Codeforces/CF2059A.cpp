#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int q, n, in;
    cin >> q;
    for(int i = 0; i < q; i++){
        unordered_set<int> a;
        unordered_set<int> b;
        cin >> n;
        for(int j = 0; j < n; j++){
            cin >> in;
            a.insert(in);
        }
        for(int j = 0; j < n; j++){
            cin >> in;
            b.insert(in);
        }
        if(a.size() + b.size() > 3){
            cout << "YES" << '\n';
        }else{
            cout << "NO\n";
        }
    }
    
}