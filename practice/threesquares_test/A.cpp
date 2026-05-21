#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;

    for(int ti = 0; ti < t; ti++){
        int c = 0;
        string s;
        cin >> s;
        int n = s.size();
        if(s[n-1] == 'u'){
            c++;
            s[n-1] = 's';
        }
        if(s[0] == 'u'){
            c++;
            s[0] = 's';
        }

        for(int j = 0; j < n; j++){
            int r_l = 0;
            while(s[j] == 'u'){
                j++;
                r_l++;
            }
            c += r_l/2;
        }
        cout << c << '\n';
    }


}