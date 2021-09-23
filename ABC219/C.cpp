#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vr vector<ll>
#define vrr vector<vector<ll>>
#define vrs vector<string>
#define For(i, a, n) for (ll i = a; i < n;i++)
#define Dfor(i, a, n) for (ll i = n-1; i >= a;i--)

void solve(string s,ll n, vrs &names){
    unordered_map<char, ll> order;

    For(i,0,26){
        order[s[i]] = i;
    }

    function<int(string a, string b)> comp = [&](string a, string b){
        for (ll i = 0; i < min(a.size(), b.size());i++){
            if(order[a[i]] > order[b[i]]){
                return 0;
            }
           
            if(order[a[i]]<order[b[i]]){
                return 1;
            }
        }

        if(a.size() > b.size()){
            return 0;
        }
        else{
            return 1;
        }
    };

    sort(names.begin(), names.end(),comp);

    for(auto it:names){
        cout << it << '\n';
    }
}

int main(){
    string s;
    cin >> s;

    ll n;
    cin >> n;

    vrs names;

    For(i,0,n){
        string x;
        cin >> x;
        names.push_back(x);
    }

    solve(s,n,names);
}

