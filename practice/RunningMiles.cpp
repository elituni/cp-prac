#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;

    for(unsigned int i = 0; i < t; i++){
        int n;
        cin >> n;
        vector<int> inputs(n);
        vector<int> left_max(n);
        vector<int> right_max(n);
        for(int j = 0; j < n; j++){
            cin >> inputs[j];
        }

        int max = inputs[0]-1;
        for(int l = 1; l < n-1; l++){
            left_max[l] = max;
            if(max < inputs[l]){
                max = inputs[l];
            }
            max--;
        }

        max = inputs[n-1]-1;
        for(int r = n-1; r >= 1; r--){
            right_max[r] = max;
            if(max < inputs[r]){
                max = inputs[r];
            }
            max--;
        }

        max = 0;
        for(int m = 1; m < n-1; m++){
            int energy = left_max[m] + right_max[m] + inputs[m];
            if(energy > max)
                max =  energy;
        }
        cout << max << '\n';
    }
}