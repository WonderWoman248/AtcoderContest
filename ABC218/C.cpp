#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vr vector<ll>
#define vrs vector<string>
#define For(i, a, n) for (ll i = a; i < n;i++)
#define Dfor(i, a, n) for (ll i = n-1; i >= a;i--)

// Rotating the array.
vrs rotateBy90(vrs s){
    ll n;
    n = s.size();
    vrs rotated;

    For(i,0,n){
        string temp = "";
        Dfor(j,0,n){
            temp += s[j][i];
        }
        rotated.push_back(temp);
    }
    return rotated;
}

/*
    Store the diff. between leftmost '#' in both matrix
    that will be used to check if all '#'s are shifted by
    same amount.
*/
pair<ll,ll> diff(vrs s, vrs t,ll n){
    pair<ll, ll> p1, p2;
    For(i, 0, n){
        For(j, 0, n){
            if (s[i][j] == '#'){
                p1=make_pair(i, j);
                break;
            }
        }
   }

   For(i,0,n){
       For(j,0,n){
           if(t[i][j]=='#'){
               p2 = make_pair(i, j);
               break;
           }
       }
     
   }

   pair<ll, ll> ans;
   ans = make_pair(p2.first - p1.first, p2.second - p1.second);
   return ans;
}

// Check if we are inside the matrix.
bool validCords(ll i, ll j, ll n){
    if(i>=0 and i<n and j>=0 and j<n){
        return true;
    }
    else{
        return false;
    }
}

// Checking if pattern are same after translating.
bool checkTranslation(vrs s, vrs t, ll n){
    pair<ll, ll> shift = diff(s, t, n);

    For(i,0,n){
        For(j,0,n){
            if(s[i][j] == '#'){
                if(!validCords(i+shift.first,j+shift.second,n)){
                    return false;
                }
                else if(s[i][j] != t[i+shift.first][j+shift.second]){
                    return false;
                }
            }
        }
    }

    return true;
}

// Check if numbers of '#' is same.
bool isEqual(vrs s, vrs t, ll n){
    ll cnt1 = 0, cnt2 = 0;
    For(i,0,n){
        For(j,0,n){
            if(s[i][j]=='#'){
                cnt1++;
            }
            if(t[i][j]=='#'){
                cnt2++;
            }
        }
    }

    return cnt1 == cnt2;
}

void solve(ll n, vrs s, vrs t){
    bool flag = false;

    if(!isEqual(s,t,n)){
        cout << "No";
        return;
    }

    For(i,0,4){
        vrs rotated = rotateBy90(s);
        if(checkTranslation(rotated,t,n)){
            flag = true;
            break;
        }
        s = rotated;
    }

    cout << (flag ? "Yes" : "No") << '\n';
}

int main(){
    ll n;
    cin >> n;

    vrs s(n);
    vrs t(n);
    
    For(i,0,n){
        cin >> s[i];
    }
    For(i,0,n){
        cin >> t[i];
    }

    solve(n, s, t);
}