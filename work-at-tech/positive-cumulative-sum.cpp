vector<int> getPositiveCumulativeSum(vector<int> &arr) {
	vector<int> result;
	int sum = 0;
	for(int i=0;i<arr.size();i++){
		sum += arr[i];
		if(sum>0){
			result.push_back(sum);
		}
	}
	return result;
}