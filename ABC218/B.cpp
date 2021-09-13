#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(vector<ll>nums){
    string ans="";
    for (int i = 0; i < 26; i++){
        ans += 96 + nums[i];
    }
    cout << ans;
}
int main(){
    vector<ll> nums(26);

    for (ll i = 0; i < 26; i++){
        cin >> nums[i];
    }

    solve(nums);
}