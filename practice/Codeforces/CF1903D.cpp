#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    ll n,q;
    cin >> n >> q;
    vector<ll> a(n);
    vector<ll> dig(100);
    ll largest = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        ll counter = 0;
        ll goal = 1;
        ll mask = 1;
        for(int j = 0; j < 62; j++){
            dig[counter] += max((ll)0,goal-(a[i] & mask));
            // cout << "added " << max((ll)0,goal-(a[i] & mask)) << " to " << i << '\n';
            largest = max(counter, largest);
            counter++;
            goal <<= 1;
            mask <<= 1;
            mask += 1;
        }
    }
    std::cout << "a[]: ";
    for(int i = 0; i < 4; i++){
        std::cout << a[i] << ' ';
    }
    std::cout << '\n';

    std::cout << "dig: ";
    for(int i = 0; i < 100; i++){
        std::cout << dig[i] << ' ';
    }
    std::cout << '\n';

    // std::cout << "largest: " << largest << '\n';

    for(int i = 0; i < q; i++){
        ll k;
        cin >> k;
        // while(k > dig[largest]){
        //     largest++;
        //     dig[largest] = dig[largest-1] + (1<<largest)*n;
        // }

        ll sum = 0;
        ll l = largest;
        for(; l >= 0; l--){
            if(dig[l] <= k){
                sum += (1<<l);
                k -= dig[l];
                l--;
                break;
            }
        }

        ll val = (1 << l)*n;
        for(; l>=0; l--){
            if(k >= val){
                k -= val;
                sum += (val/n);
            }
            val >>= 1;
        }

        cout << sum << '\n';
    }

    // for each binary digit, add the number of stuf u need to add to
    // get to that digit for each number
}
