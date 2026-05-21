#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll abssum(int i, vector<int>& a, int n){
    ll sum = 0;
    for(; i < n; i++){
        sum += abs(a[i]);
    }
    return sum;
}

ll nsum(int i, vector<int>& a, int n){
    ll sum = 0;
    for(; i < n; i++){
        sum -= a[i];
    }
    return sum;
}


ll posfirst(int i, vector<int>& a, int n){
    int lastpos;
    int minneg = INT32_MAX;
    for(lastpos = n-1; lastpos >= i; lastpos--){
        if(a[lastpos] >= 0) break;
        minneg = min(abs(minneg), abs(a[lastpos]));
    }

    return abssum(i,a,n) - (ll) min(abs(a[lastpos]), abs(minneg));
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;

    for(int ti = 0; ti < t; ti++){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int ni = 0; ni < n; ni++){
            cin >> a[ni];
        }
        if(a[0] >= 0){
            cout << posfirst(0, a, n) << '\n';
        }else{
            int i = 1;
            ll temp = 0;
            while(i < n && a[i] < 0){
                temp += abs(a[i]);
                i++;
            }
            cout << temp + max(nsum(i,a,n), posfirst(i,a,n)+a[0]) << '\n';
        }
    }



}
//if first number positive and last number negative, answer = abs sum of middle n-2 + max(first, last)
//if first number and last number positive, answer = abs sum, of first n-1
//if first number negative, then answer is either last n-1 sum 
    // or first number + previous two cases
