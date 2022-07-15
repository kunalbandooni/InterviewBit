// The iswalnum() is a built-in function in C++ STL which checks
//   if the given wide character is an alphanumeric character or not
int Solution::isPalindrome(string A) {
    int i=0,j=A.size()-1;
    while(i<=j){
        if(iswalnum(A[i]) && iswalnum(A[j])){
            if(A[i]!=A[j] && abs(A[i]-A[j])!=32)return 0;
            i++;j--;
        }
        else if(iswalnum(A[i]))
            j--;
        else if(iswalnum(A[j]))
            i++;
        else {
            i++;
            j--; // both not alphanumeric
        }
    }
    return 1;
}
