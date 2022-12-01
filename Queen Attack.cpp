bool isValid(int i,int j,int n,int m){
    if(i<0 || j<0 || i>=n || j>=m)
        return false;
    return true;
}

int dx[8]={-1,-1,0,1,1,1,0,-1};
int dy[8]={0,1,1,1,0,-1,-1,-1};

int f(int i,int j,int k,vector<string>&A,int n,int m){
   
    int x=i+dx[k];
    int y=j+dy[k];
   
    int count=0;
    if(isValid(x,y,n,m)){
        if(A[x][y]=='1')
        count++;
        else
        count+=f(x,y,k,A,n,m);
    }
   return count;
}

vector<vector<int> > Solution::queenAttack(vector<string> &A) {
    int n=A.size();
    int m=A[0].size();
    vector<vector<int>> ans(n,vector<int>(m,0));
     
       for(int k=0;k<8;k++){
           for(int i=0;i<n;i++){
               for(int j=0;j<m;j++){
                   ans[i][j]+=f(i,j,k,A,n,m);
               }
           }
       }  
    return ans;  
}
