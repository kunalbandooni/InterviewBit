bool check(int i, int j,int m , int n, vector<string>&A,string B,int ind){
    if(i<0 || i==m || j<0 || j==n || A[i][j]!=B[ind])
        return false ;
    
    if(ind==B.size()-1)
        return true;
    
    if( check(i+1,j,m,n,A,B,ind+1) || check(i-1,j,m,n,A,B,ind+1) || check(i,j+1,m,n,A,B,ind+1)|| check(i,j-1,m,n,A,B,ind+1))
        return true;
    return false;
}
int Solution::exist(vector<string> &A, string B) {
    int m=A.size();
    int n=A[0].size();
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(A[i][j]==B[0]){
                if(check(i,j,m,n,A,B,0))
                    return true;
            }
        }
    }
    return false;
}
