#include<iostream>
using namespace std;

double value(double x){
	return 2*x*x - 12*x + 7;
}

int main(){
	int n;cin>>n;
	while(n--){
		double l,r;
		cin>>l>>r;
		for(int i=0;i<200;i++){
			double l1 = (l*2+r)/3;
			double l2 = (l+r*2)/3;
			if(value(l1)<value(l2)){
				r = l2;
			}else{
				l = l1;
			}
		}
		cout<<value(l)<<endl;
	}
	return 0;
}