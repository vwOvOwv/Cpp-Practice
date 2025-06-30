// http://dsa.openjudge.cn/stack/0310/

#include <bits/stdc++.h>

using namespace std;

class Node{
public:
    int x, y;
    bool has_key;
    Node *prev;
    Node(int _x, int _y, int _has_key, Node *_prev=NULL): x(_x), y(_y), has_key(_has_key), prev(_prev){}
};

int X, Y;
vector<string> maze;
vector<vector<vector<bool>>> visited;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void bfs(int start_x, int start_y){
    queue<Node> q;
    q.push(Node(start_x, start_y, false, NULL));
    visited[start_x][start_y][0] = true;

    while(!q.empty()){
        Node &cur = q.front();
        q.pop();
        if(maze[cur.x][cur.y] == 'C' && cur.has_key){
            Node *tmp = &cur;
            vector<pair<int, int>> res;
            while(tmp->prev != NULL){
                // cout << tmp->x << ' ' << tmp->y << endl;
                res.push_back(make_pair(tmp->x, tmp->y));
                tmp = tmp->prev;
            }
            res.push_back(make_pair(start_x, start_y));
            int len = res.size();
            for(int i = len - 1; i >= 0; i--){
                cout << res[i].first + 1 << ' ' << res[i].second + 1 << endl;
            }
            return;
        }
        for(int i = 0; i < 4; i++){
            int x = cur.x + dx[i];
            int y = cur.y + dy[i];
            if(x >= 0 && x < X && y >= 0 && y < Y &&
            maze[x][y] != '1'){
                bool has_key = cur.has_key;
                if(maze[x][y] == 'Y'){
                    has_key = true;
                }
                if(!visited[x][y][has_key]){
                    visited[x][y][has_key] = true;
                    q.push(Node(x, y, has_key, &cur));
                }
            }
        }
    }
}

int main(){
    cin >> X >> Y;
    maze.assign(X, "");
    visited.assign(X, vector<vector<bool>>(Y, vector<bool>(2, false)));
    int start_x, start_y;
    for(int i = 0; i < X; i++){
        cin >> maze[i];
        for(int j = 0; j < Y; j++){
            if(maze[i][j] == 'R'){
                start_x = i;
                start_y = j;
            }
        }
    }

    bfs(start_x, start_y);

    return 0;
}