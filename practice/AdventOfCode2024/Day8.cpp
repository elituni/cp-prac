#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    map<char, vector<pair<int,int> > > antennas;
    vector<vector<char> > grid;

    string line;

    while(getline(cin, line)){
        vector<char> l;
        stringstream ss(line);
        char token;

        while(ss >> token){
            l.push_back(token);
        }
        grid.push_back(l);
    }

    for(unsigned int i = 0; i < grid.size(); i++){
        for(unsigned int j = 0; j < grid[0].size(); j++){
            if(grid[i][j] != '.'){
                antennas[grid[i][j]].push_back(make_pair(i,j));
            }
        }
    }

    set<pair<int,int> > visited;
    ll total = 0;
    for(auto [key, vec] : antennas){
        for(int i = 0; i < vec.size(); i++){
            for(int j = i+1; j < vec.size(); j++){
                int x_dist = vec[j].first-vec[i].first;
                int y_dist = vec[j].second-vec[i].second;
                pair<int,int> l = make_pair(vec[i].first-x_dist, vec[i].second-y_dist);
                pair<int,int> r = make_pair(vec[j].first+x_dist, vec[j].second+y_dist);
                while(l.first < grid.size() && l.first >= 0 && l.second < grid[0].size() && l.second >= 0){
                    if(!visited.contains(l)){ 
                        visited.insert(l);
                        // grid[l.first][l.second] = '#';
                        total++;
                    }
                    l.first -= x_dist;
                    l.second -= y_dist;
                }
                while(r.first < grid.size() && r.first >= 0 && r.second < grid[0].size() && r.second >= 0){
                    if(!visited.contains(r)){
                        visited.insert(r);
                        // grid[r.first][r.second] = '#';
                        total++;
                    }
                    r.first += x_dist;
                    r.second += y_dist;
                }
            }
        }
        for(auto pair : vec){
            if(!visited.contains(pair)){
                total++;
                visited.insert(pair);
            }
        }
    }
    // for(unsigned int i = 0; i < grid.size(); i++){
    //     for(unsigned int j = 0; j < grid[0].size(); j++){
    //         cout << grid[i][j];
    //     }
    //     cout << '\n';
    // }

    cout << total;

}