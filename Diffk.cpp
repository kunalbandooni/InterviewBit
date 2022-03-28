int Solution::diffPossible(vector<int> &A, int B) {
    // GO DOWN TO NAIVE APPROACH, THEN COME BACK HERE
  
  /*
  
  Now, let us say that for i = I, we we exploring j.

  At j = J - 1, our difference D1 was less than diff
  At j = J, our difference D2 exceeded diff.
  When i = I + 1, our A[i] increases ( as the array is sorted ).
  So, for j = J - 1, the differece will be smaller than D1
  (which is even more smaller to diff.)
  Which means we do not need to explore j <= J - 1
  and we can begin exploring directly from j = J.
  So, j only keeps moving in forward direction and never needs 
  to come back as i increases.
  
  Hence, solution...
  
  */
  
    int l=0,r=1,n=A.size();
    while(l<n and r<n){
        if(A[r] - A[l] == B and l!=r)
            return 1;
        if(A[r] - A[l] > B)
            l++;
        else
            r++;
    }
    return 0;
  
  /*
  // NAIVE METHOD
  
  for (int i = 0; i < len; i++) {
    for (int j = i + 1; j < len; j++) {
      if (A[j] - A[i] > diff) 
        break; 
        // No need going forward as the difference is going to increase even further. 
      if (A[j] - A[i] == diff) 
        return true; 
    }
  }
  
  */
  
}
