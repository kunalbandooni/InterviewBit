int Solution::solve(string A) {
    int i = 0;
    int n = A.length();
  // Skip all spaces in front
    while(A[i] == ' ')
        i++;
 
    int c = 0;
  
 // i<n means at least one word is present
    if(i < n)
        c++;
  
  // traversing loop until we reach another word
  //    while skipping all the spaces
    while(i<n-1){
        if(A[i] != A[i+1] and A[i] == ' ')
            c++;
        i++;
    }
    return c;
}
