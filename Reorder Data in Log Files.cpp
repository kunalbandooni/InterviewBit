bool custom(pair<string,string>&s1, pair<string,string> &s2){
    return s1.first < s2.first;
}

vector<string> Solution::reorderLogs(vector<string> &A) {
    vector<string>dig;
    vector<pair<string,string>>lett;
    for(auto log:A){
        if(log.back()>='a' and log.back()<='z'){
            int len=log.find('-');
            string a=log.substr(0,len);
            string b=log.substr(len);
            lett.push_back({b,a});
        }
        else
            dig.push_back(log);
    }
    sort(lett.begin(),lett.end(),custom);
    vector<string>ans;
    for(auto temp:lett)
        ans.push_back(temp.second+temp.first);
    
    for(auto j: dig)
        ans.push_back(j);
    
    return ans;
}
