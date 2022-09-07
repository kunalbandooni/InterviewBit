// All credits to STRIVER - TAKE_U_FORWARD

vector<int> Solution::repeatedNumber(const vector<int> &A) {
    int xor_all = 0;
    int n = A.size();
    for(int i=1;i<=n;i++)
        xor_all = xor_all ^ i;
    for(int i=0;i<n;i++)
        xor_all = xor_all ^ A[i];
    
    int rsb = xor_all & -xor_all;
    
    int x = 0, y = 0;
    for(int i=1;i<=n;i++){
        if(rsb & i)
            x=x^i;
        else
            y=y^i;
    }
    
    for(int i=0;i<n;i++){
        if(rsb & A[i])
            x = x^A[i];
        else
            y = y^A[i];
    }
    
    for(int i=0;i<n;i++){
        if(x == A[i])
            return {x,y};
        else if(y == A[i])
            return {y,x};
    }
    return {};
}
