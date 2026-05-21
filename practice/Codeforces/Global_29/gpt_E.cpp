#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using T = tuple<ll,ll,int>; // (trimmed, actual, idx)

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int MAX_BITS = 34;
    vector<ll> mask(MAX_BITS);
    for(int b=0;b<MAX_BITS;b++) mask[b] = ( (1ll<<b) - 1 );

    int t;
    if(!(cin >> t)) return 0;
    while(t--){
        int n,q;
        cin >> n >> q;
        vector<ll> arr(n);
        for(int i=0;i<n;i++) cin >> arr[i];

        // count of elements with bit b set
        vector<int> count(MAX_BITS, 0);

        // heaps per bit (max-heap by (trimmed, actual, idx))
        vector<priority_queue<T>> heaps(MAX_BITS);

        for(int i=0;i<n;i++){
            for(int b=0;b<MAX_BITS;b++){
                ll bit = 1ll<<b;
                if(arr[i] & bit) count[b]++;
                ll trimmed = arr[i] & mask[b];
                heaps[b].push( make_tuple(trimmed, arr[i], i) );
            }
        }

        int num_bits = 0;
        for(int b=0;b<MAX_BITS;b++) if(count[b] > 0) num_bits++;

        // required: start with (num_bits+1) zeros as in original code
        vector<ll> required(num_bits+1, 0);
        ll ops = 0;

        // helper to get valid top for a heap b (lazy pop until top matches current arr & trimmed)
        auto get_top_valid = [&](int b)->T{
            while(true){
                if(heaps[b].empty()){
                    // should not happen in original logic (every trim[b] had n entries)
                    return make_tuple(0ll, 0ll, -1);
                }
                T ttop = heaps[b].top();
                ll trimmed = get<0>(ttop);
                ll actual  = get<1>(ttop);
                int idx    = get<2>(ttop);

                ll curActual = arr[idx];
                ll curTrimmed = curActual & mask[b];
                if(trimmed == curTrimmed && actual == curActual){
                    return ttop; // valid
                } else {
                    heaps[b].pop(); // stale entry, discard
                }
            }
        };

        // follow original loops exactly: for each i where count[i]==0,
        // process j = i..0 and for each j with count[j]==0 take the best from trim[j]
        for(int i=0;i<MAX_BITS;i++){
            if(count[i] == 0){
                for(int j=i;j>=0;j--){
                    if(count[j] == 0){
                        // pick best candidate for bit j
                        T top = get_top_valid(j);
                        ll trimmed = get<0>(top);
                        ll actual  = get<1>(top);
                        int idx    = get<2>(top);
                        // compute new_val as original code
                        ll need = (1ll<<j) - trimmed;
                        ll new_val = max(actual + need, (1ll<<j));

                        // update all heaps (replace the element's pair in every trim[k])
                        // we use lazy-insert: push new entry for idx into heaps[k]
                        for(int k=0;k<MAX_BITS;k++){
                            // old trimmed = arr[idx] & mask[k]  (before assignment)
                            // new trimmed = new_val & mask[k]
                            ll oldTrim = arr[idx] & mask[k];
                            ll newTrim = new_val & mask[k];
                            // push new tuple (newTrim, new_val, idx) if something could differ.
                            // Even if newTrim == oldTrim and new_val==actual, pushing duplicates is safe;
                            // but we can skip the push in that identical case to reduce work.
                            if(newTrim != oldTrim || new_val != actual){
                                heaps[k].push( make_tuple(newTrim, new_val, idx) );
                            }
                            // update count[k] if k-th bit turned 1->0
                            ll bitk = 1ll<<k;
                            if( ((new_val & bitk) == 0) && ((actual & bitk) != 0) ){
                                count[k]--;
                            }
                        }

                        // commit the change to the array
                        arr[idx] = new_val;

                        ops += (1ll<<j) - trimmed;
                        count[j]++; // we've created an element with bit j set
                    }
                }
                required.push_back(ops);
            }
        }

        // answer queries: number of bits achievable with <= query ops
        for(int qi=0; qi<q; qi++){
            ll query; cin >> query;
            auto it = upper_bound(required.begin(), required.end(), query);
            int ans = int(it - required.begin() - 1);
            if(ans < 0) ans = 0;
            cout << ans << '\n';
        }
    }
    return 0;
}
