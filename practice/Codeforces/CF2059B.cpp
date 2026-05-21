#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll q, n, k;
    cin >> q;

    for(int z = 0; z < q; z++){
        cin >> n >> k;
        vector<ll> arr(n);
        for(int j = 0; j < n; j++){
            cin >> arr[j];
        }
        arr.push_back(0);

        unordered_map<ll,int> things;
        ll len = n-k+1;
        ll left = 1;
        ll right = 1;
        things.insert({arr[1],1});
        for(ll index = 1; index <= n; index++){
            ll l_bound = min(index, len) + max((ll)0,(index-len)*2);
            ll r_bound = index*2+len-2;
            if(r_bound >= n){
                cout << index << '\n';
                break;
            }
            for(int add = right+1; add <= r_bound; add++){
                if(!things.contains(arr[add])){
                    things.insert({arr[add],1});
                }else{
                    things[arr[add]]++;
                }
                right++;
            }
            for(int remove = left; remove < l_bound; remove++){
                if(--things[arr[remove]] <= 0){
                    things.erase(arr[remove]);
                }
                left++;
            }
            if(things.size() >= 2 || !things.contains(index)){
                cout << index << '\n';
                break;
            }
        }
    }

    
    
}