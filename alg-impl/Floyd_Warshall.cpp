#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<vector<pair<int,int>>> graph(7);
    graph[0].push_back({6,1});
    graph[1].push_back({3,1});
    graph[2].push_back({5,1});
    graph[2].push_back({4,1});
    graph[3].push_back({1,1});
    graph[3].push_back({4,1});
    graph[4].push_back({3,1});
    graph[4].push_back({2,1});
    graph[5].push_back({2,1});
    graph[5].push_back({6,1});
    graph[6].push_back({0,1});
    graph[6].push_back({5,1});

    const int INF = 9999;
    vector<vector<int>> d(graph.size(), vector<int>(graph.size(), INF));

    for(int i = 0; i < graph.size(); i++){
        d[i][i] = 0;
        for(auto [v, w] : graph[i]){
            d[i][v] = w;
        }
    }

    for(int k = 0; k < graph.size(); k++){
        for(int i = 0; i < graph.size(); i++){
            for(int j = 0; j < graph.size(); j++){
                if(d[i][j] > d[i][k] + d[k][j]){
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }

    for(int i = 0; i < graph.size(); i++){
        for(int j = 0; j < graph.size(); j++){
            cout << d[i][j] << ' ';
        }
        cout << '\n';
    }

}