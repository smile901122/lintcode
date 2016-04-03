class Queue {
public:
    stack<int> stack1;
    stack<int> stack2;

    Queue() {
        // do intialization if necessary
    }

    void push(int element) {
        // write your code here
        stack1.push(element);
    }
    
    int pop() {
        // write your code here
        if(stack2.empty())  s1ToS2(stack1, stack2);
        int val = stack2.top();
        stack2.pop();
        return val;
    }

    int top() {
        // write your code here
        if(stack2.empty())  s1ToS2(stack1, stack2);
        return stack2.top();
    }
private:
    void s1ToS2(stack<int> &s1, stack<int> &s2)
    {
        while(!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
    }
};
