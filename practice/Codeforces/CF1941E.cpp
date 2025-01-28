#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;

    ll row, col, bridges, dist;

    for(ll i = 0; i < t; i++){
        cin >> row >> col >> bridges >> dist;
        if(dist >= col-2){
          int del;
          for(ll j = 0; j < row; j++){
            for(ll k = 0; k < col; k++){
                cin >> del;
            }
          }
          cout << 2*bridges << '\n';
          continue;
        }
        dist++;
        vector<vector<ll>> river(row, vector<ll>(col));
        vector<ll> row_costs(row);

        for(ll j = 0; j < row; j++){
            for(ll k = 0; k < col; k++){
                cin >> river[j][k];
                river[j][k]++;
            }
        }

        for(ll j = 0; j < row; j++){
            multiset<ll> window;
            window.insert(1);
            
            ll k = 0;
            for(k = 1; k <= dist; k++){
                river[j][k] = *window.begin() + river[j][k];
                window.insert(river[j][k]);
            }
            for(k = dist+1; k < col; k++){
                window.extract(river[j][k-dist-1]);
                river[j][k] = *window.begin()+river[j][k];
                window.insert(river[j][k]);
            }
            row_costs[j] = river[j][col-1];
        }

        if(bridges > row) bridges = row;
        ll first = 0;
        ll second = bridges;
        ll sum = 0;
        for(ll n = first; n < second; n++){
            sum += row_costs[n];
        }
        ll min = sum;
        for(ll n = second; n < row; n++){
            sum += row_costs[n];
            sum -= row_costs[first];
            first++;
            if(min > sum){
                min = sum;
            }
        }
        cout << min << '\n';
    }
}