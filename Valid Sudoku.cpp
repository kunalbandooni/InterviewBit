/*
// When I tried full solving, it gave TLE
// only then i realised... we dont have to solve,
// simply check and you are good to go :)
bool check(int board[9][9], int num, int i, int j){
    for(int k = 0; k<9; k++)
        if(board[i][k] == num or board[k][j] == num)
            return false;
    int si = i - i%3;
    int sj = j - j%3;
    for(int i=si;i<si+3;i++)
        for(int j=sj;j<sj+3;j++)
            if(board[i][j] == num)
                return false;
    return true;
}
bool solve_sudoku(int board[9][9], int i, int j){
    if(i == 9)  return true;
    if(j == 9)  return solve_sudoku(board, i+1, 0);
    if(board[i][j]!=0)
        return solve_sudoku(board, i ,j+1);
    
    for(int c = 1;c<=9;c++)
        if(check(board, c, i, j)){
            board[i][j] = c;
            if(solve_sudoku(board, i, j+1)) 
                return true;
            board[i][j] = 0;
        }

    return false;
}
int Solution::isValidSudoku(const vector<string> &A) {
    int board[9][9];
    for(int i=0;i<9;i++)
        for(int j=0;j<9;j++)
            if(A[i][j] == '.')
                board[i][j] = 0;
            else    
                board[i][j] = A[i][j] - '0';
    
    return solve_sudoku(board, 0, 0);
}*/

int valid1(int x,int y,const vector<string> &v){
    int i,j;
    for(i=0;i<9;i++)
        if(i!=y and v[x][i]==v[x][y])
            return 0;

    for(i=0;i<9;i++)
        if(i!=x and v[i][y]==v[x][y])
            return 0;
    return 1;
}
int valid2(int x,int y,const vector<string> &v){
    int t1,t2,i;
    t1=(x/3)*3;
    t2=(y/3)*3;
    for(i=0;i<9;i++)
        if((t1+i/3)!=x and (t2+i%3)!=y and v[t1+i/3][t2+i%3]==v[x][y])
            return 0;
    return 1;
}
int Solution::isValidSudoku(const vector<string> &v){
    int i,j;
    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
            if(v[i][j]!='.'){
                if(!valid1(i,j,v))  // row and column check
                    return 0;
                if(!valid2(i,j,v))  // submatrix check
                    return 0;
            }
        }
    }
    return 1;
}
