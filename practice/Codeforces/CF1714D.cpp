#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int q;
    
    cin >> q;
    for(int test = 0; test < q; test++){
        string t, s;
        int n, wj = 0;
        cin >> t >> n;

        //[nextIndex, wj, pj]
        vector<array<int, 3>> next_i(t.size(), {-1, -1, -1});

        for(int i = 0; i < n; i++){
            int pj, nextpj, currIndex = 0;
            cin >> s;
            wj++;

            //populate next_i with the largest next index and corresponding wj, pj
            pj = t.find(s,0);
            while(pj != string::npos){
                nextpj = t.find(s,pj+1);
                //update values until either next occurrence of substring or length of string
                int iter_len = nextpj == string::npos ? s.size() : min(nextpj-pj,(int)s.size());
                for(int j = pj; j < pj+iter_len; j++){
                    //if current greatest index is less than j+string length, update
                    if(next_i[j][0]<(int)(pj+s.size())){
                        next_i[j][0] = pj+s.size();
                        next_i[j][1] = wj;
                        next_i[j][2] = pj+1;
                    }
                }
                pj = nextpj;
            }
        }

        int index = 0;
        bool possible = true;
        vector<array<int,2>> sol_strings;
        while(index < t.size()){
            if(next_i[index][0] == -1){
                possible = false;
                cout << -1 << '\n';
                break;
            }
            sol_strings.push_back({next_i[index][1],next_i[index][2]});
            index = next_i[index][0];
        }
        if(possible){
            cout << sol_strings.size() << '\n';
            for(auto [first, second] : sol_strings){
                cout << first << ' ' << second << '\n';
            }
        }
    }
}


/*
Storage: an array where each index stores the largest index
    a string can go to + wj + pj.

For each string:
    for each index, loop over the length of the string to
    determine if there is a substring starting at the index
    
*/