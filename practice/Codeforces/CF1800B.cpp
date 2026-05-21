#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    ll t;
    cin >> t;
    for(ll ti = 0; ti < t; ti++){
        int n,k;
        cin >> n >> k;
        string s;
        cin >> s;
        vector<int> a(128);
        ll num = 0;
        for(int i = 0; i < n; i++){
            if(s[i] >= 'a'){
                if(a[s[i]-'a'+'A'] > 0){
                    a[s[i]-'a'+'A']--;
                    num++;
                }else{
                    a[s[i]]++;
                }
            }else{
                if(a[s[i]+'a'-'A'] > 0){
                    a[s[i]+'a'-'A']--;
                    num++;
                }else{
                    a[s[i]]++;
                }
            }
        }
        // for(int i = 0; i < 128; i++){
        //     cout << a[i] << ' ';
        // }
        // cout << '\n';
        for(int i = 0; i < 128; i++){
            if(k <= 0){
                num += k;
                break;
            }
            k -= a[i]/2;
            num += a[i]/2;
        }
        cout << num << '\n';
    }
}