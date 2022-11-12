// Was not easy...

struct TrieNode{
    TrieNode* child[2];
    bool isEnd;
    TrieNode(){
        child[0]=NULL;
        child[1]=NULL;
        isEnd=false;
    }
};

void insert(TrieNode* root, int num){
    TrieNode* curr = root;
    for(int i=31;i>=0;i--){
        int bit = ((num>>i)&1);
        if(curr->child[bit]==NULL) 
            curr->child[bit]=new TrieNode();
        curr = curr->child[bit];
    }
}

int search(TrieNode* root, int num){
    TrieNode* curr = root;
    int res = 0;
    for(int i=31;i>=0;i--){
        int x = num;
        int bit = ((x>>i)&1);
        if(curr->child[1-bit]!=NULL){
            res += (1<<i);
            curr = curr->child[1-bit];
        }
        else
            curr = curr->child[bit];
    }
    return res;
}

int Solution::solve(vector<int> &A, vector<int> &B) {
    TrieNode* root = new TrieNode();
    int res = 0;
    for(auto x:A) 
        insert(root,x);
    for(auto x:B) 
        res = max(res, search(root, x));
    return res;
}
