#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, a, b;
    cin >> n >> a >> b;
    bool pass = true;

    for(int i = 0; i < n; i++){
        a *= 3;
        if((a/b==1) && (a%b != 0)){
            pass = false;
            break;
        }
        a %= b;
    }

    if(pass) cout << "YES";
    else cout << "NO";
}