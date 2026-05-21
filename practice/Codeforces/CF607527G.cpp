#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int tests;
    cin >> tests;

    for(int i = 0; i < tests; i++){
        int len;
        cin >> len;

        vector<pair<int,int>> input(len);

        for(int j = 0; j < len; j++){
            cin >> input[j].first;
        }
        for(int j = 0; j < len; j++){
            cin >> input[j].second;
        }

        int num_swaps = 0;
        bool trivial_swap = len%2;
        for(int j = 0; j < len; j++){
            if(input[j].first > input[j].second){
                swap(input[j].first, input[j].second);
                num_swaps++;
            }
            if(input[j].second-input[j].first == 1){
                trivial_swap = true;
            }
        }

        if(num_swaps%2==1 && trivial_swap==false){
            cout << "NO\n";
            continue;
        }

        std::sort(input.begin(), input.end());

        bool sortable = true;
        for(int j = 1; j < len; j++){
            if(input[j-1].second > input[j].second){
                sortable = false;
                break;
            }
        }
        if(sortable){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }

}