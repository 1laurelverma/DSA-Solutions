class Solution {
public:
    vector<vector<int>>m;
    vector<vector<int>>r;
    vector<vector<int>>c;
    bool flag=false;
    /*m0 : i,j<3
    m1: 2<i<6,j<3
    m2: 5<i<9,j<3
    
    */
    void update(int &k,int &i,int &j,vector<vector<char>>& board,int z){
        r[i][k]+=z;
        c[j][k]+=z;
        if(i<3){
            if(j<3){
                m[0][k]+=z;
            }
            else if(j<6){
                m[1][k]+=z;
            }
            else{
                m[2][k]+=z;
            }
        }
        else if(i<6){
            if(j<3){
                m[3][k]+=z;
            }
            else if(j<6){
                m[4][k]+=z;
            }
            else{
                m[5][k]+=z;
            }
        }
        else{
            if(j<3){
                m[6][k]+=z;
            }
            else if(j<6){
                m[7][k]+=z;
            }
            else{
                m[8][k]+=z;
            }
        } 
    }
    bool issafe(int &k,int &i,int &j)
    {
        if(r[i][k]!=0){
            return false;
        }
        if(c[j][k]!=0){
            return false;
        }
        if(i<3){
            if(j<3){
                if( m[0][k]!=0){
                    return false;
                }
                
            }
            else if(j<6){
                if( m[1][k]!=0){
                    return false;
                }
                
            }
            else{
                if( m[2][k]!=0){
                    return false;
                }
                
            }
        }
        else if(i<6){
            if(j<3){
                if( m[3][k]!=0){
                    return false;
                }
                
            }
            else if(j<6){
                if( m[4][k]!=0){
                    return false;
                }
                
            }
            else{
                if( m[5][k]!=0){
                    return false;
                }
                
            }
        }
        else{
            if(j<3){
                if( m[6][k]!=0){
                    return false;
                }
                
            }
            else if(j<6){
                if( m[7][k]!=0){
                    return false;
                }
                
            }
            else{
                if( m[8][k]!=0){
                    return false;
                }
               
            }
        }
        return true;
    }
    void solver(vector<vector<char>>& board,int i,int j){
        if(flag){
            return;
        }
        if(i>8 ){
            flag=true;
            return;
        }
        if(j<8){
            if(board [i][j]!='.'){               
                solver(board,i,j+1);
            }
            else{
                for(int k=0;k<9;k++){
                    if(issafe(k,i,j)){
                        update(k,i,j,board,1);
                        board[i][j]=char(49+k);
                        solver(board,i,j+1);
                        //if it is completely solved than
                        if(flag){
                            return;
                        }
                        //undo;
                        board[i][j]='.';
                        update(k,i,j,board,-1);
                    }
                }   
            }
            //action           
            //rec.
            //undo the action
        }
        else{
            if(board[i][j] !='.'){               
                solver(board,i+1,0);
            }
            else{
                for(int k=0;k<9;k++){
                    if(issafe(k,i,j)){
                        update(k,i,j,board,1);
                        board[i][j]=char(49+k);
                        solver(board,i+1,0);
                        //if it is completely solved than
                        if(flag){
                            return;
                        }
                        //undo;
                        board[i][j]='.';
                        update(k,i,j,board,-1);
                    }
                }   
            }
            //action
            //rec.
            //undo the action
        }
    }
    void solveSudoku(vector<vector<char>>& board) {
        vector<int>a(9,0);
        for(int i=0;i<9;i++){
            m.push_back(a);
            r.push_back(a);
            c.push_back(a);
        }
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j] != '.'){
                    r[i][board[i][j]-'1']++;
                    c[j][board[i][j]-'1']++;
                    if(i<3){
                        if(j<3){
                            m[0][board[i][j]-'1']++;
                        }
                        else if(j<6){
                            m[1][board[i][j]-'1']++;
                        }
                        else{
                            m[2][board[i][j]-'1']++;
                        }
                    }
                    else if(i<6){
                        if(j<3){
                            m[3][board[i][j]-'1']++;
                        }
                        else if(j<6){
                            m[4][board[i][j]-'1']++;
                        }
                        else{
                            m[5][board[i][j]-'1']++;
                        }
                    }
                    else{
                        if(j<3){
                            m[6][board[i][j]-'1']++;
                        }
                        else if(j<6){
                            m[7][board[i][j]-'1']++;
                        }
                        else{
                            m[8][board[i][j]-'1']++;
                        }
                    }
                }
            }
        }
        int x=0;
        int y=0;
        solver(board,x,y);
        
    }
};
