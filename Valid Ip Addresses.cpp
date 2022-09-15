/*
1>Use Backtracking Few hints ----
2>Every string before decimal and btween decimal is seperate string.
3>Use substr STL to take out strings from IP…to form 4 such strings by running loop from 1 to 3.
3’>use stoi to convert string to int ie stoi(“234”) and check is it greater than 256 or not.
4>s.substr(index,len) index is starting index and len is the len of the substring .
5>index pointer will run to whole string in recursive calls ie recu(index +1,x,y,z,)
6>A.B.C.D every letter is seperate string remember.
6’> A,B,C,D should not be grater than 256.
7>// 013(A).123(B).234©.012(D) is not valid is len >1 and A[0]=0(before first decimal string ie A) ;
8>//0.123 .1xx.2yy .is valid as single 0 allowed with len =1;
9>//After forming last string D no need to put decimal.
10>//when you form part A increase to cnt=1 and concentate to ans ;B=cnt=2 . C= cnt=3 D ->cnt =4
11>//when cnt ==4 and index=s.length() this means you got your answer then push in ans vector and then return .
else
12>directly return .(invalid case so directly return )
*/

void fun(string s,vector<string>&ans,string temp,int index ,int cnt){
    if(cnt==4 && index==s.length()){
        ans.push_back(temp);
        return ;
    }
    else if(cnt==4)
       return ;
    
    
    for(int len=1;len<=3;len++){
        if(index +len>s.length())
            break;
        string t = s.substr(index,len);
        int x = stoi(t);
        if(len>1 && t[0]=='0'  || x>256)
           break;
        if(cnt<3)
            fun(s,ans,temp+t+".",index+len , cnt+1);
        else
           fun(s,ans,temp+t,index+len , cnt+1 );
    }
}
vector<string> Solution::restoreIpAddresses(string A) {
    vector<string> ans;
    //helper(A, 0 , "", 1, ans);
    fun(A, ans, "", 0, 0);
    return ans;
}
