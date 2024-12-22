#include <vector>
#include <iostream>
using namespace std;


struct Dsu{
    vector<int> next_uncolored;
    vector<int> colors;

    Dsu(int max){
        max+=2;
        next_uncolored.resize(max);
        colors.resize(max);
        for(unsigned int i = 0; i < max; i++){
            next_uncolored[i] = i;
            colors[i] = 0;
        }
    }
    int find_next(int index){
        if(next_uncolored[index] == index) return index;
        return next_uncolored[index] = find_next(next_uncolored[index]);
    }
    void color_range(int l, int r, int c){
        int next = find_next(r+1);
        while(l <= r){
            if(colors[l] != 0){
                l = find_next(l);
                continue;
            }
            colors[l] = c;
            next_uncolored[l] = next;
            l++;
        }
    }
};

int main(){
    int n, q;
    cin >> n >> q;
    int l, r, c;
    vector<vector<int>> queries(q, vector<int>(3));
    for(unsigned int i = 1; i <= q; i++){
        cin >> l >> r >> c;
        queries[q-i][0] = l;
        queries[q-i][1] = r;
        queries[q-i][2] = c;
    }
    Dsu dsu(n);
    for(unsigned int i = 0; i < q; i++){
        dsu.color_range(queries[i][0], queries[i][1], queries[i][2]);
    }
    for(unsigned int i = 1; i <= n; i++){
        cout << dsu.colors[i] << endl;
    }
}


