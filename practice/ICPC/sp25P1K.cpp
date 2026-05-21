#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    array<pair<double,double>,3> control;
    array<pair<double,double>,3> vaccinated;

    int n;
    cin >> n;
    char v,a;
    for(int i = 0; i < n; i++){
        cin>>v;
        if(v == 'N'){
            for(int j = 0; j < 3; j++){
                cin >> a;
                if(a == 'Y') control[j].first++;
                control[j].second++;
            }
        }
        if(v == 'Y'){
            for(int j = 0; j < 3; j++){
                cin >> a;
                if(a == 'Y') vaccinated[j].first++;
                vaccinated[j].second++;
            }
        }
    }
    for(int j = 0; j < 3; j++){
        if(control[j].first / control[j].second <= vaccinated[j].first / vaccinated[j].second){
            cout << "Not Effective" << '\n';
        }else{
            cout << (((control[j].first / control[j].second) - (vaccinated[j].first / vaccinated[j].second)) / (control[j].first / control[j].second)) * 100 << '\n';
        }
    }
}
