// http://dsa.openjudge.cn/linearlist/0217/
// simulation

#include <iostream>
#include <vector>

using namespace std;

int N;

int main(){
    cin >> N;
    int M = 2 * N - 1;
    vector<vector<int> > vec(M, vector<int>(M, 0)); 
    vec[0][N - 1] = 1;
    int cur_x = 0;
    int cur_y = N - 1;
    for(int i = 2; i <= M * M; i++){
        if(cur_y == M - 1 && cur_x == 0){
            cur_x++;
        }
        else if(cur_x == 0){
            cur_x = M - 1;
            cur_y++;
        }
        else if(cur_y == M - 1) {
            cur_x--;
            cur_y = 0;
        }
        else if(vec[cur_x - 1][cur_y + 1] != 0) // judge at last to avoid illegal memory access 
            cur_x++;
        else {
            cur_x--;
            cur_y++;
        }
        vec[cur_x][cur_y] = i;
    }
    for(int i = 0; i < M; i++){
        for(int j = 0; j < M; j++){
            cout << vec[i][j];
            if(j != M - 1)
                cout << " ";
        }
        cout << endl;
    }
}