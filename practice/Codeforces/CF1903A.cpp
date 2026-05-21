#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int t, k, n;
    int prev, curr;
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> k >> n;
        bool sorted = true;
        cin >> prev;
        for(int j = 1; j < k; j++){
            cin >> curr;
            if(curr < prev) sorted = false;
            prev = curr;
        }
        if(n == 1 && !sorted){
            cout << "NO\n";
        }else{
            cout << "YES\n";
        }
    }
}