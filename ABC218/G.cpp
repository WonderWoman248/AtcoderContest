#include <bits/stdc++.h>
using namespace std;
#define ll long long

int isPrime(int n)
{
    if (n <= 1)
        return 0;
    if (n == 2 || n == 3)
        return 1;

    if (n % 2 == 0 || n % 3 == 0)
        return 0;

    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return 0;
    return 1;
}

int main(){
    ll t=1;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        int res = isPrime(n);
        if(res == 1){
        cout << "Yes" <<'\n';
        }else{
        cout << "No" <<'\n';
        }
    }
}