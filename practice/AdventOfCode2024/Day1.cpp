#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> first, second;
    int one, two;
    for(int i = 0; i < 1000; i++){
        cin >> one >> two;
        first.push_back(one);
        second.push_back(two);
    }
    sort(first.begin(), first.end());
    sort(second.begin(), second.end());
    long sum = 0;
    for(int i = 0; i < 1000; i++){
        sum += abs(first[i]-second[i]);
    }
    cout << sum << endl;

    long similarity = 0;
    for(int i = 0; i < 1000; i++){
        for(int j = 0; j < 1000; j++){
            if(first[i] == second[j])
                similarity += first[i];
        }
    }
    cout << similarity << endl;

}