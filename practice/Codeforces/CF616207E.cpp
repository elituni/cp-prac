#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    array<long long, 15> count;
    long long sum = 0;
    long long digit = 1;
    for(int i = 0; i < 15; i++){
        count[i] = sum;
        sum = digit + sum*9;
        digit *= 10;
    }
    long long t, k;
    cin >> t;
    for(long long it = 0; it < t; it++){
        cin >> k;
        long long s = k;
        long long sum = 0;
        long long d;
        long long c = 1;
        long long i = 0;
        while(k != 0){
            d = k%10;
            if(d >= 4){
                sum += c + (d-1)*count[i];
            }else{
                sum += d*count[i];
            }
            c *= 10;
            k /= 10;
            i++;
        }
        cout << s-sum << '\n';
    }
}