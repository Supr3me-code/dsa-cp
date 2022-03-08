int getIdenticalTwinsCount(vector<int> &arr) {
	// int result = 0;
	// for(int i=0;i<arr.size()-1;i++){
	// 	for(int j=i+1;j<arr.size();j++){
	// 		if (arr[i] == arr[j]){
	// 			result++;
	// 		}
	// 	}
	// }
	// return result;
	
	//----------Optimal approach
	unordered_map<int, int> frequency;
	for(auto x: arr){
		frequency[x]++;
	}
	int identicalTwinCount = 0;
	for(auto x: frequency){
		identicalTwinCount += (x.second * (x.second - 1)/2);
	}
	return identicalTwinCount;
}