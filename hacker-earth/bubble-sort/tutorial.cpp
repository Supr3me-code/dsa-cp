#include<iostream>
using namespace std;

int main(){
	int n;cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int counter = 0;
	int temp;
	for(int k=0;k<n-1;k++){
		for(int i=0;i<n-k-1;i++){
			if(arr[i+1]<arr[i]){
				temp = arr[i];
				arr[i] = arr[i+1];
				arr[i+1] = temp;
				counter++;
			}
		}
	}
	cout<<counter<<endl;
	return 0;
}