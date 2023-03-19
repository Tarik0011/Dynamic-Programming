/*
*   -------------- ?*?*? --------------
* |         In The Name of *Allah*     |
* |             Author : Tarik         |
* |                                    |
*  -------------- ?*?*? ---------------
*/
 
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define  pb        push_back
#define  all(v)    v.begin(),v.end()
#define  endl       '\n'  
#define  uint       long long
#define  int        long long
#define  fastio    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL) 
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set; 

const int mxn=1e6+123;
int a[mxn];
void solve(){
   int n;
   cin>>n;
   for(int i=0;i<n;i++){
   	cin>>a[i];
   }
   vector<vector<int>>subsets;
   for(int mask=1;mask<(1<<n);mask++){
   	vector<int>v;
   	for(int i=0;i<n;i++){
   		if((mask & (1<<i))!=0){
   			v.pb(a[i]);
   		}
   	}
   	 subsets.pb(v);
   }
   
   for(auto x:subsets){
   	for(auto u:x){
   		cout<<u<<' ';
   	}
   	cout<<endl;
   }

}
signed main(){ 
    fastio; 
    int t=1;
   // cin>>t;
    while(t--){
       solve();
    }
}
