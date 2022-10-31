#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
#include "unordered_map"
#include "unordered_set"
#include "algorithm"
#include "iostream"
#include "cstring"
#include "cstdlib"
#include "cassert"
#include "numeric"
#include "cstdio"
#include "vector"
#include "bitset"
#include "cmath"
#include "queue"
#include "stack"
#include "list"
#include "map"
#include "set"
#define  my_gease ios_base::sync_with_stdio(false);cin.tie(NULL);
#define  YES cout<<"YES"<<endl;
#define  NO  cout<<"NO"<<endl;
#define  INF 0x3f3f3f3f3f3f3f3fLL
#define  LL long long int 
using namespace __gnu_pbds;
using namespace std;
typedef tree<LL, null_type, less_equal<LL>, 
rb_tree_tag,tree_order_statistics_node_update> ordered_set;
void print_array(vector<LL> &arr){
    for(auto it:arr){
        cout<<it<<" ";
    }
    cout<<endl;
}
void print_hashmap(map<LL,LL> &hash){
    for(auto it:hash){
        cout << it.first<<" "<<it.second << endl;
    }
}
LL Pow(LL x,LL y,LL M){
    LL prod=1;
    while(y){
        if(y%2){
            prod=(prod*x)%M;
        }
        x=(x*x)%M;
        y=y/2;
    }
    return prod%M;
}
const long long int mod = 998244353LL;
LL dp[2000][2000];
LL r(LL current_pos,LL moves_left,LL N,LL M){
    if(moves_left<0){
        return 0LL;
    }
    if(current_pos==N){
        return 1LL;
    }
    if(dp[current_pos][moves_left] !=  -1LL){
        return dp[current_pos][moves_left];
    }
    LL pp = 0LL;
    LL p = Pow(M,mod-2,mod);
    for(LL i=1;i<=M;i++){
        if(current_pos+i>N){
            LL left = current_pos + i - N;
            pp = (pp + (p*r(current_pos-left,moves_left-1LL,N,M))%mod)%mod;
        }
        else{
            pp = (pp + (p*r(current_pos+i,moves_left-1LL,N,M)))%mod;
        }
    }
    return dp[current_pos][moves_left]=pp;
}
LL euclid(LL x1,LL y1,LL x2,LL y2){
    return (x1-x2)*(x1-x2) +  (y1-y2)*(y1-y2);
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);
    #endif
    my_gease;
    LL T;
    T = 1LL;
    while(T--){
        LL N = 9LL;
        vector<string> arr(N);
        for(auto &it:arr){
            cin >> it;
        }
        LL cnt = 0LL;
        for(LL i=0;i<N;i++){
            for(LL j=0;j<N;j++){
                for(LL x=0;x<N;x++){
                    for(LL y=0;y<N;y++){
                        for(LL x1=0;x1<N;x1++){
                            for(LL y1=0;y1<N;y1++){
                                for(LL x2=0;x2<N;x2++){
                                    for(LL y2=0;y2<N;y2++){
                                        if(
                                            euclid(i,j,x,y) &&
                                            euclid(i,j,x,y) == euclid(i,j,x2,y2) && 
                                            euclid(i,j,x2,y2) == euclid(x2,y2,x1,y1) && 
                                            euclid(x2,y2,x1,y1) == euclid(x1,y1,x,y) &&
                                            euclid(i,j,x1,y1) == euclid(x,y,x2,y2) &&
                                            euclid(i,j,x1,y1) == 2*euclid(i,j,x,y))
                                        {
                                            if(arr[i][j]=='#' and arr[x1][y1]=='#' and arr[x2][y2]=='#' and arr[x][y]=='#' )
                                                cnt++;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        // how to count these tedhe medhe squares
        cout << cnt/8 << endl;

    }
    
}
