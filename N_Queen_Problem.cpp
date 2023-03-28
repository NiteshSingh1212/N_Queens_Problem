class Solution {
public:
//map create
  unordered_map<int,bool> rowCheck;
  unordered_map<int,bool> upperLeftDiagonalCheck;
  unordered_map<int,bool> lowerLeftDiagonal;
  void StoreFullBoard(vector<vector<string>> &ans,vector<vector<char>> &board,int n){
      vector<string> temp;
        
      for(int i=0;i<n;i++){
        string output="";
          for(int j=0;j<n;j++){
            output.push_back(board[i][j]);
          }
           temp.push_back(output);
      }
      ans.push_back(temp);
  }
  bool isSafe(vector<vector<char>> &board,int row,int col,int n){
      if( rowCheck[row]==true) {
          return false;
      }
      if(upperLeftDiagonalCheck[n-1+col-row]==true){
          return false;
      }
      if(  lowerLeftDiagonal[row+col]==true){
          return false;
      }
      return true;
  }
  void solve(vector<vector<string>> &ans,vector<vector<char>> &board,int col,int n){
      //Base Case
             if(col>=n){
              StoreFullBoard(ans,board,n);
              return;
             }
             //one case solve
      for(int row=0;row<n;row++){
  if(isSafe(board,row,col,n)){
              board[row][col]='Q';
              rowCheck[row]=true;
              upperLeftDiagonalCheck[n-1+col-row]=true;
              lowerLeftDiagonal[row+col]=true;
              //baki recursion sambhalega
              solve(ans,board,col+1,n);
              //Backtracking
              board[row][col]='.';
              rowCheck[row]=false;
              upperLeftDiagonalCheck[n-1+col-row]=false;
              lowerLeftDiagonal[row+col]=false;

          }
      }
  }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<char>> board(n,vector<char>(n,'.'));
         vector<vector<string>> ans;
        solve(ans,board,0,n);
        return ans;
    }
};