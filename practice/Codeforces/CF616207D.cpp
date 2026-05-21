#include <bits/stdc++.h>
using namespace std;


int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    array<int, 46> fib;
    int a = 1; int b = 1;
    fib[0] = 1; fib[1] = 1;
    for(int i = 2; i <= 45; i++){
        swap(a,b);
        b = a+b;
        fib[i] = b;
    }

    int t, n, x, y;
    cin >> t;
    for(int it = 0; it < t; it++){
        cin >> n >> y >> x;
        int l = 1; int r = fib[n+1];
        int pl = 1; int pr = fib[n];
        bool correct = true;
        //fix bounds
        for(int c = n-1; c >= 0; c--){
            if(x < l+fib[c]){
                r-=fib[c+1];
            }else if(x > r-fib[c]){
                l+=fib[c+1];
            }else{
                cout << "NO\n";
                correct = false;
                break;
            }
            swap(x,y);
            swap(l,pl);
            swap(r,pr);
        }
        if(correct){
            cout << "YES\n";
        }
    }
}