/*
Method- 1

A simple solution is to consider every element one by one. For every element, compare it with all elements on the left and all elements on right.
Time Complexity- O(N^2)
Space Complexity- O(1)

Method- 2
An Efficient Solution can solve this problem in O(N) time using O(N) extra space. Below is detailed solution.

Create two arrays leftMax[] and rightMin[].
Traverse input array from left to right and fill leftMax[] such that leftMax[i] contains maximum element from 0 to i-1 in input array.
Traverse input array from right to left and fill rightMin[] such that rightMin[i] contains minimum element from to N-1 to i+1 in input array.
Traverse input array. For every element A[i], check if A[i] is greater than leftMax[i] and smaller than rightMin[i]. If yes, return 1.
If loops exits and no such element found return 0
Time Complexity- O(N)
Space Complexity- O(N)

Method- 3

A Further Optimization to the above approach is to use only one extra array and traverse input array only twice.
The first traversal is the same as above and fills leftMax[]. Next traversal traverses from the right and keeps track of the minimum. The second traversal also finds the required element.

Time Complexity- O(N)
Space Complexity- O(N)
*/
int Solution::perfectPeak(vector<int> &A) {
    int max1=A[0];

    int minSufix[A.size()];
    minSufix[A.size()-1]=A[A.size()-1];

    for(int i=A.size()-2;i>=0;i--)
        minSufix[i]=min(A[i],minSufix[i+1]);

    for(int i=1;i<A.size()-1;i++){
        if(A[i]>max1 && minSufix[i+1]>A[i] )
            return 1;
        if(A[i]>max1)
            max1=A[i];
    }
    return 0;
}
