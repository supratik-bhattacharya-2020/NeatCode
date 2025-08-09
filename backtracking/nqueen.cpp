class Solution {
public:
    bool isValid(vector<string>&sub,int row,int col,int n){
        //check row
        //not needed as we are coming from row 1 to n, there is directionality
        //check col
        for(int i=0;i<n;i++){
            if(sub[i][col]=='Q'){
                return false;
            }
        }
        //check fwd diagonal
        //directionality of rows to keep in mind
        for(int i=row-1,j=col-1;i>=0&&j>=0;i--,j--){
            if(sub[i][j]=='Q'){
                return false;
            }
        }

        for(int i=row-1,j=col+1;i>=0&&j<n;i--,j++){
            if(sub[i][j]=='Q'){
                return false;
            }
        }
        return true;
    }
    void b(vector<vector<string>>&res,vector<string>&sub,int n,int row){
        if(row==n){
            res.push_back(sub);
            return;
        }
        if(row>=n||row<0){
            return;
        }
        for(int j=0;j<n;j++){
            if(row==0){
                sub[row][j] = 'Q';
                b(res,sub,n,row+1);
                sub[row][j] = '.';
            }
            else{
                if(isValid(sub,row,j,n)){
                    sub[row][j] = 'Q';
                    b(res,sub,n,row+1);
                    sub[row][j] = '.';
                }
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> sub;
        if (n==2||n==3){
            return res;
        }
        for(int i=0;i<n;i++){
            string str = "";
            for(int j=0;j<n;j++){
                str+= ".";
            }
            sub.push_back(str);
        }
        b(res,sub,n,0);
        return res;
    }
};
