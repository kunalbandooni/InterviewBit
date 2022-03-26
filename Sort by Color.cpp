// TC: O(n)      SC: O(1)
// TWO POINTER APPROACH
void Solution::sortColors(vector<int> &a) {
    int zero=0,one=0,two=a.size()-1;
    while(one<=two){
        switch(a[one]){
            case 0:         // Bring '0' to front
                swap(a[one],a[zero]);
                one++;
                zero++;
                break;
            case 1:         // Keep '1' in between
                one++;
                break;
            case 2:         // Send '2' to end
                swap(a[one],a[two]);
                two--;
        }
    }
}

// TC: O(n)      SC: O(1)
// HASHING
void Solution::sortColors(vector<int> &a) {
    int m[3]={0};
    for(int i=0;i<a.size();i++){
        m[a[i]]++;
    }
    int k=0;
    for(int i=0;i<3;i++)
        for(int j=0;j<m[i];j++)
            a[k++]=i;
}
