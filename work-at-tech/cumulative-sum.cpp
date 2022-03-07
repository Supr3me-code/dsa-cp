vector<int> getCumulativeSum(vector<int> &arr) {
	vector<int> result;
	int sum = 0;
	for(int i=0;i<arr.size();i++){
		sum += arr[i];
		result.push_back(sum);
	}
	return result;
}