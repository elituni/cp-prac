#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll t;
    cin >> t;
    for(ll ti = 0; ti < t; ti++){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int ni = 0; ni < n; ni++){
            cin >> a[ni];
        }
        vector<int> mex(n);
        unordered_set<int> seen;
        seen.reserve(n); 

        int nonzero = 0;
        int smallest = 0;
        for(int ni = n-1; ni >= 0; ni--){
            mex[ni] = smallest;
            seen.insert(a[ni]);
            if(smallest == a[ni]){
                do{
                    smallest++;
                }while(seen.contains(smallest));
            }
            if(a[ni] != 0) nonzero++;
        }

        bool suitablezero = false;

        for(int ni = 0; ni < n; ni++){
            if(a[ni] == 0){
                suitablezero = true;
                break;
            }
            if(mex[ni] > a[ni]){
                break;
            }
        }

        if(suitablezero){
            nonzero++;
        }
        cout << nonzero << '\n';
    }
}