#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n,k;
    unordered_map<string,int> freq;
    cin >> n >> k;
    string str;
    getline(std::cin, str);
    for(int ki = 0; ki < k; ki++){
        getline(std::cin, str);
        int idx = 0;
        while(idx+3 < str.size() && str[idx+3] == ' '){
            idx += 4;
        }
        // cout  << "str.substr(idx): " << str.substr(idx) << '\n';
        freq[str.substr(idx)] = max(freq[str.substr(idx)], idx/4+1);
    }
    int total = 0;
    int count = 0;
    for(auto [key,val] : freq){
        // cout << "key,val: " << key << ' ' << val << '\n';
        total += val;
        count++;
    }
    // cout << "total: " << total << '\n';
    // cout << "count: " << count << '\n';
    if(n < total){
        cout << "NO\n";
    }else{
        cout<< "YES\n";
    }

}