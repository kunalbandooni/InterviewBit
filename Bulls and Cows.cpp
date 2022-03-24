string Solution::solve(string A,string B){
    string s="";
    int b=0;
    map<int,int> m1,m2;
    for(int i=0;i<A.length();i++){
        if(A[i]==B[i])
            b++;
        m1[A[i]]++;
        m2[B[i]]++;
    }
    int sum=0;
    for(int i=0;i<m1.size();i++){
        if(m1[i]==m2[i])
            sum+=m1[i];
        else
            sum+=(m1[i]>m2[i]?m2[i]:m1[i]);
    }
    sum=sum-b;
    s=to_string(b)+"A"+to_string(sum)+"B";
    return s;
}
