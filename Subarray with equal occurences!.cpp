/*
Using unordered_maps
TC: O(n)
SC: O(n)
*/
int Solution::solve(vector<int> &A, int B, int C) {
    int n=A.size(),ans=0,cnt=0;
    unordered_map<int,int>r;
    for(int i=0;i<n;i++){
        if(A[i]==B)
            cnt++;

        if(A[i]==C)
            cnt--;
        
        if(cnt==0)
            ans++;
        
        ans+=r[cnt];
       
        r[cnt]++;
    }
    return ans;
}



/*
Basic Approach that comes to mind

TC : O(n*n)

SC : O(1)

*/
int Solution::solve(vector<int> &A, int B, int C) {
    int count = 0;
    for (int i = 0; i < A.size() ; i++){
        int total_A = 0;
        int total_B = 0;
        for (int j = i; j < A.size() ; j++){
            if (A[j] == B){
                total_A++;
            }
            else if (A[j] == C){
                total_B++;
            }
            if(total_A == total_B){
                count++;
            }
        }
    }
    return count;
}
