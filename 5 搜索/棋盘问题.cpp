// http://bailian.openjudge.cn/practice/1321/
// k-皇后问题

#include <iostream>
#include <vector>

using namespace std;

bool available(vector<vector<char> > board, int i, int j, int n){
    for(int ii = 0; ii < i; ii++){
        if(board[ii][j] == '*')
            return false;
    }
    return true;
}

int solve(vector<vector<char> > &board, int row_idx, int n, int k){
    if(k == 0)
        return 1;
    if(row_idx == n)
        return 0;
    int res = 0;
    for(int i = row_idx; i < n; i++){
        for(int j = 0; j < n; j++){
            if(board[i][j] == '#' && available(board, i, j, n)){
                board[i][j] = '*';
                k--;
                res += solve(board, i + 1, n, k);
                k++;
                board[i][j] = '#';
            }
        }
    }
    return res;
}

int main(){
    int n, k;
    while(cin >> n >> k && n != -1){
        vector<vector<char> > board(n, vector<char>(n, '#'));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> board[i][j];
            }
        }
        cout << solve(board, 0, n, k) << endl;
    }
    return 0;
}
