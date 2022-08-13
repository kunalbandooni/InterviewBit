string Solution::solve(int A) {
    vector<int> d;
    d.push_back(1);

    for(int i=2;i<=A;i++){
        for(auto it=d.begin();it!=d.end();it++){
            *it = (*it) * i;
        }
        for(int j=0;j<d.size();j++){
            if(d[j]<10){continue;}
            if(j==d.size()-1){d.push_back(0);}
            d[j+1] += d[j]/10;
            d[j] = d[j]%10;
        }
    }

    //storing array into string
    string s;
    for(auto it=d.rbegin();it!=d.rend();it++){
        auto c = std::to_string(*it);
        s.append(c);
    }
    return s;
}
