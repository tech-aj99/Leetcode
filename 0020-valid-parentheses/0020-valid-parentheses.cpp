class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(char ch:s){
            // opening brackets
            if(ch == '(' || ch == '{' || ch == '['){
                st.push(ch);
            }
            //closing brackets
            else{
                //no matching opening bracket
                if(st.empty()) return false;
                // check matching pair 
                if(ch == ')' && st.top() != '(') return false;
                if(ch == '}' && st.top() != '{') return false;
                if(ch == ']' && st.top() != '[') return false;

                st.pop();
            }
        }
        // stack should be empty if all brackets are matched 
        return st.empty();
    }
};