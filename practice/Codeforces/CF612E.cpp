#include <bits/stdc++.h>
using namespace std;

void convert_to_disjoint_cycles(unordered_map<int, vector<vector<int>>>& output, vector<int>& input){
    vector<bool> visited(input.size());
    for(int i = 0; i < input.size(); i++){
        if(visited[i]) continue;
        vector<int> cycle;
        int start = i;
        visited[i] = true;
        cycle.push_back(i);
        int iter = input[i];
        while(iter != start){
            visited[iter] = true;
            cycle.push_back(iter);
            iter = input[iter];
        }
        output[cycle.size()].push_back(cycle);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int size;
    cin >> size;
    vector<int> input(size);
    for(int i = 0; i < size; i++){
        cin >> input[i];
        input[i]--;
    }
    unordered_map<int, vector<vector<int>>> cycles;
    convert_to_disjoint_cycles(cycles, input);

    bool impossible = false;
    vector<vector<int>> new_cycles;
    for(auto [num, cycles] : cycles){
        if(num%2==0 && cycles.size()%2==1){
            impossible = true;
            break;
        }
        if(num%2==1){
            for(auto cycle : cycles){
                vector<int> new_cycle(cycle.size());
                int i = 0;
                int index = 0;
                for(; i <= cycle.size()/2; i++){
                    new_cycle[index] = cycle[i];
                    index += 2;
                }
                index = 1;
                for(; i < cycle.size(); i++){
                    new_cycle[index] = cycle[i];
                    index += 2;
                }
                new_cycles.push_back(new_cycle);
            }
        }
        else{
            for(int i = 0; i < cycles.size(); i+=2){
                vector<int> new_cycle;
                for(int j = 0; j < cycles[i].size(); j++){
                    new_cycle.push_back(cycles[i][j]);
                    new_cycle.push_back(cycles[i+1][j]);
                }
                new_cycles.push_back(new_cycle);
            }
        }
    }

    if(impossible){
        cout << "-1";
        return 0;
    }

    vector<int> out(size);
    for(auto cycle : new_cycles){
        out[cycle[cycle.size()-1]] = cycle[0]+1;
        for(int i = 1; i < cycle.size(); i++){
            out[cycle[i-1]] = cycle[i]+1;
        }
    }

    for(int a : out){
        cout << a << ' ';
    }
}