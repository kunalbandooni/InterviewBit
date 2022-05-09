int Solution::findMin(const vector<int> &A) {
    int n=A.size();
    int low=0, high=n-1, index=0; //index of a small number
    while(low<=high){
        int mid = (low+high)/2;
        if(A[mid]<A[index]) //as the array sorted search on left until finding small number
        {
            index=mid;
            high = mid-1;
        }
        else 
            low=mid+1; //else search on right
    }
    return A[index]; //return small number
}
