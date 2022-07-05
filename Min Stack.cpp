stack<int> stk1 , stk2;

MinStack::MinStack() {
    while(!stk1.empty())
        stk1.pop();
    while(!stk2.empty())
        stk2.pop();
}

void MinStack::push(int x) {
    stk1.push(x);
    if(stk2.empty() || x<=stk2.top())
        stk2.push(x);
}

void MinStack::pop() {
    int x;
    if(!stk1.empty()){
        x=stk1.top();
        stk1.pop();
    }
    if(!stk2.empty() && stk2.top()==x)
        stk2.pop();
}

int MinStack::top() {
    if(stk1.empty())
        return -1;
    return stk1.top();
}

int MinStack::getMin() {
    if(stk2.empty())
        return -1;
    return stk2.top();
}
