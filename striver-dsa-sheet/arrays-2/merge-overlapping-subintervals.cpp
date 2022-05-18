// Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        if(intervals.size()==0){
            return result;
        }
        
        sort(intervals.begin(), intervals.end());
        vector<int> aux = intervals[0];
        
        for(auto i:intervals){
            if(i[0]<=aux[1]){
                aux[1] = max(aux[1],i[1]);
            }else{
                result.push_back(aux);
                aux = i;
            }
        }
        
        result.push_back(aux);
        return result;
    }
};