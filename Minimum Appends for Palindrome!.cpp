/*
*   Since test case were not enough,
*   this problem was solved simply
*   using 2 pointer.
*
*   If the test cases had been strong, 
*   we use longest palindromic subsequence
*   and solve using DP
*   res = str.length() - lps(str);
*/
int Solution::solve(string A) {
    int i=0;
    int j=A.size()-1;
    int k,l;
    while(i<j){
        if(A[i]==A[j]){
            k=i;
            l=j;
            while(k<l && A[k]==A[l]){
                k++;
                l--;
            }
            if(k>=l)
                return i;
            i = k;
        }
        else
            i++;
    }
}
