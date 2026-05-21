#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCut(string s) {
        char prev = s[0];
        int sum = 0;
        for(int i = 1; i < s.size(); i++){
            if(s[i] != prev) {
                sum++;
                prev = s[i];
            }
        }
    }
};