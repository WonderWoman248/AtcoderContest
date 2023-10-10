#include <bits/stdc++.h>
using namespace std;
#define ll long long

void checkOdd(ll n){
    if(n%2 == 1){
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
        checkOdd(n)
    }
}