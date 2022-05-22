int Solution::braces(string A) {
    stack<char> s;
    int n = A.size();

    for(int i=0;i<n;i++){
        if(A[i] != ')')
            s.push(A[i]);
        else{
            int cnt = 0;
            while(s.size()>0 && s.top()!= '('){
                char ch = s.top();
                s.pop();
                if(ch=='+' || ch=='-' || ch=='*' || ch=='/')
                    cnt++;
            }
            if(cnt == 0)
                return true;
            s.pop();
        }
    }
    return false;
}
