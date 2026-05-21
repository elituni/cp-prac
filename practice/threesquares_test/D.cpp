#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    for(int ti = 0; ti < t; ti++){
        int n;
        cin >> n;
        vector<int> a(n);
        vector<ll> pre(n);
        ll sum = 0;
        ll in;
        for(int ni = 0; ni < n; ni++){
            cin >> in;
            a[ni] = in;
            sum += in;
            pre[ni] = sum;
        }
        bool fail = false;
        vector<int> new_a;
        while(a.size() != 1){
            new_a.clear();
            ll mid = lower_bound(pre.begin(), pre.end(), sum/2)-pre.begin();
            //check that it divides evenly
            if(mid >= pre.size() || pre[mid] != (float) sum/2){
                fail = true;
                break;
            }

            int l = 0;
            int r = mid+1;
            int lmax = *max_element(a.begin(), a.begin()+r);
            int rmax = *max_element(a.begin()+r, a.end());

            while(min(l,r) <= mid && max(l,r) < a.size()){
                if(a[l] > a[r]){
                    swap(l,r);
                    swap(lmax, rmax);
                }
                int target = a[r];
                new_a.push_back(a[r]);
                while(target > 0){
                    //make sure merge is possible in this subsection
                    if(a[l] < a[r] && a[l] < lmax/2) break;
                    target -= a[l];
                    l++;
                    //make sure the splits were even, i.e. not 4 -> 1 2 1
                    if(target > 0 && a[l] > a[l-1] && target%a[l] != 0) break;
                }
                r++;
                if(target != 0){
                    fail = true;
                    break;
                }
            }
            if(fail) break;

            swap(a,new_a);
            pre.clear();
            pre.push_back(a[0]);
            for(int i = 1; i < a.size(); i++){
                pre.push_back(a[i]+pre[i-1]);
            }
            sum = pre[pre.size()-1];
        }   
        if(fail) cout << "NO\n";
        else cout << "YES\n";
    }

}



// two sequences are the same iff for each (larger) number,
    // the corresponding block on the other half has a valid merge to that number
// target is to break this down into a single number, the maximum in the array