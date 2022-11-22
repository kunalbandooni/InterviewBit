int Solution::solve(vector<int> &A, int B) {
    unordered_map<int, int> map;
    int curr_sum = 0; //prefix sum
    int count = 0; //count of all subarrays

    for(int i = 0; i<A.size(); i++){
        if(A[i] % 2 == 0) 
            A[i] = 0;
        else 
            A[i] = 1; // odd nos become 1. Now subarrays with sum = B should be found
    }
   
    for(int i = 0; i<A.size(); i++){
        curr_sum += A[i];
        if(curr_sum == B) count += 1;
        if(map.find(curr_sum - B) != map.end())
            count += map[curr_sum - B];
        map[curr_sum]++;
    }
    return count;
}
