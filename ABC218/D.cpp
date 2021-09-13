#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vr vector<ll>
#define vrr vector<vector<ll>>
#define vrs vector<string>
#define For(i, a, n) for (ll i = a; i < n;i++)
#define Dfor(i, a, n) for (ll i = n-1; i >= a;i--)

void solve(ll n, vrr points){
}

int main(){
    ll n;
    cin >> n;

    vrr points(n, vr(2));

    For(i,0,n){
        For(j,0,2){
            cin >> points[i][j];
        }
    }
    solve(n,points);
}

