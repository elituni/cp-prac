#include <bits/stdc++.h>
using namespace std;

class Graph{
    public:
    // pair.first is connected vertex, pair.second is weight
    unordered_map<int, vector<pair<int,int>>> graph;

    vector<array<int, 3>> prim_mst(){
        unordered_set<int> visited;
        //key: unvisited vertex; value: visited vertex and weight
        unordered_map<int, array<int, 2>> neighbors;
        //weight, unvisited vertex, visited vertex
        set<array<int,3>> distances;
        //weight, unvisited vertex, visited vertex
        vector<array<int, 3>> mst_edges;
        int previous = graph.begin() -> first;
        visited.insert(previous);
        for(auto [v, w] : graph.begin() -> second){
            neighbors.insert({v, {previous, w}});
            distances.insert({w, v, previous});
        }
        while(distances.size() > 0){
            array<int, 3> curr_vertex = *distances.begin();
            distances.erase(curr_vertex);
            visited.insert(curr_vertex[1]);
            mst_edges.push_back(curr_vertex);

            previous = curr_vertex[1];
            for(auto [v, w] : graph[previous]){
                if(visited.contains(v)) continue;
                if(neighbors.contains(v)){
                    if(w < neighbors[v][1]){
                        distances.erase({neighbors[v][1], v, neighbors[v][0]});
                        distances.insert({w, v, previous});
                        neighbors[v] = {previous, w};
                    }
                }else{
                    distances.insert({w, v, previous});
                    neighbors[v] = {previous, w};
                }
            }
        }
        return mst_edges;
    }
};

int main(){
    Graph g;
    g.graph.insert({1, {{0, 4}, {7, 11}, {2, 8}}});
    g.graph.insert({2, {{1, 8}, {8, 2}, {5, 4}, {3, 7}}});
    g.graph.insert({3, {{2, 7}, {5, 14}, {4, 9}}});
    g.graph.insert({4, {{3, 9}, {5, 10}}});
    g.graph.insert({5, {{2, 4}, {3, 14}, {4,10}}});
    g.graph.insert({6, {{7, 1}, {8, 6}, {5, 2}}});
    g.graph.insert({7, {{0, 8}, {1, 11}, {8, 7}, {6, 1}}});
    g.graph.insert({8, {{2, 2}, {7, 7}, {6, 6}}});
    g.graph.insert({0, {{1, 4}, {7, 8}}});

    vector<array<int,3>> mst = g.prim_mst();
    cout << "minimum spanning tree: \n";
    for(auto [w, v1, v2] : mst){
        cout << v1 << ' ' << v2 << ' ' << w << endl;
    }
}