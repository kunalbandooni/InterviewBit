int Solution::solve(int A, vector<vector<int> > &B) {
    vector<int> store1(A+1 , 1);
    int sum  = 0;
    int n = B.size();
    
    sort(B.begin() , B.end());
    for(int i  =  n-1; i >= 0 ; i--)
        store1[B[i][0]] += store1[B[i][1]];  
    
    for(int k = 2 ; k < store1.size() ; k++)
        if(store1[k]%2 == 0)
            sum++;
    
    return sum;
}
