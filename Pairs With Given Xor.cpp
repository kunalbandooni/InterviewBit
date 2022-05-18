/*
A Simple solution is to traverse each element and 
check if there’s another number whose XOR with it 
is equal to B.
This solution takes O(N2) time.

An efficient solution of this problem take O(N) time.
The idea is based on the fact that A[i] ^ A[j] is 
equal to B if and only if A[i] ^ B is equal to A[j].

Initialize result as 0.
Create an empty hash set “s”.
Do following for each element A[i] in A[]
If B ^ A[i] is in “s”, then increment result by 1.
Insert A[i] into the hash set “s”.
Return result
*/

int Solution::solve(vector<int> &A, int B) {
    int ans=0;
    unordered_map <int,int> ump;
    for(int i=0;i<A.size();i++){
        if(ump[B ^ A[i]])
            ans++;
        ump[A[i]] = 1;
    }
    return ans;
}
