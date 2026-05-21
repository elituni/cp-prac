#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    bool passed = false;
    ll t=0, n=0, in=0;
    cin >> t;
    for(int q = 0; q < t; q++){
        passed = false;
        cin >> n;
        unordered_set<ll> nums;
        for(int j = 0; j < n; j++){
            cin >> in;
            if(in == 0){
                passed = true;
            }
            nums.insert((in));
        }
        if(nums.size() < n || passed){
            cout << "YES" << '\n';
            continue;
        }

        vector<ll> numbers;
        for(ll num : nums){
            numbers.push_back(num);
            // cout << num << ' ';
        }
        // cout << endl;



        unordered_set<ll> sums;
        sums.insert(0);
        for(int i = 0; i < n; i++){
            unordered_set<ll> new_sums;
            for(auto sum : sums){
                // cout << sum << ' ' << numbers[i] << ' ' << sum+numbers[i] << '\n';
                if(sums.contains(sum+numbers[i]) || new_sums.contains(sum+numbers[i])){
                    passed = true;
                    break;
                }
                new_sums.insert(sum+numbers[i]);
            }
            sums.insert(new_sums.begin(), new_sums.end());
            // cout<<sums.size()<<"\n";
            if(passed){
                cout << "YES" << '\n';
                break;
            }
            new_sums.clear();
        }
        sums.clear();
        if(!passed){
            cout << "NO" << '\n';
        }
        numbers.clear();
        nums.clear();
    }
}
/*
true if:
- 0 is in {a}
- a number and its negative complement is in {a}
- a number is repeated in {a}
- any pair of two elements in {a} have a difference = another number in {a}
    or its negative complement
*/

// 2 3 6 11
// 0 2 5 11