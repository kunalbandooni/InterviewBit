int Solution::atoi(const string A) {
    long long int num=0;
    int n = A.size();
    int j=0;
    int s =1;  // s represent the sign of number

    //conditions to check if number is positive or negative
    if(A[0]=='-'){
        j=1;
        s=-1;
    }
    if(A[0]=='+'){
        j=1;
        s=1;
    }
   
    for(int i =j ;i<n;i++){
        if(A[i]=='0'|| A[i]=='1'||A[i]=='2'||A[i]=='3'||A[i]=='4'||A[i]=='5'||A[i]=='6'||A[i]=='7'||A[i]=='8'||A[i]=='9' )
            num = num *10 + (A[i]-'0');
        else
            break;
        
        //checking overflow
        if(num > INT_MAX){
            if(s==1)
                return INT_MAX;
            else
                return INT_MIN;
        }
    }
    return s*(int)num;
}
