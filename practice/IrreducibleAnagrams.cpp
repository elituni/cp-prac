#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string in;
    cin >> in;
    vector<char> str(in.begin(), in.end());
    vector<ll> next_three(str.size(), -1);

    map<char, ll> in_range;
    ll left, right, last_added = 0;
    in_range[str[0]] = 0;
    while(left < next_three.size()){
        if(in_range.size() < 3){
            if(right >= str.size()) break;
            in_range[str[right]] = right;
            last_added = right;
            right++;
        }else{
            ll min = str.size();
            ll minKey;
            for(auto [key, val] : in_range){
                if(val < min){
                    min = val;
                    minKey = key;
                }
            }
            for(; left <= min; left++){
                next_three[left] = last_added;
            }
            in_range.erase(minKey);
        }
    }
    // cout << "next_three: ";
    // for(ll i = 0; i < str.size(); i++){
    //     cout << next_three[i] << ' ';
    // }
    // cout << '\n';
    
    ll q, l, r;
    cin >> q;
    for(ll i = 0; i < q; i++){
        cin >> l >> r;
        l--;
        r--;
        // cout << "substr: ";
        // for(int i = l; i <= r; i++){
        //     cout << str[i] << " ";
        // }
        // cout << '\n';
        if(l == r) cout << "Yes\n";
        else if(str[l] != str[r]) cout << "Yes\n";
        else if(next_three[l] != -1 && next_three[l] <= r) cout << "Yes\n";
        else cout << "No\n";
    }
}