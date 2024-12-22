#include <bits/stdc++.h>
using namespace std;

int main() {

    //read orderings
    std::string line;
    vector<vector<int>> tokens;
    while(getline(cin, line)){
        if(line.size() == 0) break;
        stringstream ss(line);
        string token;

        vector<int> v;
        while(getline(ss, token, '|')){
            v.push_back(stoi(token));
        }
        tokens.push_back(v);
    }

    //read chains
    vector<vector<int>> chains;
    while(getline(cin, line)){
        stringstream ss(line);
        string token;

        vector<int> v;
        while(getline(ss, token, ',')){
            v.push_back(stoi(token));
        }
        chains.push_back(v);
    }


    //pt 1 --------
    int firstsum = 0;
    vector<vector<int>> failed;
    for(int i = 0; i < chains.size(); i++){
        bool passed = true;
        int mid = chains[i][chains[i].size()/2];
        for(int j = 0; j < chains[i].size(); j++){
            for(int k = j+1; k < chains[i].size(); k++){
                for(int l = 0; l < tokens.size(); l++){
                    if(tokens[l][1] == chains[i][j] && tokens[l][0] == chains[i][k]){
                        passed = false;
                    }
                }
            }
        }
        if(!passed) failed.push_back(chains[i]);
        if(passed) firstsum += mid;
    }
    cout << firstsum << endl;


    //pt 2 --------
    int secondsum = 0;
    for(int i = 0; i < failed.size(); i++){
        bool passed = true;
        for(int j = 0; j < failed[i].size(); j++){
            for(int k = j+1; k < failed[i].size(); k++){
                for(int l = 0; l < tokens.size(); l++){
                    if(tokens[l][1] == failed[i][j] && tokens[l][0] == failed[i][k]){
                        int temp = failed[i][j];
                        failed[i][j] = failed[i][k];
                        failed[i][k] = temp;
                    }
                }
            }
        }
        secondsum += failed[i][failed[i].size()/2];
    }
    cout << secondsum;
}