#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    string s;
    cin >> s;
    vector<int> c;
    int largest = 0;
    vector<int> pre()
    for(int i = 0; i < s.size(); i++){
        c[s[i]]++;
        if(c[s[i]] > largest) largest = c[s[i]];

    }

}