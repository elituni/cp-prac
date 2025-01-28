#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> k(n);
    for(int i = 0; i < n; i++){
        cin >> k[i];
    }
    
    sort(k.begin(), k.end());
    int i = 0, counter = 0;
    for(int j = (n+1)/2; j < n; j++){
        if(k[i] <= k[j]/2){
            counter++;
            i++;
        }
    }
    cout << n-counter;
}