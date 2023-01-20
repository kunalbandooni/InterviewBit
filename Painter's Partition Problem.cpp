#define ll long long
#define pp pair< int , int >
bool func(vector<int> &nums , ll mid , int A)
{
    int n=nums.size();
    int count=1;
    // here we have to find the max paint to put
    ll sum=0;
   
    for(int i=0;i<nums.size();i++)
    {
        if(nums[i]>mid)
        {
            return false;
        }
       
        if(sum+nums[i]<=mid)
        {
            sum+=nums[i];
        }
        else{
           sum=nums[i];
           count++;
        }
    }  
    return count <= A;
}
int Solution::paint(int A, int B, vector<int> &nums) {
    int n=nums.size();
    ll l = *max_element(nums.begin() , nums.end());
    ll r=0;
    for(int i=0;i<nums.size();i++)
    {
        r+=nums[i];
    }
   
    if(A>=nums.size())
    {
        return (int)l * B;
    }   
    int mod=10000003;
    ll res=-1;

    while(l<=r)
    {
        ll mid=(l+(r-l)/2);  
        if(func(nums , mid , A ))
        {
            res=mid;
            r=mid-1;
        }
        else
        {
            l=mid+1;
        }
    }
    res = (res%mod * B%mod)%mod;  
    return (int)(res + mod) % mod;
}
