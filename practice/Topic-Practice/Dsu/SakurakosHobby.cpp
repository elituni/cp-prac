#include <iostream>
#include <vector>
using namespace std;

int main(){
    int testCases = 0;
    cin >> testCases;
    for(int i = 0; i < testCases; i++){
        int n = 0;
        cin >> n;
        vector<int> pointers(n);
        vector<int> color(n);
        char temp;
        for(int i = 0; i < n; i++){
            cin >> pointers[i];
        }
        for(int i = 0; i < n; i++){
            cin >> temp;
            color[i] = temp - '0';
        }
        
        
        // cout << "pointers: ";
        // for (int i: pointers)
        //     cout << i << ' ';
        // cout << "\ncolor: ";
        // for (int i: color)
        //     cout << i << ' ';
        // cout << "\n";
        

        vector<int> numBlack(n, -1);
        for(int i = 0; i < n; i++){
            if(numBlack[i] != -1){
                continue;
            }
            int curr = i;
            int blackCount = 0;
            if(color[curr] == 0) blackCount++;
            curr = pointers[curr]-1;
            while(curr != i){
                if(color[curr] == 0) blackCount++;
                curr = pointers[curr]-1;
            }
            
            numBlack[i] = blackCount;
            curr = pointers[curr]-1;
            while(curr != i){
                numBlack[curr] = blackCount;
                curr = pointers[curr]-1;
            }
        }
        for(int i = 0; i < n; i++){
            cout << numBlack[i] << ' ';
        }
        cout << endl;
    }
}

