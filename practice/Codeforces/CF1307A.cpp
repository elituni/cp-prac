#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    for(int ti = 0; ti < t; ti++){
        int n,x;
        cin >> n >> x;

        bool nvm = false;
        int large = 0;
        int in;
        for(int ni = 0; ni < n; ni++){
            cin >> in;
            if(in == x) nvm = true;
            large = max(large, in);
        }
        int out;
        if(x == 0) out = 0;
        else if(nvm) out = 1;
        else if(x > 0 && x < large) out = 2;
        else{
            out = x/large;
            if(x%large != 0) out++;
        }
        cout << out << '\n';
    }
}

// 0 = 0
// (0,3) = 2
// 3 = 1
// (3,6] = 2
// (6,9] = 3
// (9,12] = 4



