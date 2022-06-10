/*

Bit magic here helps to find out the ith bit of the required element and
for that we have to iterate the whole array the MAX bit size for the given
integers in the qn. (i.e. 4byes=32 bits here).

Logic: in each iteration count the no. of 1’s and no. of 0’s in that ith bit 
position using ‘&’ operator to check if ith bit is set or not. then the 
ith bit of the required no. will be 0 if no. of 0’s aren’t multiple of 3
else it’s 1.

Note: Multiple of 3 : because when a no. is repeated 3 times then every bit 
of that no. will be occurring 3 times 
ex. 5=101 -> 3 times repeating -> 101. 101. 101. 
here we can see 0th,1st,2nd bits are occurring 3 times so considering all the 
elements in the array we will have no. of 0’s and no. of 1’s in multiples of
3 and only the required number will change that multiple by adding its bit
to the total…

*/

int Solution::singleNumber(const vector<int> &A) {
    int ans=0,len=A.size(),even,odd,p=1;
    for(int i=0;i<32;i++) {
        even=0;
        odd=0;
        for(int j=0;j<len;j++) {
            int x=p&A[j];
            if(x==0)
                even++;
            else
                odd++;
        }
        if(odd%3!=0)
            ans+=p;
        p*=2;
    }
    return ans;
}
