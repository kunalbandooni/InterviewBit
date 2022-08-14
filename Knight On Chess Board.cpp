int Solution::knight(int A, int B, int C, int D, int E, int F) {
    int m[8][2] = {{-2,-1}, {-2,1}, {2,1}, {2,-1}, {1,2}, {-1,2}, {1,-2}, {-1,-2}};
    queue<pair<int,int>> q;
    q.push({C,D});
    int vis[A+1][B+1] = {0};
    vis[C][D] = 1;
    int steps = 0;
    
    while(!q.empty()){
        int s = q.size();
        while(s--){
            pair<int, int> p = q.front();
            q.pop();
            int x = p.first, y = p.second;
   
            if(x == E and y == F)
                return steps;
            
            for(int i=0;i<8;i++){
                int cx = x + m[i][0];
                int cy = y + m[i][1];
            
                if(cx > 0 and cy > 0 and cx <= A and cy <= B and !vis[cx][cy]){
                    vis[cx][cy] = 1;
                    q.push({cx,cy});
                }
            }
        }
        steps++;
    }
    return -1;
}
