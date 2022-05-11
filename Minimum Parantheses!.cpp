/*

Explanation:

We keep the track of balance of the string i:e the number 
of ‘(‘ minus the number of ‘)’. A string is valid if its 
balance is 0, and also every prefix has non-negative balance.

Now, consider the balance of every prefix of A. If it is 
ever negative (say, -1), we must add a ‘(‘ bracket at the
beginning. Also, if the balance of S is positive (say, +P), 
we must add P times ‘)’ brackets at the end.

Time Complexity: O(A)

*/
// Fastest Solution
int Solution::solve(string A){
    int i,count,len,k;
    len=A.length();count=0,k=0;
    for(i=0;i<len;i++){
        if(A[i]=='(')
          count++;
        else{
            if(count>0) count--;
            else k++;
        }
    }
    k=k+count;
    return(k);
}

/*int Solution::solve(string A) {
    int n = A.length();
    stack <char> st;
    int c=0;

    for(int i=0;i<n;i++){
        if(A[i]=='(')
            st.push(A[i]);
        else{
            if(!st.empty() && st.top()=='(')
                st.pop();
            else
                st.push(A[i]);
        }
    }

    while(!st.empty()){
        c++;
        st.pop();
    }
    return c;
}*/
