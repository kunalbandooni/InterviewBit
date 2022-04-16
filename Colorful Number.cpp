int Solution::colorful(int A) {
    // store each digit in a vector
    vector<int> a;
    while(A){
        a.push_back(A%10);
        A=A/10;
    }

    // push each digit in the set
    //      if already found, DUPLICATE!!
    unordered_set<int> s;
    for(int i=0;i<a.size();i++){
        if(s.find(a[i]) != s.end())
            return 0;
        s.insert(a[i]);
    }

    // push each combination in set now
    //      and check for duplicates
    for(int i=0;i<a.size();i++){
        int mul = a[i];
        for(int j=i+1;j<a.size();j++){
            mul = mul * a[j];
            if(s.find(mul) != s.end())
                return 0;
            s.insert(mul);
        }
    }
    
    // surely a "colorful number"
    return 1;
}
