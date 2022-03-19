int Solution::divisibleBy60(vector<int> &A) {
    if(A.size()==1) {
        if(A[0]==0)
            return 1;
        return 0;
    }
    int sum=0;
    bool zero=false;
    // check if sum is divisible by 3 and has a "0" in it
    for(int i=0;i<A.size();i++){
        if(A[i]==0)
            zero=true;
        sum+=A[i];
    }
    if(zero==false)
        return 0;
    if(A.size()<=2){
        if(A[0]==6 or A[1]==6)
            return 1;
        return 0;
    }
    if(sum%3 == 0 and zero == true)
        return 1;
    return 0;
}
