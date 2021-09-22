#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vr vector<ll>
#define vrr vector<vector<ll>>
#define vrs vector<string>
#define For(i, a, n) for (ll i = a; i < n;i++)
#define Dfor(i, a, n) for (ll i = n-1; i >= a;i--)

// Checking if a point exit in the array.
bool check(ll x, ll y,vector<pair<ll,ll>>points){
    pair<ll, ll> find = make_pair(x, y);

    // STL binary search function.
    if(binary_search(points.begin(),points.end(),find)){
        return true;
    }

    return false;
}

void solve(ll n, vector<pair<ll,ll>>points){
    ll cnt = 0;
    sort(points.begin(), points.end());
    For(i,0,n-1){
        For(j,i+1,n){
            
            // Checking for bottom left point and top right points exits.
            if(points[i].first<points[j].first and points[i].second < points[j].second){

                // Checking for rest two points.
                if(check(points[i].first,points[j].second,points) and check(points[j].first,points[i].second,points)){
                    cnt++;
                }
            }
        }
    }

    cout << cnt;
}

int main(){
    ll n;
    cin >> n;

    vector<pair<ll, ll>> points(n);

    For(i,0,n){
        ll x, y;
        cin >> x >> y;
        points[i] = {x, y};
    }
    solve(n,points);
}

