#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main(){
	lli t;
	cin>>t;
	while(t--){
		lli n,ans=0;
		cin>>n;
		map<lli,lli>m1;
		lli arr[n];
		for(lli &i:arr)cin>>i,m1[i]++;
		ans+=(m1[1]*(m1[1]-1))/2;
		ans+=(m1[1]*(n-m1[1]));
		ans+=(m1[2]*(m1[2]-1))/2;
		cout<<ans<<endl;
	}
}