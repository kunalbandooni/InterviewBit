vector<int> Solution::solve(vector<int> &A) {
    int low=0,high=0;
    while(high!=A.size()-1){
        while(A[low]!=0 && low!=A.size()-1)
            low++;
        if(high==0)
            high=low;
        while(A[high]==0 && high!=A.size()-1)
            high++;
        swap(A[low],A[high]);   
    }
    return A;
}
