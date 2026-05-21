#include <bits/stdc++.h>
using namespace std;

void insert(vector<array<int,5>>& bst, int val, int index){
    if(index == -1){
        bst.push_back({-1,-1,0,0,val});
    }else if(val < bst[index][4]){
        insert(bst,val,bst[index][0]);
        if(bst[index][0] == -1) bst[index][0] = bst.size()-1;
        bst[index][2]++;
    }else{
        insert(bst,val,bst[index][1]);
        if(bst[index][1] == -1) bst[index][1] = bst.size()-1;
        bst[index][3]++;
    }
}

void erase(vector<array<int,5>>& bst, int val, int index){
    
}

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    //leftchild, rightchild, numleft, numright, val
    vector<array<int,5>> bst;
    int len;
    cin >> len;
    string action;
    int num;
    for(; len > 0; len--){
        cin >> action >> num;
        if(action == "Insert"){

        }if(action == "Delete"){
            
        }if(action == "Rank"){
            
        }if(action == "Kth"){
            
        }
    }


}