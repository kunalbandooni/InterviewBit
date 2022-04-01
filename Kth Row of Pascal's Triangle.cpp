// TC: O(n)
vector<int> Solution::getRow(int A){
    vector<int> res(A+1);
    res[0]=1;
    for(int i=1;i<=A;i++)
        res[i] = res[i-1] * (A-i+1) / i;
    return res;
}
// Time taken too long... 
//      also long long int is small :)
/*long long int fact(int n){
    long long int f=1;
    for(int i=2;i<=n;i++)
        f=f*i;
    return f;
}
vector<int> Solution::getRow(int A) {
    if(A == 0)
        return {1};
    else if(A==1)
        return {1,1};
    vector<int> v;
    long long int x=fact(A);
    for(int i=0;i<=A;i++){
        if(i == 0 or i == A)
            v.push_back(1);
        else
            v.push_back(x / (fact(i)*fact(A-i)));
    }
    return v;
}*/
