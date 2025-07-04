// http://noi.openjudge.cn/ch0205/8436/
// BFS + 状态压缩

// #include <bits/stdc++.h>
#include <iostream>
#include <map>
#include <utility>
#include <vector>
#include <string>
#include <queue>

using namespace std;

class Node{
public:
    int x, y;
    int time;
    int key;
    int snakes;
    
    Node(int _x, int _y, int _cur_time, int _cur_key, int _snakes):
    x(_x), y(_y), time(_cur_time), key(_cur_key), snakes(_snakes){}
    
    bool operator < (const Node &node) const {
        return node.time < time;
    }
};

vector<string> a;
map<pair<int, int>, int> snake_pos2idx;
vector<vector<vector<vector<bool>>>> visited;

int N, M;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void bfs(int start_x, int start_y){
    priority_queue<Node> q;
    q.push(Node(start_x, start_y, 0, 0, (1 << snake_pos2idx.size()) - 1));
    visited[start_x][start_y][0][(1 << snake_pos2idx.size()) - 1] = true;

    while(!q.empty()){
        Node cur = q.top();
        q.pop();

        int new_time, new_key, new_snakes;
        if(a[cur.x][cur.y] == 'T' && cur.key == M){
            cout << cur.time << endl;
            return;
        }

        for(int i = 0; i < 4; i++){
            int x = cur.x + dx[i];
            int y = cur.y + dy[i];

            if(x >= 0 && x < N &&
            y >= 0 && y < N &&
            a[x][y] != '#'){
                char next_cell = a[x][y];
                int new_time = cur.time + 1;
                int new_key = cur.key;
                int new_snakes = cur.snakes;

                if (next_cell == 'S') {
                    int snake_idx = snake_pos2idx[make_pair(x, y)];
                    if (cur.snakes & (1 << snake_idx)) {
                        new_time = cur.time + 2;
                        new_snakes = cur.snakes & ~(1 << snake_idx);
                    }
                }
                else if (next_cell >= '0' && next_cell <= '9') {
                    if (next_cell == ('0' + cur.key + 1)) {
                        new_key = cur.key + 1;
                    }
                }
                
                if (!visited[x][y][new_key][new_snakes]) {
                    visited[x][y][new_key][new_snakes] = true;  // 入队标记在边权非负时总是正确的，省内存
                    q.push(Node(x, y, new_time, new_key, new_snakes));
                }
            }
        }
    }
    cout << "impossible" << endl;
    return;
}

int main(){
    while(cin >> N >> M && N){
        int num_snakes = 0;
        a.clear();
        snake_pos2idx.clear();
        visited.clear();
        a.assign(N, string(N, '#'));
        int start_x, start_y;

        for(int i = 0; i < N; i++){
            cin >> a[i];
            for(int j = 0; j < N; j++){
                if(a[i][j] == 'K'){
                    start_x = i;
                    start_y = j;
                }
                else if(a[i][j] == 'S'){
                    snake_pos2idx[make_pair(i, j)] = num_snakes;
                    num_snakes++;
                }
            }
        }
        visited.assign(N, 
                vector<vector<vector<bool>>>(N, 
                    vector<vector<bool>>(M + 1, 
                        vector<bool>((1 << num_snakes) + 1, false))));
        bfs(start_x, start_y);
    }
    return 0;
}