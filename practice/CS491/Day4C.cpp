#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    long double sq=0,lg=0,p2=0,p1=0,c=0;
    ll n;
    cin >> n;
    
    string label;
    long double c1, c2, c3;
    for(int i = 0; i < n; i++){
        cin >> label;
        if(label == "1"){
            cin >> c1 >> c2;
            p1 += c1;
            c += c2;
        }else if(label == "2"){
            cin >> c1 >> c2 >> c3;
            p2 += c1;
            p1 += c2;
            c += c3;
        }else if(label == "sqrt"){
            cin >> c1 >> c2;
            c1 = sqrt(c1);
            sq += c1;
            c += c2;
        }else if(label == "log"){
            cin >> c1 >> c2;
            lg += c1;
            c += c2;
        }else{
            throw std::invalid_argument("bad input");
        }
    }
    long double max = -DBL_MAX;
    if(lg == 0) max = c;
    for(long double i = 1; i <= 43200; i++){
        long double val = lg*log(i)+sq*sqrt(i)+p2*i*i+p1*i+c;
        max = std::max(max, val);
    }
    cout << setprecision(10) << max << endl;
}
