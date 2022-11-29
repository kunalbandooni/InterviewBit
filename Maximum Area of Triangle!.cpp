int Solution::solve(vector<string> &v) {
    int n = v.size();
    int m = v[0].size();
    int ans = 0;
    int leftRight[3][2] = {{n,-1},{n,-1},{n,-1}};
    for(int j = m-1 ; j >= 0 ; j--){
        for(int i = 0 ; i < n ; i++){
            int index = -1;
            if(v[i][j] == 'r') index = 0;
            else if(v[i][j] == 'b') index = 1;
            else index = 2;
            leftRight[index][0] = min(j,leftRight[index][0]);
            leftRight[index][1] = max(j,leftRight[index][1]);
        }
    }
   
    for(int j = 0 ; j < m ; j++){
        int idx[3][2] = {{n,-1},{n,-1},{n,-1}};
        for(int i = 0 ; i < n ; i++){
            int index = -1;
            if(v[i][j] == 'r') index = 0;
            else if(v[i][j] == 'b') index = 1;
            else if(v[i][j] == 'g') index = 2;
            idx[index][0] = min(idx[index][0],i);
            idx[index][1] = max(idx[index][1],i);
        }
        for(int i = 0 ; i < 3 ; i++){
            for(int J = 0 ; J < 3 ; J++){
                if(i == J) continue;
                int k = 3-i-J;
                int base = max(0,idx[J][1]-idx[i][0]+1);
                int height = max(j-leftRight[k][0]+1,leftRight[k][1]-j+1);
                height = max(0,height);
                ans = max(ans,(base*height+1)/2);
            }
        }
    }
    return ans;
}
