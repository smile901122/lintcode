class Solution {
public:
    /**
     * @param s A string
     * @return whether the string is a valid parentheses
     */
    bool isValidParentheses(string& s) {
        // Write your code here
        string left = "([{";
        string right = ")]}";
        stack<char> stk;
        for (auto c : s) 
        {
            if (left.find(c) != string::npos)   //字符串中find若找到返回下标，否则返回 npos 
            {
                stk.push (c);
            } 
            else 
            {
                if (stk.empty () || stk.top () != left[right.find (c)])
                return false;
                else    stk.pop ();
            }
        }
        return stk.empty();
        /*
        int n = s.size();
        if(n < 2)   return false;
        unordered_map<char, char> m;
        m['}'] = '{';
        m[']'] = '[';
        m[')'] = '(';
        
        stack<char> st;
        for(int i = 0; i < n; ++i)
        {
            switch(s[i])
            {
                case '{':
                case '[':
                case '(':
                    st.push(s[i]);
                    break;
                case '}':
                case ']':
                case ')':
                    if(st.empty() || st.top() != m[s[i]])   return false;
                    else st.pop();
            }
        }
        if(st.empty())  return true;
        return false;
        */
    }
};
