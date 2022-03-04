int Solution::solve(vector<int> &A) {
    int maxi=INT_MIN,count=0;
    for(int i=0;i<A.size();i++)
        if(maxi<A[i]){
            count++;
            maxi=A[i];
        }
    return count;
}
