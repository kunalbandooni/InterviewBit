int funct(string A,string B, string& str)
{
    int max=INT_MIN;
    int len1=A.size(),len2=B.size();
    for(int i=1;i<=min(len1,len2);i++)
    {
        if(A.compare(len1-i,i,B,0,i)==0)
        {
            max=i;
            str=A+B.substr(i);
        }
    }
    for(int i=1;i<=min(len1,len2);i++)
    {
        if(A.compare(0,i,B,len2-i,i)==0)
        {
            max=i;
            str=B+A.substr(i);
        }
    }
    return max;
}
int Solution::solve(vector<string> &A) {
    int n=A.size();
    while(n!=1)
    {
        int l,r,maxi=INT_MIN;
        string resstr;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                string str;
                int res=funct(A[i],A[j],str);
                if(maxi<res)
                {
                    maxi=res;
                    resstr=str;
                    l=i;
                    r=j;
                }
            }
        }
        n--;
        if(maxi==INT_MIN)
        A[0]+=A[n];
        else
        {
            A[l]=resstr;
            A[r]=A[n];
        }
    }
    return A[0].size();
}
