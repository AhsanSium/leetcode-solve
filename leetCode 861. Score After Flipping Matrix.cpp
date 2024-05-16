class Solution {
public:
    /*
        In a binary number, the bits in higher-order positions carry more weight 
        in determining the decimal value than those in lower-order positions.

        Ideally, we want all bits in the first column of the matrix (first digit) to be 1
        The contribution of a column to the score of the matrix depends solely on the number of 1's in the column. 
        So, it would be ideal for us to maximize the number of 1's in each column
    */
    void flip_row(vector <int> &vec){
        for(int i = 0; i < vec.size(); i++){
            if(vec[i] == 1){
                vec[i] = 0;
            }
            else{
                vec[i] = 1;
            }
        }
    }
    void flip_column(vector<vector<int>>& vec, int row){
        for(int i = 0; i < vec.size(); i++){
            if(vec[i][row] == 1){
                vec[i][row] = 0;
            }
            else{
                vec[i][row] = 1;
            }
        }
    }
    int matrixScore(vector<vector<int>>& grid) {
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(j == 0 && grid[i][j] == 0){
                    flip_row(grid[i]);
                    continue;
                }
            }
        }

        int zero = 0, one = 0;
        for(int i = 1; i < grid[0].size(); i++){
            zero = 0; one = 0;
            for(int j = 0; j < grid.size(); j++){
                if(grid[j][i] == 0){
                    zero ++;
                }
                else{
                    one ++;
                }
            }
            if(zero > one){flip_column(grid, i);}
        }

        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                cout << grid[i][j] << " ";
            }
            cout << "\n";
        }
        int total = 0, row = 0, base = 1;
        for(int i = 0; i < grid.size(); i++){
            for(int j = grid[0].size() - 1; j >= 0; j--){
                // cout << grid[i][j] << " ";
                row = row + grid[i][j] * base;
                base = base * 2;
            }
            // cout << "\n";
            total = total + row;
            row = 0;
            base = 1;
        }

        return total;
    }
};