static bool cmp(vector<int> &a,vector<int> &b)
{
    if(a[1] != b[1]){
       return a[1]<b[1];
    }
    return a[0]>b[0];
}

int Solution::setIntersection(vector<vector<int> > &A) 
{  
    sort(A.begin(),A.end(),cmp);
   int cnt = 2; 
   int n = A.size();
   pair<int,int> p;
   p.first = A[0][1]-1; p.second = A[0][1];
   for(int i = 1; i<n; i++){
      if(p.second < A[i][0]){
          cnt = cnt+2;
          p.second = A[i][1];
          p.first = p.second - 1;
      }
      else if(p.second == A[i][0]){
          cnt++;
          p.first = p.second;
          p.second = A[i][1];
      }
      else if(p.first < A[i][0]){
          cnt++;
         if(p.second == A[i][1]){
            p.first = p.second - 1;
         }
         else{
            p.first = p.second;
            p.second = A[i][1];
         }
      }
   }
   return cnt;
}
