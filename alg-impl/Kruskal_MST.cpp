#include <vector>
#include <unordered_map>
#include <algorithm>
#include <array>
using namespace std;

struct Graph{
    vector<int> vertices;
    //weight -> first vertex -> second vertex
    vector<array<int, 3>> edges;

    vector<array<int, 3>> kruskal_mst(){
        sort(edges.begin(), edges.end());
        Dsu dsu(*this);
        vector<array<int,3>> mst_edges;
        for(auto edge : edges){
            if(dsu.find_set(edge[1]) != dsu.find_set(edge[2])){
                mst_edges.push_back(edge);
                dsu.union_set(edge[1], edge[2]);
            }
        }
        return mst_edges;
    }
};

struct Dsu{
    unordered_map<int, int> parents;
    unordered_map<int, int> size;
    Dsu(Graph graph){
        for(int vertex : graph.vertices){
            parents[vertex] = vertex;
            size[vertex] = 1;
        }
    }
    int find_set(int a){
        if(parents[a] == a) return a;
        return parents[a] = find_set(parents[a]);
    }
    void union_set(int a, int b){
        a = find_set(a);
        b = find_set(b);
        if(size[a] > size[b]) swap(a, b);
        parents[b] = a;
        size[a] += size[b];
    }
};



