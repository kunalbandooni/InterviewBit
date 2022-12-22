string Solution::multiply(string s1, string s2) {
    int m1=s1.size();
    int m2=s2.size();

    if(s1=="0" || s2=="0")  return "0";

    string ans="";
    int carry=0;
    string temp="";
    for(int j=m2-1;j>=0;j--){
        temp+='0';
        string res=temp;
        res.pop_back();

        carry=0;

        int val=s2[j]-'0';

        for(int i=m1-1;i>=0;i--){
            int x= (s1[i]-'0')*val;
            x+=carry;
            res.push_back('0' + (x%10));
            carry=x/10;
        }
        while(carry>0){
            res.push_back('0' + (carry%10));
            carry=carry/10;
        }

        reverse(res.begin(),res.end());

        if(ans==""){
              ans=res;
              continue;
        }

        carry=0;

        // now add
        string t="";

        int k1=ans.size();
        int k2=res.size();

        int a=k1-1;
        int b=k2-1;
        val=0;
        while(a>=0 || b>=0){
            val=0;
            if(a>=0){
                val+=(ans[a]-'0');
                a--;
            }

            if(b>=0){
                val+=(res[b]-'0');
                b--;
            }
            val+=carry;
            t.push_back('0' + (val%10));
            carry=val/10;
        }

        while(carry>0){
            t.push_back('0' + (carry%10));
            carry=carry/10;
        }

        reverse(t.begin(),t.end());
        ans=t;
    }
    int i=0;
    while(i<ans.size() && ans[i]=='0'){
        i++;
    }
    if(i==ans.size())   return "0";
    return ans.substr(i);
}
