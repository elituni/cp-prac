#include <bits/stdc++.h>
using namespace std;
using ll = long long;

deque<vector<int>> get_permutations(int len){
    deque<vector<int>> permutations;
    vector<int> perm;
    vector<int> copy;
    vector<int> second_copy;
    permutations.push_back(perm);
    while((perm = permutations.front()).size() != len){
        permutations.pop_front();
        copy = perm;
        second_copy = perm;
        perm.push_back(0);
        copy.push_back(1);
        second_copy.push_back(2);
        permutations.push_back(perm);
        permutations.push_back(copy);
        permutations.push_back(second_copy);
    }
    return permutations;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<ll> totals;
    vector<vector<ll>> elems;

    string line;
    while(getline(cin, line)){
        stringstream ss(line);
        string token;

        ll input;
        char colon;

        ss >> input;
        totals.push_back(input);

        ss >> colon;

        vector<ll> line_elements;
        while(ss >> input){
            line_elements.push_back(input);
        }
        elems.push_back(line_elements);
    }

    ll correct_sum = 0;
    int index = 0;
    for(auto elem_list : elems){
        bool passed = false;
        deque<vector<int>> permutations = get_permutations(elem_list.size()-1);
        for(auto permutation : permutations){
            ll total = elem_list[0];
            for(int i = 0; i < permutation.size(); i++){
                if(permutation[i] == 0){
                    total += elem_list[i+1];
                }else if(permutation[i] == 1){
                    total *= elem_list[i+1];
                }else{
                    string concat = to_string(total) + to_string(elem_list[i+1]);
                    total = stoll(concat);
                }
            }
            if(total == totals[index]){
                passed = true;
                break;
            }
        }
        if(passed){
            correct_sum += totals[index];
        }
        index++;
    }
    cout << correct_sum;
}

