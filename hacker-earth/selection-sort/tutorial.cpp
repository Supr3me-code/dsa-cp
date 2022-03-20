#include<iostream>
using namespace std;

int main(){
	int n,x;
	cin>>n>>x;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int minimum;
	for(int i=0;i<x;i++){
		minimum = i;
		for(int j=i+1;j<n;j++){
			if(arr[minimum]>arr[j]){
				minimum = j;
			}
		}
		swap(arr[minimum],arr[i]);
	}
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	return 0;
}