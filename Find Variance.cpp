string Solution::solve(vector<int> &A) {
    int n=A.size();
    double sum=0,sum_sqr=0;
    for(int i=0;i<n;i++){
        sum+=A[i];
        sum_sqr+=A[i]*A[i];
    }
    float mean=sum/n;
    string ans = to_string (mean*mean - sum_sqr/n);
    int i;
    for(i=0;i<ans.length();i++){
        if(ans[i]=='.'){
             if(ans[i+3] >='5')
                ans[i+2]++;
             break;
         }        
    }
    if(ans[0]=='-')
        return ans.substr(1,i+2);
    return ans.substr(0,i+2);
}
