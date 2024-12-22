#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string orgline;
    int counter = 0;
    while(getline(cin, orgline)){
        // cout << "while" << endl;
 
    // variable to store token obtained from the original
    // string
    string s;
 
    // constructing stream from the string
    // cout << "orgline 1: " << orgline << endl;
    stringstream ss(orgline);
 
    // declaring vector to store the string after split
    vector<int> v;
 
    // using while loop until the getline condition is
    // satisfied
    // ' ' represent split the string whenever a space is
    // found in the original string
    while (getline(ss, s, ' ')) {
 
        // store token string in the vector
        v.push_back(stoi(s));
    }

//     for (int i: v)
//     cout << i << ' ';
// cout << '\n';

    bool passed = false;
    // cout << orgline << '\n';
    // cout << "v size: " << v.size() << '\n';
    for(int i = 0; i <= v.size(); ++i){
        vector<int> vec = v;
        if(i != v.size()){
            vec.erase(vec.begin() + i);
        }
        bool failed = false;
        bool increasing = true;
        int prev, curr;
        prev = vec[0];
        curr = vec[1];
        if(curr-prev <= 3 && curr-prev >=1){
            increasing = true;
        }else if(prev-curr <= 3 && prev-curr >=1){
            increasing = false;
        }
        else continue;
        prev = curr;
        for(int k = 2; k < vec.size(); k++){
            curr = vec[k];
            if(increasing && curr-prev <= 3 && curr-prev >=1){
                prev = curr;
            }
            else if(!increasing && prev-curr <= 3 && prev-curr >=1){
                prev = curr;
            }
            else{
                counter--;
                failed = true;
                break;
            }
        }
        counter++;

        if(!failed){
            // cout << "i:" << i << "  counter: " << counter << '\n';
            break;
        }
    }
    // cout << "end" << endl;
    // cout << orgline << '\n';
    }
    cout << counter;
}