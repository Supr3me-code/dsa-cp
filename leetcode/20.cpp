class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto c:s){
            if(c=='(')
                st.push(')');
            else if(c=='{')
                st.push('}');
            else if(c=='[')
                st.push(']');
            else{
                if(!st.empty() && c==st.top()){
                    st.pop();     
                }else{
                    return false;
                }
            }
        }
        return st.empty();
    }
};