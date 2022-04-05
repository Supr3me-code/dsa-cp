class Solution {
public:
    int firstUniqChar(string s) {
        set<char> st;
        set<char> st2;
        for(int i=0;i<s.size();i++){
            if(st.find(s[i])==st.end()){
                st.insert(s[i]);
            }else{
                st2.insert(s[i]);
            }
        }
        
        for(int i=0;i<s.size();i++){
            if(st2.find(s[i])==st2.end()){
                return i;
            }
        }
        
        return -1;
    }
};