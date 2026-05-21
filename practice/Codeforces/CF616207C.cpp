#include <bits/stdc++.h>
using namespace std;


int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int t, n;
    cin >> t;
    for(int it = 0; it < t; it++){
        cin >> n;
        n--;
        int prev, in;
        cin >> prev;
        cout << prev << ' ';
        for(int i = 1; i < n; i++){
            cin >> in;
            cout << min(in, prev) << ' ';
            prev = in;
        }
        cout << prev << '\n';
    }
}