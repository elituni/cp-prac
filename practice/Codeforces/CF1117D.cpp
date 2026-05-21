#include <bits/stdc++.h>
using namespace std;
using ll = long long;


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

void vec_matr_mult(vector<vector<ll>>& mat, vector<ll>& vec, ll& m){
    vector<ll> temp = vec;
    for(int i = 0; i < m; i++){
        ll sum = 0;
        for(int j = 0; j < m; j++){
            sum += temp[j]*mat[i][j];
            sum %= 1000000007;
        }
        vec[i] = sum;
    }
}

int main(){
    ll n,m;
    cin >> n >> m;

    vector<vector<ll>> mat(m, vector<ll>(m));
    mat[0][0] = 1; mat[0][m-1] = 1;
    for(int i = 1; i < m; i++){
        mat[i][i-1] = 1;
    }

    vector<ll> vec(m);
    vec[0] = 1;
    
    while(n > 0){
        if(n&1) vec_matr_mult(mat, vec, m);
        matrix_sq(mat,m);
        n>>=1;
    }
    cout << vec[0];
}