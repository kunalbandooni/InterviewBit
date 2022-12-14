int func(vector<int> &nums , int k ){
    // at least k
    unordered_map< int , int > mp;
    int l=0, r=0, ans=0;
    int n=nums.size();
   
    mp[nums[0]]++;
    while(r<n){
        if(mp.size()<=k){
            r++;
            if(r<n)
                mp[nums[r]]++;       
            ans+=(r-l);
        }
        else{
            mp[nums[l]]--;
            if(mp[nums[l]]==0)
                mp.erase(nums[l]);
            l++;
        }
    }      
    mp.erase(nums[l]);
    return ans;
}

int Solution::solve(vector<int> &A, int B) {
    // A good subarray has exactly k distinct numbers
    // at least k distinct number - at least (k-1) distinct numbers  
    // exactly K problem always can be done (at least k) - (at least k-1)
   
    int a1 = func(A , B);
    int a2 =  func(A , B-1);
    return a1-a2;
}
