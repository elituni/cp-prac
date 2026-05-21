#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void add(vector<string>& ans, list<string>& lis, unordered_set<string>& v, string s){
        for(int i = 1; i <= s.size(); i++){
            string str = s.substr(0, i);
            if(v.contains(str)){
                if(i == s.size()){
                    std::ostringstream oss;
                    for(string word : lis){
                        oss << word << ' ';
                    }
                    oss << str;
                    ans.push_back(oss.str());
                }
                else{
                    lis.push_back(str);
                    add(ans,lis,v,s.substr(i));
                    lis.pop_back();
                }
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> v;
        v.reserve(1024);
        v.max_load_factor(0.25); 

        for(string word : wordDict){
            v.insert(word);
        }
        vector<string> ans;
        list<string> lis;
        add(ans,lis,v,s);
        return ans;
    }
};