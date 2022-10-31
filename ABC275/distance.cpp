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
#define  INF (long long int)1e15
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
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);
    #endif
    my_gease;
    LL N;
    cin >> N;
    LL M;
    cin >> M;
    LL K;
    cin >> K;
    vector<LL> a(1+M);
    vector<LL> b(1+M);
    vector<LL> c(1+M);
    for(LL i=1;i<=M;i++){
        LL  x,y,w;
        cin >> x >> y >> w;
        a[i] = x;
        b[i] = y;
        c[i] = w;
    }
    vector<LL> distance(N+1,INF);
    distance[1] = 0LL;
    while(K--){
        LL index;
        cin >> index;
        // path from A TO B  USING C
        if(distance[b[index]]>distance[a[index]]+c[index]){
            distance[b[index]] = distance[a[index]]+c[index];   
        }
    }
    if(distance[N]==INF){
        cout<<-1<<endl;
    }
    else{
        cout << distance[N]<<endl;
    }

}
