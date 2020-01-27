#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define show(a) cout<<""#a""<<" is "<<a<<endl;
#define print(arr,xx) cout<<endl<<"debug ->";for(int i=0;i<xx;i++)cout<<arr[i].first<<" "<<arr[i].second<<" \n"[i==xx-1];
#define here cerr<<"here\n";
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
	 
int caseno=0;
#define print_case cout<<"Case "<<++caseno<<": ";
#define fout freopen("output.txt","w",stdout);
#define fin freopen("input.txt","r",stdin);
#define srt(v) sort(v.begin(),v.end());
#define greatersrt(v) sort(v.begin(),v.end(),greater<ll>())
#define pb push_back
#define mp make_pair
#define PI acos(-1.0)
#define ll long long
#define ld long double
#define reto exit(0);
#define sspace <<" "<<
bool sortbysec(pair<int,int>a,pair<int,int>b){return a.second>b.second;}
ll gc(ll a,ll b){while(b){ll x=a%b;a=b;b=x;}return a;}
ll lc(ll a,ll b){return a/gc(a,b)*b;}
const int primemod=1e9+7;
const ld eps=1e-9;
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define inl(x) scanf("%lld",&x
#define in(x) scanf("%d",&x)
#define pii pair<int,int>
#define rshuffle(r...)rshuffle(r,[](int _){return rand()%_;})
ll max(ll a,ll b) {return (a>b)?a:b;}
/**Code Goes Here**/

int main(){
	#ifndef ONLINE_JUDGE 
	fout 
	fin 
	int kase=1; 
	while(kase--){
	#endif
    ///-----
		int T;
		cin>>T;
		while(T--){
			deque<string>dq;
			stack<double>st;
			string a;
			while(cin>>a and a!="?"){
				dq.push_back(a);
			}
			dq.push_back("?");
			
			while(!dq.empty() and dq.front()!="?"){
				a=dq.front(); dq.pop_front();
				if(a=="+" || a=="-" || a=="*" || a=="/"){
					double x=st.top(); st.pop();
					double y=st.top(); st.pop();
					if(a=="+")st.push(x+y);
					else if(a=="-")st.push(y-x);
					else if(a=="*")st.push(x*y);
					else if(a=="/")st.push(y/x);
				}
				else {
					double num=0;
					for(int i=0;i<a.size();i++){
						if(isdigit(a[i])){
							num=num*10.0+(a[i]-'0');
						}
					}
					st.push(num);
				}
			}
			cout<<(int)st.top()<<endl;
		}
	///-----
}
 
#ifndef ONLINE_JUDGE
}
#endif

				
