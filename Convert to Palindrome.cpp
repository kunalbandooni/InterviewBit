/*
We can solve this problem by finding the position of mismatch.
We start looping in the string by keeping two pointers at both 
the ends which traverse towards mid position after each iteration,
this iteration will stop when we find a mismatch, as it is allowed
to remove just one character we have two choices here,

At mismatch, either remove character pointed by left pointer 
or remove character pointed by right pointer.

We will check both the cases, remember as we have traversed equal 
number of steps from both sides, this mid string should also be a 
palindrome after removing one character, so we check two substrings,
one by removing left character and one by removing right character 
and if one of them is palindrome then we can make complete string
palindrome by removing corresponding character, and if both substrings 
are not palindrome then it is not possible to make complete string 
a palindrome under given constraint.

Time Complexity : O(len(A))
Space Complexity : O(1)

*/

int Solution::solve(string A) {
    int n = A.size();
    int m =n/2;
    int count=0;
    int end= n-1;
    int start =0 ;
    int chk=0;
    bool flag = true;
    // for loop when we only increment start once
    for(int i=0;i<n;i++){   
        if(chk>=n)
            break;// To check no chnace of runtime error due to out of range index
        if(A[start]==A[end]){
            start++;
            end--;
            chk=chk+2;
        }
        else{
            count++;
            start++; 
            chk++;
            if(count==2){
                flag= false;
                break;
            }
        }
    }
    chk=0;
    end=n-1;
    start=0;
    count=0;
    // for loop when we only decrement end once
    if(flag==false){  
        flag =true;
        for(int i=0;i<n;i++){
            if(chk>=n)break;
            if(A[start]==A[end]){
                start++;
                end--;
                chk=chk+2;
            }
            else{  
                count++;
                end--;
                chk++;
                if(count==2){
                    flag= false;
                    break;
                }
            }
        }
    }
    if(flag)
        return 1;
    return 0;
}
