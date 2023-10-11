#include <bits/stdc++.h>
using namespace std;
#define ll long long

void isPowerOfTwo(ll n){
    if(x<0){
    cout << "No" << '\n';
    }
    else if((n & (~(n - 1)) == n)){
        cout << "Yes" <<'\n';
    }
    else{
        cout << "No" << '\n';
    }
}

int main(){
    ll t=1;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        isPowerOfTwo(n)
    }
}