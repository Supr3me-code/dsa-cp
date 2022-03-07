#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	int n;cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	sort(arr,arr+n);
	int q;cin>>q;
	
	while(q--){
		int low = 0, high = n-1;
		int query;cin>>query;
		while(low<=high){
			int mid=(low+high)/2;
     		if(arr[mid]<query){
         		low=mid+1;
     		}
     		else if(arr[mid]>query){
         		high=mid-1;
     		}
     		else{
         		cout<<mid+1<<endl;
				break;
     		}
		}
	}
}