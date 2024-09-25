class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        
        for(auto it : tokens){
            if(isdigit(it[0]) || it.size() > 1){
                st.push(stoi(it));
            }
            else{
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();
                
                if(it == "+"){
                    st.push(num2 + num1);
                }
                else if(it == "-"){
                    st.push(num2 - num1);
                }
                else if(it == "*"){
                    st.push(num2 * num1);
                }
                else{
                    st.push(num2 / num1);
                }
            }
        }
        return st.top();
        
    }
};