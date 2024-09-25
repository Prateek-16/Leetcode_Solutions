class Solution {
public:
    int calculate(string s) {
        stack<int>st;
        int result = 0;
        int sign = 1;
        int n = s.size();
        
        for(int i = 0;i<n;i++){
            if(isdigit(s[i])){
                int num = 0;
                while(i < n && isdigit(s[i])){
                    num = num*10 + (s[i] - '0');
                    i++;
                }
                num *= sign;
                result += num;
                i--;
            }
            else if(s[i] == '+'){
                sign = 1;
            }
            else if(s[i] == '-'){
                sign = -1;
            }
            else if(s[i] == '('){
                st.push(result);
                st.push(sign);
                //Reset Result and sign for values inside the bracket
                result = 0;
                sign = 1;
            }
            else if(s[i] == ')'){
                int prevSign = st.top();
                st.pop();
                int prevResult = st.top();
                st.pop();
                
                result = prevResult + (prevSign*result); 
            }
            
        }
        return result;
        
        
        
    }
};