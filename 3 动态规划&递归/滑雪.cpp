// http://bailian.openjudge.cn/practice/1088/
// dp[i][j]: 从(i, j)出发的最长下降路径的长度
// 记忆化搜索

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > dp(110, vector<int>(110, -1));
vector<vector<int> > height(110, vector<int>(110, -1));
int R, C;

int cal_length(int start_x, int start_y){
    if(dp[start_x][start_y] != -1)
        return dp[start_x][start_y];
    int dx[4] = {-1, 0, 0,1};
    int dy[4] = {0, -1, 1,0};
    int max_res = 0;
    for(int i = 0; i < 4; i++){
        int x = start_x + dx[i];
        int y = start_y + dy[i];
        if(x >= 1 && x <= R && y >= 1 && y <= C){
            if(height[x][y] < height[start_x][start_y]){
                int res;
                if(dp[x][y] == -1){
                    res = cal_length(x, y) + 1;
                }
                else
                    res = dp[x][y] + 1;
                max_res = max(max_res, res);
            }
        }
    }
    dp[start_x][start_y] = max_res;
    return max_res;
}

int main(){
    cin >> R >> C;
    for(int i = 1; i <= R; i++){
        for(int j = 1; j <= C; j++){
            cin >> height[i][j];
        }
    }
    int max_len = 0x80000000;
    for(int i = 1; i <= R; i++){
        for(int j = 1; j <= C; j++){
            dp[i][j] = cal_length(i, j);
            max_len = max(max_len, dp[i][j]);
        }
    }
    cout << max_len + 1 << endl;    // 输出的是区域长度（= 路径长度 + 1）
    return 0;
}