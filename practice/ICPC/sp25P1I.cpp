#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    if(n%2 == 1){
        cout << "still running";
        return 0;
    }
    int a,b;
    int sum = 0;
    for(int i = 0; i < n; i += 2){
        cin >> a >> b;
        sum += b-a;
    }
    cout << sum;

}
