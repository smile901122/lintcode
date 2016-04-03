class MinStack {
public:
    MinStack() {
        // do initialization if necessary
    }

    void push(int number) {
        // write your code here
        s.push(number);
        //if(ms.empty() || number <= ms.top())     ms.push(number);
        if(ms.empty())    ms.push(number);
        else  ms.push(number < ms.top() ? number : ms.top());
    }

    int pop() {
        // write your code here
        //if(s.top() == ms.top())     ms.pop();
        ms.pop();
        int val = s.top();
        s.pop();
        return val;
    }

    int min() {
        // write your code here
        return ms.top();
    }
private:
    stack<int> s;
    stack<int> ms;
};
