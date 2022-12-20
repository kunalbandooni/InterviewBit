/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
UndirectedGraphNode *Solution::cloneGraph(UndirectedGraphNode *node) {
    unordered_map<int,UndirectedGraphNode*>m;
       
    queue<UndirectedGraphNode *> q;
    q.push(node);
    UndirectedGraphNode * n=new UndirectedGraphNode(node->label);
    m[node->label]=n;
       
    while(!q.empty()){
        UndirectedGraphNode* t=q.front();
        q.pop();
           
        for(auto i:t->neighbors){
            if(m.find(i->label)==m.end()){
                m[i->label]=new UndirectedGraphNode(i->label);
                q.push(i);
            }
            (m[t->label]->neighbors).push_back(m[i->label]);
        }
    }
       
    return m[node->label];
}
