#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int cases, add, subtract, in;
    ll sum;
    while(cin >> add >> subtract){
        sum = 0;
        for(int j = 0; j < add; j++){
            cin >> in;
            sum += in;
        }
        for(int j = 0; j < subtract; j++){
            cin >> in;
            sum -= in;
        }
        cout << sum << '\n';
    }
}