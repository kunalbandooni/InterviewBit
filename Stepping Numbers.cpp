vector<int> Solution::stepnum(int A, int B) {
    queue< string > q;

    for(int i=1;i<=9;i++)
        q.push(to_string(i));    

    vector<int> res;   
    if(A<=0)
        res.push_back(0);
   
    while(!q.empty()){
        auto x = q.front();
        q.pop();
       
        int val = stoi(x);
       
        if(val>=A && val<=B)
            res.push_back(val);
       
        if(val>B)
            continue;
       
        string s1=x;
        string s2=x;
        char ch = x.back();
       
        if(ch>='1'){
            s1.push_back(ch-1);
            q.push(s1);
        }
       
        if(ch<='8'){
            s2.push_back(ch+1);
            q.push(s2);
        }
    }
    return res;
}
