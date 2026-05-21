#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int max = 1;
        for(int i = 0; i < points.size(); i++){
            map<array<float,2>,int> freq;
            for(int j = i+1; j < points.size(); j++){
                float x = points[i][0]-points[j][0];
                float y = points[i][1]-points[j][1];
                if(x==0){
                    freq[{(float)INT_MAX,(float)points[i][0]}]++;
                }else{
                    float slope = y/x;
                    float intercept = points[i][1]-(points[i][0]*slope);
                    freq[{slope,intercept}]++;
                }
            }
            for(auto [a,f] : freq){
                max = std::max(max,f+1);
            }
        }
        return max;
    }
};

