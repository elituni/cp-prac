
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    ll t;
    cin >> t;
    for(ll ti = 0; ti < t; ti++){
        ll x,n,m;
        cin>>x>>n>>m;
        ll minn = n; ll minm = m;
        ll min = x;
        ll counter = 0;
        while(n + m > 0){
            if(x == 0) break;
            if(x == 1 && n != 0){
                x=0;
                break;
            }
            if(n == 0 || (m!=0 && x%2==1)){
                x = (x+1)/2;
                m--;
            }else{
                x /= 2;
                n--;
            }
            // counter++;
            // cout << counter << '\n';
        }
        while(minn + minm > 0){
            if(min == 0) break;
            if(min==1 && minn == 0){

                break;
            }
            if(minm == 0 || (minn!=0 && min%2==1)){
                min/=2;
                minn--;
            }else{
                min = (min+1)/2;
                minm--;
            }
            // counter++;
            // cout << counter << '\n';
        }
        cout << min << ' ' << x << '\n';
    }
}