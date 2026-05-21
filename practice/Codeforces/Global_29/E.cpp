/*
For each bit, keep track of:
- number of elements with that bit
- a set of elements in descending order of values & (2^n)-1
    - pair <trimmed elem, original elem>

to add the ith bit, the minimum number of operations is:
- take the largest element in the set for i 
- for every non-zero bit under that value:
    - remove the elem from the corresponding set and add <0, original elem>
    - subtract 1 from every counter corresponding to a nonzero bit
- requires 2^i-elem operations
- add 1 to the counter for this
- go down the bits and repeat for any whose counter is 0
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    const int MAX_BITS = 34;

    int t;
    cin >> t;
    for(int ti = 0; ti < t; ti++){
        int n,q;
        cin >> n >> q;
        ll input;
        vector<int> count(MAX_BITS);
        vector<multiset<pair<ll,ll>, std::greater<pair<ll,ll>>>> trim(MAX_BITS);
        for(int ni = 0; ni < n; ni++){
            cin >> input;
            for(int b = 0; b < MAX_BITS; b++){
                ll max_bit = 1ll << b;
                if((input & max_bit) != 0) count[b]++;
                trim[b].insert({input & (max_bit-1), input});
            }
        }
        // for (size_t i = 0; i < trim.size(); i++) {
        //     std::cout << "trim[" << i << "]: ";
        //     for (auto const &p : trim[i]) {
        //         std::cout << "(" << p.first << ", " << p.second << ") ";
        //     }
        //     std::cout << "\n";
        // }

        // for (size_t i = 0; i < count.size(); i++) {
        //     std::cout << count[i] << " ";
        // }
        // std::cout << "\n";

        int num_bits = 0;
        for(int elem : count){
            if(elem != 0) num_bits++;
        }
        
        //number of bits required
        vector<ll> required(num_bits+1);
        ll ops = 0;

        // find min number of operations to get 1 more bit
        for(int i = 0; i < MAX_BITS; i++){
            if(count[i] == 0){
                // find number of ops to get this one
                for(int j = i; j >= 0; j--){
                    if(count[j] == 0){
                        auto [trimmed, actual] = *trim[j].begin();
                        ll new_val = max(actual+ ((1ll<<j) - trimmed),(1ll << j));

                        for(int k = 0; k < MAX_BITS; k++){
                            ll max_bit = 1ll << k;
                            auto it = trim[k].find({actual & (max_bit-1), actual});
                            trim[k].erase(it);
                            trim[k].insert({(new_val & (max_bit-1)),new_val});
                            if((new_val & max_bit) == 0 && (actual & max_bit) != 0){
                                count[k]--;
                            }
                        }

                        ops += (1ll << j) - trimmed;
                        count[j]++;
                    }
                }
                // for (size_t i = 0; i < trim.size(); i++) {
                //     std::cout << "trim[" << i << "]: ";
                //     for (auto const &p : trim[i]) {
                //         std::cout << "(" << p.first << ", " << p.second << ") ";
                //     }
                //     std::cout << "\n";
                // }
                required.push_back(ops);
            }
        }


        // cout << "required: ";
        // for(int i = 0; i < MAX_BITS; i++){
        //     cout << required[i] << ' ';  
        // }
        // cout << '\n';

        // cout << "required size: " << required.size() << '\n';
        
        int query;
        for(int qi = 0; qi < q; qi++){
            cin >> query;
            auto above = --upper_bound(required.begin(), required.end(), query);
            cout << above-required.begin() << '\n';
        }

    }



}

/*
    auto it = ms.find(2); // Find the first occurrence of 2
        if (it != ms.end()) {
            ms.erase(it); // Erase only that specific instance
        }
*/