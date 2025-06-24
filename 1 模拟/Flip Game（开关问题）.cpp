// http://dsa.openjudge.cn/linearlist/0207/
// switch problem

#include <iostream>
#include <vector>

using namespace std;

int N = 4;
int K = 1 << N;
char chess[5];
vector<vector<int> > board(N, vector<int>(N));

int get_bit(int num, int bit_idx){
    return (num >> (N - bit_idx - 1)) & 0x1;
}

int cal_flip_count(int goal, int init_flip){
    vector<vector<int> > tmp_board = board;
    int flip_count = 0;
    for(int j = 0; j < N; j++){
        if(get_bit(init_flip, j)){
            flip_count++;
            tmp_board[0][j] ^= 1;
            if(j == 0){
                tmp_board[0][j + 1] ^= 1;
            }
            else if(j == N - 1){
                tmp_board[0][j - 1] ^= 1;
            }
            else{
                tmp_board[0][j - 1] ^= 1;
                tmp_board[0][j + 1] ^= 1;
            }
            tmp_board[1][j] ^= 1;
        }
    }
    for(int i = 1; i < N; i++){
        for(int j = 0; j < N; j++){
            if(tmp_board[i - 1][j] != goal){    // flip [i, j] if [i - 1, j] is not equal to goal
                flip_count++;

                tmp_board[i - 1][j] ^= 1;

                if(i < N - 1){
                    tmp_board[i + 1][j] ^= 1;
                }

                if(j == 0){
                tmp_board[i][j + 1] ^= 1;
                }
                else if(j == N - 1){
                    tmp_board[i][j - 1] ^= 1;
                }
                else{
                    tmp_board[i][j - 1] ^= 1;
                    tmp_board[i][j + 1] ^= 1;
                }

                tmp_board[i][j] ^= 1;
            }
        }
    }
    int j = 0;
    for(; j < N; j++){  // check last row
        if (tmp_board[N - 1][j] != goal){
            break;
        }
    }
    if(j == N)
        return flip_count;
    return 0x7fffffff;
}

int main(){
    for(int i = 0; i < N; i++){
        cin >> chess;
        for(int j = 0; j < N; j++){
            if(chess[j] == 'w')
                board[i][j] = 1;
            else
                board[i][j] = 0;
        }
    }
    int min_flip_count = 0x7fffffff;
    int flip_count;
    for(int n = 0; n < K; n++){ // enumerate first row
        flip_count = cal_flip_count(0, n);
        if(flip_count < min_flip_count)
            min_flip_count = flip_count;
        flip_count = cal_flip_count(1, n);
        if(flip_count < min_flip_count)
            min_flip_count = flip_count;
    }
    if(min_flip_count == 0x7fffffff)
        cout << "Impossible" << endl;
    else
        cout << min_flip_count << endl;
    return 0;
}