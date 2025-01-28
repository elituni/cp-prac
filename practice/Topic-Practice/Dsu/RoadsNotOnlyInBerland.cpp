#include <vector>
#include <iostream>
#include <unordered_set>
using namespace std;

struct Dsu{
    vector<vector<int> > useless_roads;
    vector<int> parents;
    vector<int> size;
    Dsu(int max){
        parents.resize(max);
        size.resize(max);
        for(int i = 0; i < max; i++){
            parents[i] = i;
            size[i] = 1;
        }
    }
    int find_set(int a){
        if(parents[a] == a){
            return a;
        }
        return parents[a] = find_set(parents[a]);
    }
    void union_set(int a, int b){
        int sa = a;
        int sb = b;
        a = find_set(a);
        b = find_set(b);
        if(a == b){
            vector<int> road = {sa,sb};
            useless_roads.push_back(road);
        }
        if(size[a] > size[b]){
            parents[b] = a;
            size[a] += size[b];
        }else{
            parents[a] = b;
            size[b] += size[a];
        }
    }
};

int main(){
    int n;
    cin >> n;
    Dsu dsu(n);
    for(int i = 0; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        dsu.union_set(a, b);
    }
    unordered_set<int> groups;
    groups.reserve(dsu.useless_roads.size()+1);
    for(int i = 0; i < n; i++){
        groups.insert(dsu.find_set(i));
    }
    unordered_set<int>::iterator itr = groups.begin();
    cout << dsu.useless_roads.size() << endl;
    for(int i = 0; i < dsu.useless_roads.size(); i++){
        cout << dsu.useless_roads[i][0]+1 << ' ' << dsu.useless_roads[i][1]+1 << ' ' << *itr+1 << ' ';
        itr++;
        cout << *itr+1 << endl;
    }
}