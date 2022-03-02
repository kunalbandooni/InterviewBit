int Solution::solve(vector<int> &A, int B, int C) {
    long int c=0;
    if(B%2==0){
        for(int i=0;i<A.size();i++)
            if(A[i]%2!=0)
                c++;
    }
    else{
        for(int i=0;i<A.size();i++)
            if(A[i]%2==0)
                c++;
    }
    return c*C;
    /*bool odd=true;
    if(B%2==0){
        odd=false;
    long int c=0;
    for(int i=0;i<A.size();i++){
        if(odd and A[i]%2==0)
            c++;
        else if(!odd and A[i]%2!=0)
            c++;
    }
    return c*C;*/
}
