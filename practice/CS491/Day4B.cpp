#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool rev(array<ll,2> a, array<ll,2> b){
    return a > b;
}

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    ll n;
    cin >> n;
    vector<array<ll,2>> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i][1] >> a[i][0];
    }
    sort(a.begin(), a.end(), rev);

    ll time = 86400;
    ll s_time;
    for(int i = 0; i < n; i++){
        s_time = a[i][0]-a[i][1];
        time -= a[i][1];
        time = min(s_time, time);
    }
    cout << ((time<0) ? -1 : time);
    


}