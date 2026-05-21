#include <bits/stdc++.h>
using namespace std;


int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    long t, n, x1, y1, x2, y2;
    cin >> t;
    for(long it = 0; it < t; it++){
        cin >> n >> x1 >> y1 >> x2 >> y2;
        double mid = (n/2)+0.5;
        x1 -= mid; y1 -= mid; x2 -= mid; y2 -= mid;
        x1 = abs(x1); y1 = abs(y1); x2 = abs(x2); y2 = abs(y2);
        double m1 = max(x1,y1);
        double m2 = max(x2,y2);
        double dist = abs(m1-m2);
        long ldist = lround(dist);
        cout << ldist << '\n';
    }

}