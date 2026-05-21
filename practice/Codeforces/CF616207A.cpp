#include <bits/stdc++.h>
using namespace std;


int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int t, n;
    char d;
    cin >> t;
    for(int ti = 0; ti < t; ti++){
        cin >> n >> d;
        bool inserted = false;
        char in;
        for(int i = 0; i < n; i++){
            cin >> in;
            if(!inserted && in < d){
                cout << d;
                inserted = true;
            }
            cout << in;
        }
        if(!inserted) cout << d;
        cout << '\n';
    }

}