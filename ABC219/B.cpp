#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vr vector<ll>
#define vrr vector<vector<ll>>
#define vrs vector<string>
#define For(i, a, n) for (ll i = a; i < n;i++)
#define Dfor(i, a, n) for (ll i = n-1; i >= a;i--)

void solve(string s1,string s2, string s3,string t){
    string ans = "";
    for(auto it:t){
        if(it=='1'){
            ans += s1;
        }
        else if(it=='2'){
            ans += s2;
        }

        else{
            ans += s3;
        }
    }

    cout << ans;
}

int main(){
    string s1,s2,s3,t;
    cin >> s1 >> s2 >> s3 >> t;

    solve(s1,s2,s3,t);
}

