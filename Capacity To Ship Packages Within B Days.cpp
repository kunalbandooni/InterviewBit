#include <numeric>
int Solution::solve(vector<int> &weights, int days) {
    int min = *max_element(weights.begin(),weights.end());
    int max = accumulate(weights.begin(),weights.end(),0);
       
    if(days == weights.size()) return min;
    if(weights.empty() || days == 0) return 0;
       
    int ans = 0;
    while(max>min){
        int mid = (max+min)/2;
        int sum = 0,count=1;
        for(int i=0;i<weights.size();i++){
            if(sum+weights[i]>mid){
               sum=0;
               count++;
            }
            sum+=weights[i];
        }
        if(count>days){
            min = mid+1;
        }
        else{
            max = mid;
        }
    }
    return min;
}
