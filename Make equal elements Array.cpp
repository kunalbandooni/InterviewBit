int Solution::solve(vector<int> &A, int B) {
    // TC: O(n)
    int add=A[0]+B;
    int sub=A[0]-B;
    int same=A[0];
    for(int i=1;i<A.size();i++){
        if(A[i]==add or A[i]+B==add or A[i]-B==add)
            continue;
        if(A[i]==sub or A[i]+B==sub or A[i]-B==sub)
            continue;
        if(A[i]==same or A[i]+B==same or A[i]-B==same)
            continue;
        return 0;
    }
    return 1;

    /*
    // Check if value comes in range of difference
    int min=*min_element(A.begin(),A.end());
    int max=*max_element(A.begin(),A.end());
    int diff=max-min;

    if(diff==0)
        return 1;
    if(diff==B){
        for(auto i:A)
            if(i!=min and i!=max)
                return 0;
        return 1;
    }
    if(diff == 2*B){
        for(auto i:A)
            if(i!=min and i!=max and i!=(min+B))
                return 0;
        return 1;
    }
    return 0;
    */
}
