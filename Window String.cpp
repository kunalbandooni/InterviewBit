string Solution::minWindow(string s, string t) {
    int n = t.size();
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++){
        mp[t[i]]++;
    }
   
    int i = 0, j = 0, count = mp.size();
    string ans;
    while(j<s.size()){
        if(mp.find(s[j]) != mp.end()){
            mp[s[j]]--;
       
            if(mp[s[j]] == 0) count--;
           
            while(count == 0){
                if(ans == ""){
                    ans = s.substr(i,j-i+1);
                }
                else if(j-i+1 < ans.size()){
                ans = s.substr(i,j-i+1);
                }
           
                if(mp.find(s[i]) != mp.end()){
                    if(mp[s[i]] == 0){
                        count++;
                    }
                    mp[s[i]]++;
                }
                i++;
            }
           
        }
            j++;
       
    }
   
    return ans;
}
