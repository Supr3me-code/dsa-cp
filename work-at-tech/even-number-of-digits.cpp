int numberOfDigits(int n){
	int digits = 0;
	if(n==0){
		return 1;
	}
	while(n>0){
		n /= 10;
		digits++;
	}
	return digits;
}

vector<int> getEvenDigitNumbers(vector<int> &arr) {
    vector<int> result;
	for(int i=0;i<arr.size();i++){
		if(numberOfDigits(arr[i])%2==0){
			result.push_back(arr[i]);
		}
	}
	return result;
}
