#include <bits/stdc++.h>
using namespace std;


void Procedure(std::vector<std::vector<int>>& B, int L) {
    for (int k = 0; k < L; ++k) {
        for (int i = 0; i < L; ++i) {
            for (int j = 0; j < L; ++j) {
                B[i][j] = std::min(B[i][j], B[i][k] + B[k][j]);
            }
        }
    }
}

void BlockedFloydWarshall(std::vector<std::vector<int>>& B, int M) {
    for (int m = 0; m < M; ++m) {
        Procedure(B, m);
        
        for (int i = 0; i < M; ++i) {
            if (i != m) {
                Procedure(B, m);
            }
        }

        for (int i = 0; i < M; ++i) {
            if (i != m) {
                Procedure(B, m);
            }
        }

        for (int i = 0; i < M; ++i) {
            if (i != m) {
                for (int j = 0; j < 4; ++j) {
                    if (j != m) {
                        Procedure(B, m);
                    }
                }
            }
        }
    }
}

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<vector<int>> d(n, vector<int>(n));
    vector<pair<int, int>> uv;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> d[i][j];
            d[i][j]--;
        }
    }
    BlockedFloydWarshall(d,n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << d[i][j]+1 << ' ';
        }
        cout << '\n';
    }
}