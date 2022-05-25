int Solution::romanToInt(string A) {
    map<char,int> m;
    m['I'] = 1;
    m['V'] = 5;
    m['X'] = 10;
    m['L'] = 50;
    m['C'] = 100;
    m['D'] = 500;
    m['M'] = 1000;
    
    int ans = 0, i = 0, N = A.size();
    while(i < N-1){
        if(m[A[i]] < m[A[i+1]]) 
            ans-=m[A[i]];
        else 
            ans+=m[A[i]];
        i++;
    }
    ans+=m[A[i]];
    return ans;
}
