#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void matrix_mult(vector<vector<ll>>& base_mat, vector<vector<ll>>& sol, ll& m){
    vector<vector<ll>> temp = sol;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < m; j++){
            ll sum = 0;
            for(int k = 0; k < m; k++){
                sum += base_mat[i][k]*temp[k][j];
                sum %= 1000000007;
            }
            sol[i][j] = sum;
        }
    }
}

void matrix_sq(vector<vector<ll>>& base_mat, ll& m){
    vector<vector<ll>> temp = base_mat;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < m; j++){
            ll sum = 0;
            for(int k = 0; k < m; k++){
                sum += temp[i][k]*temp[k][j];
                sum %= 1000000007;
            }
            base_mat[i][j] = sum;
        }
    }

}

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    ll n, m, k;
    cin >> n >> m >> k;
    n--;

    char a, b;
    vector<vector<ll>> base_mat(m, vector<ll>(m, 1));
    for(int del = 0; del < k; del++){
        cin >> a >> b;
        a < 'a' ? a-=('A'-26) : a-='a';
        b < 'a' ? b-=('A'-26) : b-='a';
        base_mat[b][a] = 0;
    }

    vector<vector<ll>> sol(m,vector<ll>(m));
    for(int i = 0; i < m; i++){
        sol[i][i] = 1;
    }
    while(n != 0){
        if(n&1){
            matrix_mult(base_mat,sol,m);
        }
        matrix_sq(base_mat,m);
        n>>=1;
    }
    ll total = 0;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < m; j++){
            total += sol[i][j];

        }
    }
    total %= 1000000007;
    cout << total;
}