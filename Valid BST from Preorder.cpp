void makeBST(vector<int>& A, int &index, int low, int high){

    if(index >= A.size()) return; //preorder vector exhausted, means whole tree can be created

    if(A[index] <= low || A[index] >= high) return; // it means element cannot be pushed to either left or right

                                                    // by returning checking for parent node, to push element at right

    int root = A[index]; // value of root for limits

    index++;

    makeBST(A, index, low, root); //left call, higher limit will be root's data

    makeBST(A, index, root, high); //right call, lower limit will be root's data

}



int Solution::solve(vector<int> &A) {

    int index = 0;

    int low = INT_MIN; //for root node lower limit is

    int high = INT_MAX; // upper limit

    

    makeBST(A, index, low, high);

    if(index < A.size()) return false; // makeBST function returned in between, it was not possible to make a BST

    return true;

}
