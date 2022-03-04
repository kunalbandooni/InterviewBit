int Solution::singleNumber(const vector<int> &A) {
    int a=0;
    for(int i=0;i<A.size();i++)
        a=a^A[i];
    return a;
}
