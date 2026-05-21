#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    int n;
    string s;
    for(int ti = 0; ti < t; ti++){
        bool in_chain = false;
        bool possible = true;
        cin >> n >> s;
        int count = 0;
        int i = 0;
        if(s[0] == '1'){
            while(i < n-1 && s[i] == '1') i++;
            in_chain = true;
        }
        for(; i < n-1; i++){
            if(!in_chain){
                if(s[i] == '1' && s[i+1] == '1'){
                    while(i < n-1 && s[i+1] == '1') i++;
                    in_chain = true;
                }
                count = 0;
            }else{
                if(s[i] == '0' && s[i+1] == '1'){
                    count++;
                    i++;
                    continue;
                }else if(s[i] == '0' && s[i+1] == '0'){
                    count = 0;
                    i++;
                    in_chain = false;
                    continue;
                }else if(s[i] == '1'){
                    if(count % 2 == 1) possible = false;
                    in_chain = false;
                }
            }
        }
        if(in_chain && count % 2 == 1 && s[n-1] != '0') possible = false;
        if(possible == true){
            cout << "YES" << '\n';
        }else{
            cout << "NO\n";
        }
    }
}

/*
all we care about is 11 (01)* 011

*/