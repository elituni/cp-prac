#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll n;
    cin >> n;
    string s;
    vector<pair<bitset<32>, bitset<32>>> odd; 
    vector<pair<bitset<32>, bitset<32>>> even; 
    for(ll ni = 0; ni < n; ni++){
        cin >> s;
        bitset<32> existence;
        bitset<32> oddness;
        for(int si = 0; si < s.size(); si++){
            existence.set(s[si]-'a');
            oddness.flip(s[si]-'a');
        }
        if(s.size() & 1){
            odd.push_back({existence,oddness});
        }else{
            even.push_back({existence,oddness});
        }
    }

    unordered_map<bitset<32>,array<int,32>> m;
    m.reserve(1024); 
    m.max_load_factor(0.25); 

    ll ans = 0;
    bitset<32> helper;
    bitset<32> temp;
    for(int i = 0; i < 26; i++)
        helper.flip(i);
    
    for(int i = 0; i < odd.size(); i++){
        for(int j = 0; j < 26; j++){
            helper.reset(j);
            temp = odd[i].second ^ helper;
            if(!m.contains(temp)){
                m[temp] = array<int,32>{};
            }
            m[temp][j] += (!odd[i].first[j]);
            helper.set(j);
        }
    }
    for(int i = 0; i < even.size(); i++){
        if(m.contains(even[i].second)){
            for(int j = 0; j < 26; j++){
                if(!even[i].first[j]){
                    ans += m[even[i].second][j];
                }
            }
        }
    }
    cout << ans;
}