#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void countDays(vector<ll>& vec, int len, ll& lim, ll& sum, int l, int r){
    // // cout << "bounds: "<< l << '-' << r <<'\n';
    // if(r-l == 1){
    //     if(vec[r]-vec[l] < lim){
    //         // cout << "add l:" << l << " r:" << r << endl;
    //         sum += 1;
    //     }
    //     return;
    // }
    // int mid = (r+l)/2;
    // countDays(vec,len,lim,sum,l,mid);
    // countDays(vec,len,lim,sum,mid,r);
    // cout << "bounds: "<< l << '-' << r << "+" << mid <<'\n';
    // for(int i = l; i <= r; i++){
    //     cout << vec[i] << ' ';
    // }
    // cout << '\n';
    // vector<ll> temp;
    // int l_iter = l;
    // int r_iter = mid+1;
    // while(true){
    //     if(l_iter == mid && r_iter == r+1) break;
    //     if(l_iter == mid){
    //         r_iter++;
    //     }else if(r_iter == r+1){
    //         // cout << "add "<<(r_iter-mid-1)<<'\n';
    //         l_iter++;
    //         sum += (r_iter-mid-1);
    //     }else{
    //         if(vec[r_iter]-vec[l_iter] < sum){
    //             r_iter++;
    //         }else{
    //             cout << "r_iter " << r_iter << " l_iter" << l_iter << '\n';
    //             l_iter++;
    //             cout << "add "<<(r_iter-mid-1)<<'\n';
    //             sum += (r_iter-mid-1);
    //         }
    //     }
    // }
    // l_iter = l;
    // r_iter = mid;
    // while(true){
    //     if(l_iter == mid && r_iter == r) break;
    //     if(l_iter == mid){
    //         temp.push_back(vec[r_iter]);
    //         r_iter++;
    //     }else if(r_iter == r){
    //         temp.push_back(vec[l_iter]);
    //         l_iter++;
    //     }else{
    //         if(vec[r_iter]-vec[l_iter] < 0){
    //             temp.push_back(vec[r_iter]);
    //             r_iter++;
    //         }else{
    //             temp.push_back(vec[l_iter]);
    //             l_iter++;
    //         }
    //     }
    // }
    // for(ll t : temp){
    //     vec[l] = t;
    //     l++;
    // }
}

//array, s, left bound (inclusive), right bound (inclusive)
void inv(vector<ll>& arr, const ll& s, const ll& l, const ll& r, ll& sum){
    if(l == r){
        if(arr[r]-arr[l-1] < s){
            sum++;
        }
        return;
    }
    ll mid = (l+r)/2;
    inv(arr,s,l,mid,sum);
    inv(arr,s,mid+1,r,sum);

    //add inversions
    ll lp = l;
    ll rp = mid+1;
    while(lp <= mid){
        while(rp <= r && arr[rp]-arr[lp-1]<s){
            rp++;
        }
        lp++;
        sum += rp-(mid+1);
    }

    ll lp = l;
    ll rp = mid+1;
    

}

int main(){
    ll lim;
    int len;
    cin >> len >> lim;
    vector<ll> vec(len+1);
    ll in, sum = 0;
    vec[0] = 0;
    for(int i = 1; i <= len; i++){
        cin >> in;
        sum += in;
        vec[i] = sum;
    }
    cout << "vec: ";
    for(int i = 0; i < vec.size(); i++){
        cout << vec[i] << ' ';
    }
    cout << "\n\n";
    ll totalDays = 0;
    int l = 0;
    int r = len;
    countDays(vec, len, lim, totalDays, l, r);
    cout << "vec: ";
    for(int i = 0; i < vec.size(); i++){
        cout << vec[i] << ' ';
    }
    cout << totalDays;
   
}