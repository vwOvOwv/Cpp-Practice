// http://bailian.openjudge.cn/practice/4127/

#include <iostream>
#include <ostream>
#include <utility>
#include <vector>
#include <queue>

using namespace std;

int N = 5;
vector<vector<int> > maze(N , vector<int>(N, 1));
vector<vector<pair<int, int> > > prv(N, vector<pair<int, int>>(N, make_pair(-1, -1)));
vector<vector<bool> > visited(N , vector<bool>(N, false));
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
void bfs(){
    queue<pair<int, int> > q;
    q.push(make_pair(0, 0));
    visited[0][0] = true;
    pair<int, int> cur;
    while(!q.empty()){
        cur = q.front();
        // cout << cur.first << ' ' << cur.second << endl;
        if(cur == make_pair(N - 1, N - 1))
            break;
        q.pop();
        int x = cur.first, y = cur.second;
        for(int i = 0; i < 4; i++){
            int xx = x + dx[i], yy = y + dy[i];
            if(xx >= 0 && xx < N && yy >= 0 && yy < N
            && maze[xx][yy] != 1 && !visited[xx][yy]){
                q.push(make_pair(xx, yy));
                prv[xx][yy] = cur;
                visited[xx][yy] = true;
            }
        }
    }
    // for(int i = 0; i < N; i++){
    //     for(int j = 0; j < N; j++){
    //         cout << '(' << prv[i][j].first << ", " << prv[i][j].second << ')' << ' ';
    //     }
    //     cout << endl;
    // }
    vector<string> res;
    int cur_x = N - 1, cur_y = N - 1;
    while(prv[cur_x][cur_y].first != -1){
        string tmp(6, ' ');
        tmp[0] = '(';
        tmp[1] = cur_x + '0';
        tmp[2] = ',';
        tmp[3] = ' ';
        tmp[4] = cur_y + '0';
        tmp[5] = ')';
        res.push_back(tmp);
        pair<int, int> next = prv[cur_x][cur_y];
        cur_x = next.first;
        cur_y = next.second;
    }
    string tmp(6, ' ');
    tmp[0] = '(';
    tmp[1] = cur_x + '0';
    tmp[2] = ',';
    tmp[3] = ' ';
    tmp[4] = cur_y + '0';
    tmp[5] = ')';
    res.push_back(tmp);
    int n = res.size();
    for(int i = n - 1; i >= 0; i--){
        cout << res[i] << endl;
    }
}

int main(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> maze[i][j];
        }
    }
    bfs();
    return 0;
}