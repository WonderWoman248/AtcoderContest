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
LL dp[3100][3100][2];
LL r(LL index,bool pichla_delete,LL M,vector<LL> &arr){
    if(M<0LL){
        return INF;
    }
    if(index == (LL)arr.size()){
        if(M){
            return INF;
        }
        return 0LL;
    }
    if(dp[index][M][pichla_delete] != -1LL){
        return dp[index][M][pichla_delete];
    }
    LL p1 = INF;
    LL p2 = INF;
    if(index == 0LL){
        p1 =     r(index+1,false,M-arr[index],arr);
        p2 = 1 + r(index+1,true,M,arr);
    }
    else{
        p1 = r(index+1,false,M-arr[index],arr);
        p2 = !pichla_delete + r(index+1,true,M,arr);
    }
    return dp[index][M][pichla_delete]=min(p1,p2);

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
        memset(dp,-1,sizeof(dp));
        LL N,M;
        cin >> N >> M;
        vector<LL> arr(N);
        for(auto &it:arr){
            cin >> it;
        }
        for(LL i=1;i<=M;i++){
            LL res = r(0LL,false,i,arr);
            if(res==INF){
                cout << -1 << endl;
            }
            else{
                cout << res << endl;
            }
        }
    }
    
}
