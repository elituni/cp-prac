#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int t, n;
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> n;
        vector<int> vec(n);
        for(int j=0; j < n; j++){
            cin >> vec[j];
        }
        sort(vec.begin(), vec.end());
        cout << vec[n-1]+vec[n-2]-vec[0]-vec[1] << '\n';

    }



}
