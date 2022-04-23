// MAJDOORI and MAJBOORI
vector<int> Solution::spiralOrder(const vector<vector<int> > &A) {
    int szeA=A.size(),szeB=A[0].size();
    int m=A.size(),n=A[0].size();
    vector<int> res;
    int i=0,j=1,k=n-2,p=m-2,r=0,q=1,x=0,y=0;
    while(szeA>0&&szeB>0){
        vector<int> temp=res;
        int a;
        for(a=i; a<n&&y<m; a++)
            res.push_back(A[y][a]);
        i++;
        y++;
        int b;
        for(b=j; b<m; b++)
            res.push_back(A[b][n-1]);
        j++;
        int c;
        for(c=n-2; c>=r&&r<m-1; c--)
            res.push_back(A[m-1][c]);
        r++;
        k--;
        int d=p;
        for(d=m-2; d>=q&&x<n-1; d--)
            res.push_back(A[d][x]);
        x++;
        p--;
        q++;
        n--;
        m--;
        szeA-=2;
        szeB-=2;
        if(res==temp)
            return res;
    }
    return res;
}
