int Solution::repeatedNumber(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
     int a,cnt1=0,b,cnt2=0;
    for(int i=0;i<A.size();i++){
        if(a == A[i]) cnt1++;
       
        else if(b == A[i]) cnt2++;
       
        else if(cnt1 == 0){
            cnt1++;
            a = A[i];
        }
       
        else if(cnt2 == 0){
            cnt2++;
            b = A[i];
        }
       
        else {
            cnt1--;
            cnt2--;
        }
    }
    cnt1=0,cnt2=0;
    for(int i=0;i<A.size();i++){
        if(A[i] == a){
            cnt1++;
        }
        else if(A[i] == b){
            cnt2++;
        }
    }
   
    if(cnt1 > (float)ceil(A.size()/3)) return a;
    else if(cnt2 > (float)ceil(A.size()/3)) return b;
    else return -1;
}
