vector<vector<int> > Solution::solve(vector<int> &A, int B, int C) {
   
    int n = A.size();
    int ptr = 0;
    vector<vector<int>> ans(B,vector<int>(C,0));
    int top = 0, bottom = B-1; //row
    int left = 0, right = C-1; //col
   
    while(top <= bottom && left <= right)
    {
        //filling the upper row
        for(int i = left; i <= right; i++)
        {
            ans[top][i] = A[ptr++];
        }
        top++;
       
        //filling right column
        for(int i = top; i <= bottom; i++)
        {
            ans[i][right] = A[ptr++];
        }
        right--;
       
        //filling bottom row
        //(&& top <= bottom) required for test cases like 1 x col or row x 1
        //if row is already filled ie. top > bottom skip the row
        for(int i = right; i >= left && top <= bottom; i--)
        {
            ans[bottom][i] = A[ptr++];
        }
        bottom--;
       
        //filling left column
        //if column is already filled ie. left > right skip the column
        for(int i = bottom; i >= top && left <= right; i--)
        {
            ans[i][left] = A[ptr++];
        }
        left++;
       
    }
   
    return ans;
   
}
