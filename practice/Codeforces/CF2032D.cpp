#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, n, q;
    cin >> t;
    for(int test = 0; test < t; test++){
        cin >> n;
        vector<int> p(n);
        list<int> paths = {1};
        p[1] = 0;
        bool rank1 = true;
        auto iter = paths.begin();
        for(int i = 2; i < n; i++){
            if(rank1){
                cout << "? " << 1 << ' ' << i << endl;
                cin >> q;
                if(q){
                    p[i] = 0;
                    paths.push_back(i);
                }else{
                    rank1 = false;
                    p[i] = 1;
                    paths.front() = i;
                    iter = paths.begin();
                    iter++;
                }
            }else{
                while(true){
                    if(iter == paths.end()){
                        iter = paths.begin();
                    }
                    if(paths.size() == 1){
                        p[i] = *iter;
                        *iter = i;
                        break;
                    }
                    cout << "? " << *iter << ' ' << i << endl;
                    cin >> q;
                    if(q){
                        iter = paths.erase(iter);
                    }else{
                        p[i] = *iter;
                        *iter = i;
                        iter++;
                        break;
                    }
                }
            }
        }
        cout << "! ";
        cout.flush();
        for(int i = 1; i < n; i++){
            cout << p[i] << ' ';
            cout.flush();
        }
        cout << endl;
    }

}

/*
rank 1: check everything with 1
    - insert in linkedlist if is, set p to 0
    - end and move to rank 2 if not, set p to 1, replace 1 with val
rank 2+: iterate thru linkedlist
    - if not, set p to val, update current val
    - if yes, remove from linkedlist, continue
*/