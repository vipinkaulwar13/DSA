// class Solution {
// public:
//     int numMagicSquaresInside(vector<vector<int>>& grid) {
//         int count = 0;
//         int n = grid.size(), m = grid[0].size();
//         for(int i = 0; i<n-3; i++){
//             for(int j = 0; j<m-3; j++){
//                 vector<int>s;
//                 vector<int>t;
//                 vector<int>flag(10, 0);
//                 for(int x = i; x<i+3; x++){
//                     int sum = 0;
//                     for(int y = j; y<j+3; y++){
//                         flag[grid[x][y]]++;
//                         sum += grid[x][y];
//                     }
//                     s.push_back(sum);
//                 }
//                 for(int x = j; x<j+3; x++){
//                     int sum = 0;
//                     for(int y = i; y<i+3; y++){
//                         sum+= grid[y][x];
//                     }
//                     t.push_back(sum);
//                 }
//                 int lcr = grid[j][j] + grid[j+1][j+1] + grid[j+2][j+2];
//                 int rcr = grid[i][j+2] + grid[i+1][j+1] + grid[i+2][j];
                
//                 int temp = 0;
//                 for(int z = 1; z<10; z++){
//                     if(flag[z] != 1) temp = 1; break;
//                 }
//                 if(temp == 1) continue;
//                 int temp2 = 0;
//                 for(int x = 0; x<s.size(); x++){
//                     if(s[x]!=t[x]){
//                         temp2 = 1;
//                         break;
//                     }
//                 }
//                 if(temp2 = 1) continue;
//                 else count++;
                
//             }
//         }
//         return count;
//     }
// };

class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();
        for (int row = 0; row + 2 < m; row++) {
            for (int col = 0; col + 2 < n; col++) {
                if (isMagicSquare(grid, row, col)) {
                    ans++;
                }
            }
        }
        return ans;
    }

private:
    bool isMagicSquare(vector<vector<int>>& grid, int row, int col) {
       
        string sequence = "2943816729438167";
        string sequenceReversed = "7618349276183492";

        string border = "";
        
        vector<int> borderIndices = {0, 1, 2, 5, 8, 7, 6, 3};
        for (int i : borderIndices) {
            int num = grid[row + i / 3][col + (i % 3)];
            border += to_string(num);
        }

        
        return (grid[row][col] % 2 == 0 && grid[row + 1][col + 1] == 5 &&
                (sequence.find(border) != string::npos ||
                 sequenceReversed.find(border) != string::npos));
    }
};