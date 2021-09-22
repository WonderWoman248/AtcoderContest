#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vr vector<ll>
#define vrr vector<vector<ll>>
#define vrs vector<string>
#define For(i, a, n) for (ll i = a; i < n;i++)
#define Dfor(i, a, n) for (ll i = n-1; i >= a;i--)

void solve(ll n){
   if(n>=90){
       cout << "expert";
   }

   else if(n >=0 and n <40){
       cout << 40 - n;
   }

   else if(n >= 40 and n < 70){
       cout << 70 - n;
   }
   else if(n >= 70 and n < 90){
       cout << 90 - n;
   }
}

int main(){
    ll n;
    cin >> n;

    solve(n);
}

