class Solution {
public:
    string decodeString(string s) {
        stack<char> st;
        
        for(char ch:s){
            if(ch != ']'){
                st.push(ch);
            }
            else{
                string temp;
                while(!st.empty() && st.top()!='['){
                    temp = st.top() + temp;
                    st.pop();
                }
                
                st.pop();
                
                string num = "";
                while(!st.empty() && isdigit(st.top())){
                    num = st.top() + num;
                    st.pop();
                }
                
                int n = stoi(num);

                string res;
                for(int i=0;i<n;i++){
                    res += temp;
                }
                
                for(int i=0;i<res.size();i++){
                    st.push(res[i]);
                }
                
            }
        }
        
        string ans;
        while(!st.empty()){
            ans = st.top() + ans;
            st.pop();
        }
        
        return ans;
        
    }
};