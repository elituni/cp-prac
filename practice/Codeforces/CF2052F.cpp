#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int t, n;
    string l1, l2;
    bool none, multiple;
    cin >> t;

    for(int i = 0; i < t; i++){
        cin >> n;
        cin.ignore();
        getline(cin,l1);
        getline(cin,l2);
        // cout << "n: " << n << '\n';
        // cout << l1 << '\n' << l2 << "\n\n";
        none = false;
        multiple = false;

        if(l1[0] == '.' && l2[0] == '.'){
            l1[0] = '2';
            l2[0] = '2';
        }else if(l1[0] == '.'){
            l1[0] = '1';
        }else if(l2[0] == '.'){
            l2[0] = '1';
        }

        for(int j = 1; j < n; j++){
            if((l1[j-1] == '1' && l1[j] != '.') || (l2[j-1] == '1' && l2[j] != '.')){
                none = true;
                break;
            }
            if(l1[j] == '.' && l1[j-1] == '1'){
                l1[j] = '2';
            }
            if(l2[j] == '.' && l2[j-1] == '1'){
                l2[j] = '2';
            }
            if(l1[j] == '.' && l2[j] == '.'){
                if(l1[j-1] == '2' && l2[j-1] == '2'){
                    multiple = true;
                }
                l1[j] = '2';
                l2[j] = '2';
            }
            if(l1[j] == '.'){
                l1[j] = '1';
            }
            if(l2[j] == '.'){
                l2[j] = '1';
            }
        }
        if(l1[n-1] == '1' || l2[n-1] == '1') none = true;
        if(none) cout << "None" << '\n';
        else if(multiple) cout << "Multiple" << '\n';
        else cout << "Unique" << '\n';
    }
}