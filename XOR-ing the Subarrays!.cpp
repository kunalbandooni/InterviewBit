int Solution::solve(vector<int> &A) {
    // basic intuition is... 
    //      even numbers when XOR give 0 
    //      odd numbers when XOR give [ XOR of odd places ]
    if(A.size()%2==0)
        return 0;
    int XOR = 0;
    for(int i=0;i<A.size();i+=2)
        XOR^=A[i];
    return XOR;
}
