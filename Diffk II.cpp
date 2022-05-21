int Solution::diffPossible(const vector<int> &A, int B) {
    /*
    // TC: O(n*n)

    for(int i=0;i<A.size()-1;i++)
        for(int j=i+1;j<A.size();j++)
            if(abs(A[i] - A[j]) == B)
                return 1;
    return 0;
    */

  
    // Trade time with space
    // TC: O(n)
    // SC: O(n)

    unordered_map<int,int> m;
    for(int i=0;i<A.size();i++){
        int k=B+A[i], l=A[i]-B;
        if(m.find(k)!=m.end()||m.find(l)!=m.end())
            return 1;
        m[A[i]]++;
    }
    return 0;
}
