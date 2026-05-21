#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, k, l1, l2;
    cin >> n >> k >> l1 >> l2;

    vector<int> x(l1);
    vector<int> y(l2);
    vector<int> x_max;
    vector<int> y_max;
    
    for(int i = 0; i < l1; i++){
        cin >> x[i];
    }
    for(int i = 0; i < l2; i++){
        cin >> y[i];
    }

    sort(x.begin(), x.end(), [] (const int a, const int b){return a > b;});
    sort(y.begin(), y.end(), [] (const int a, const int b){return a > b;});

    for(int i = 0; i < l1; i++){
        cout << x[i];
    }
    cout << '\n';
    for(int i = 0; i < l2; i++){
        cout << y[i];
    }
    cout << '\n';

    int total = 0;
    int points = 0;
    while(true){
        int x_index = 0;
        int y_index = 0;

        
        
    }
}