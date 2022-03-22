long Solution::countSalutes(string A) {
    long count=0,t=0;
    for(int i=0;i<A.length();i++){
        if(A[i]=='>')
            t++;
        else
            count+=t;
    }
    return count;
}
