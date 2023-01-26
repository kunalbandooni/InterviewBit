vector<int> Solution::subUnsort(vector<int> &A) {
    vector<int>ans;
    int i=0;
    int j=A.size()-1;
   
    while(i<A.size()-1 && A[i]<=A[i+1])
        i++;
   
    while(j>0 && A[j]>=A[j-1] )
        j--;
   
    if(i==A.size()-1){
        ans.push_back(-1);
        return ans;
    }
    int minele=INT_MAX;
    int maxele=INT_MIN;
   
    for(int k=i;k<=j;k++){
        minele=min(minele,A[k]);
        maxele=max(maxele,A[k]);
    }
   
    int l=0;
    int r=A.size()-1;
   
    while(l<=i && A[l]<=minele)
        l++;
   
    while(r>=j && A[r]>=maxele)
        r--;

    ans.push_back(l);
    ans.push_back(r);
    return ans;   
}
