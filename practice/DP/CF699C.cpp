#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int n, curr;
    cin >> n;
    vector<vector<int>> status(n+1, vector<int>(3));
    for(int i = 1; i <= n; i++){
        cin >> curr;
        status[i][0] = max(status[i-1][1], status[i-1][2]);
        status[i][1] = status[i][0];
        status[i][2] = status[i][0];
        if(curr == 1){
            status[i][1] = status[i-1][2]+1;
        }else if(curr == 2){
            status[i][2] = status[i-1][1]+1;
        }else if(curr == 3){
            status[i][1] = status[i-1][2]+1;
            status[i][2] = status[i-1][1]+1;
        }
    }
    cout << n-max(status[n][1], status[n][2]);
}