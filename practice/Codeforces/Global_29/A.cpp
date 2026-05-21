#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int t;
    cin >> t;
    int x,y;
    for(int ti = 0; ti < t; ti++){
        cin >> x >> y;
        if((x == 0 && y != 0) || (y == 1) || x == y || (x > y && abs(x-y) < 2)){
            cout << "-1" << '\n';
        }
        else if(x==0 && y == 0){
            cout << "0" << '\n';
        }
        else if(y == 0 && x != 0){
            cout << "1" << '\n';
        }
        else if(x < y){
            cout << "2" << '\n';
        }else{
            cout << "3" << '\n';
        }
    }

}

// if x <= 0 fail
// if y <= 1 fail
// if x == y fail
// if x>y and |x-y| < 2 fail


