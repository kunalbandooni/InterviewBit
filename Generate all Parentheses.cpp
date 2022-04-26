int Solution::isValid(string A) {
     stack<char> s;
    int i = 0;
    int N = A.size();
    
    for(i = 0; i<N; i++){
        if(A[i] == '(' || A[i] == '{' || A[i] == '[') s.push(A[i]);
        else if(A[i] == ')'){ //can use switch case also
            if(s.empty()) return 0;
            char res = s.top();
            if(res == '(') s.pop();
            else return 0;
        }
        else if(A[i] == '}'){
            if(s.empty()) return 0;
            char res = s.top();
            if(res == '{') s.pop();
            else return 0;
        }
        else if(A[i] == ']'){
            if(s.empty()) return 0;
            char res = s.top();
            if(res == '[') s.pop();
            else return 0;
        }
    }
    return s.empty();
}
