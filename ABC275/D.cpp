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
// map<long long int,long long int > hash;
LL f(LL N,map<LL,LL> &hash){

    if(N==0){
        return 1LL;
    }
    if(hash.find(N)!=hash.end()){
        return hash[N];
    }
    return hash[N] = f(N/2,hash) + f(N/3,hash);
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
        LL N;
        cin >> N;
        map<LL,LL> hash;
        cout << f(N,hash) << endl;

    }
    
}
// try out all pairs of 
