#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    ll n, s;
    cin >> n >> s;

    vector<ll> input(n);
    for(ll i = 0; i < n; i++){
        cin >> input[i];
    }

    vector<ll> dp_sum;
    vector<ll> dp_index;
    ll moving_sum = 0;
    for(int r = 0; r < n; r++){
        moving_sum += input[r];
        if(moving_sum >= 0){
            dp_sum.push_back(moving_sum);
            dp_index.push_back(r);
            moving_sum = 0;
        }
    }
    for(int i = 0; i < dp_sum.size(); i++){
        cout << dp_index[i] << ' ';
    }cout << endl;

    moving_sum = 0;
    for(int i = 0; i < dp_sum.size(); i++){
        moving_sum += dp_sum[i];
        dp_sum[i] = moving_sum;
    }
    for(int i = 0; i < dp_sum.size(); i++){
        cout << dp_sum[i] << ' ';
    }cout << endl;
    
    ll total_sum = 0;
    ll rating = 0;
    ll p_index = 0;

    for(int r = 0; r < n; r++){
        total_sum += input[r];
        cout << "total: " << total_sum << endl;
        if(total_sum < s) rating++;
        if(p_index+1 < dp_index.size() && dp_index[p_index+1] < r){
            p_index++;
        }
        ll index = upper_bound(dp_sum.begin(), dp_sum.begin()+p_index, (total_sum-s))-dp_sum.begin();
        if(index < p_index) {
            rating += p_index-index;
        }
    }
    cout << rating;


    
}

/*
go thru array linearly, keeping a dp array of the next group where sum is positive, and its end index.
go thru array linearly, keeping a moving sum from the start.
    - pointer 1: the index where current sums - previous sums = is < target
    - pointer 2: the current index.

*/