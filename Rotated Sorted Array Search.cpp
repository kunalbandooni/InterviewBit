int Solution::search(const vector<int> &A, int B) {
    int n = A.size();
    int low = 0, high = n-1;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(A[mid] == B) 
            return mid;
        else if(A[0]<=A[mid]){          //i.e. left part is sorted
            if(A[0]<=B && B < A[mid])   //B lies on left part
                high = mid-1;
            else 
                low = mid+1;
        }
        else{               //right part is sorted
            if(A[mid] < B && B<=A[n-1])     //B lies on right part
                low = mid+1;
            else 
                high = mid-1;
        }
    }
    return -1;
}
