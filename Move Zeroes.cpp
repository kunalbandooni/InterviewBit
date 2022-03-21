vector<int> Solution::solve(vector<int> &nums) {
        int j = 0;
        // move all the nonzero elements advance
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] != 0)
                nums[j++] = nums[i];
        for (;j < nums.size(); j++)
            nums[j] = 0;
        return nums;
}
/*vector<int> Solution::solve(vector<int> &A) {
    int low=0,high=0;
    while(high!=A.size()-1){
        while(A[low]!=0 && low!=A.size()-1)
            low++;
        if(high==0)
            high=low;
        while(A[high]==0 && high!=A.size()-1)
            high++;
        swap(A[low],A[high]);   
    }
    return A;
}
*/
