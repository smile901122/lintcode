class Solution {
public:
    /**
     * @param tokens The Reverse Polish Notation
     * @return the value
     */
    int evalRPN(vector<string>& tokens) {
        // Write your code here
        stack<char> s;
        for(auto i : tokens)
        {
            if(i == '+')
            {
                int num1 = s.top() - '0';
                s.pop();
                int num2 = s.top() - '0';
                s.pop();
                s.push(num2 + num1 + '0');
            }
            else if(i == '-')
            {
                int num1 = s.top() - '0';
                s.pop();
                int num2 = s.top() - '0';
                s.pop();
                s.push(num2 - num1 + '0');
            }
            else if(i == '*')
            {
                int num1 = s.top() - '0';
                s.pop();
                int num2 = s.top() - '0';
                s.pop();
                s.push(num2 * num1 + '0');
            }
            else if(i == '/')
            {
                int num1 = s.top() - '0';
                s.pop();
                int num2 = s.top() - '0';
                s.pop();
                s.push(num2 / num1 + '0');
            }
            else s.push(i);
        }
        int res = s.top() - '0';
        return res;
    }
};
