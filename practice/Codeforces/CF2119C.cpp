

/*
for each bit:
if n is odd, an even number of 0s will = 1 and an odd number of 0s will = 0
we can have all 1s if n is odd, otherwise we must have an even number of 1s
if n is even, there must be an even number of 1s and 0s

if n is even and the base number is 1, then we need to + 2 1s
111100





*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    ll t;
    cin>>t;
    for(ll ti = 0; ti < t; ti++){
        ll n,l,r,k; 
        cin>>n>>l>>r>>k;
        if(n%2==1) cout << l << '\n';
        else{
            ll next = pow(2, ceil(log2(l+1)));
            if(next > r || n==2) cout << "-1\n";
            else if(k >= n-1) cout << next << '\n';
            else cout << l << '\n';
        }
    }
}

/*

*/