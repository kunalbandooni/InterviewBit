vector<int> Solution::plusOne(vector<int> &A) {
    int x=0;
    int n=A.size();
    int i=n-1;
    while(A[i]==9) {
        A[i]=0;
        x++;
        i--;
    }
    if(x==n)
        A.insert(A.begin(),1);
    else 
        A[i]++;
    i=0;
    while(A[i]==0)
        A.erase(A.begin(),A.begin()+1);
    return A;  
}
