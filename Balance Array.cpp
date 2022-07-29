int Solution::solve(vector<int> &A) {
    int le=0,te=0,to=0; //left even total even , total odd
    int lo=0,re=0, ro=0; //left odd, right even, right odd;
    int n=A.size();
    for(int i=0; i<n; i++){
        if(i%2==0) te+=A[i];
        else to+=A[i];
    }

    int ans=0;
    for(int i=0; i<n; i++){
        if(i%2==0){
            re=te-le-A[i]; //we must remove left even and curr element to get right even
            ro=to-lo;       //because A[i] is not yet added to left even
            if(le+ro==re+lo) ans++; //after removing curr, right even becomes right odd and vice versa
            le+=A[i];
        }
        else{
            re=te-le;
            ro=to-lo-A[i];  //same reason
            if(le+ro==re+lo) ans++;
            lo+=A[i];
        }
    }
    return ans;
}
