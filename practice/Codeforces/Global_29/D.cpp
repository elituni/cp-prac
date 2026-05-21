#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);


    int t;
    cin >> t;
    for(int ti = 0; ti < t; ti++){
        unordered_map<int,int> freq;
        freq.reserve(1024);
        freq.max_load_factor(0.25);
        int n;
        cin >> n;
        int a;

        ll alice = 0;
        ll bob = 0;

        ll sum = 0;
        for(int ni = 0; ni < n; ni++){
            cin >> a;
            freq[a]++;
            sum += a;
        }
        vector<int> odds;
        for(auto [key,val] : freq){
            if(key % 2 == 1){
                odds.push_back(val);
            }
        }
        sort(odds.begin(),odds.end(), std::greater<int>());
        for(int p = 0; p < odds.size(); p += 2){
            alice += odds[p];
            sum -= odds[p];
        }
        for(int p = 1; p < odds.size(); p += 2){
            bob += odds[p];
            sum -= odds[p];
        }
        if(sum%2 == 1) "WRONG \n";
        alice += sum/2;
        bob += sum/2;
        cout << alice << ' ' << bob << '\n';
    }

}