// http://dsa.openjudge.cn/stack/0309/
#include <iostream>
#include <utility>
#include <vector>
#include <queue>

using namespace std;

class Node{
public:
    int x, y;
    int num_step;
    Node(int _x, int _y, int _num_step): x(_x), y(_y), num_step(_num_step){}
    // 优先队列默认是最大堆，为了实现最小堆（按步数从小到大），需要重载 > 运算符
    bool operator > (const Node &node) const {
        return num_step > node.num_step;
    }
};

const int N = 11;
const int INF = 0x7fffffff;
vector<vector<int>> board(N, vector<int>(N, 0));
vector<vector<pair<int, int>>> prv(N, vector<pair<int, int>>(N, make_pair(-1, -1)));

int dx[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
int dy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int check_dx[8] = {0, -1, -1, 0, 0, 1, 1, 0};
int check_dy[8] = {-1, 0, 0, 1, 1, 0, 0, -1};

void find_path(int start_x, int start_y, int end_x, int end_y){
    vector<vector<int>> dis(N, vector<int>(N, INF));
    vector<vector<int>> path_cnt(N, vector<int>(N, 0));

    priority_queue<Node, vector<Node>, greater<Node>> q;

    dis[start_x][start_y] = 0;
    path_cnt[start_x][start_y] = 1;
    q.push(Node(start_x, start_y, 0));

    while(!q.empty()){
        Node cur = q.top();
        q.pop();

        int x = cur.x, y = cur.y;
        int d = cur.num_step;

        if(d > dis[x][y]){
            continue;
        }

        for(int i = 0; i < 8; i++){
            int new_x = x + dx[i], new_y = y + dy[i];
            int check_x = x + check_dx[i], check_y = y + check_dy[i];

            if(new_x >= 0 && new_x < N && new_y >= 0 && new_y < N &&
                board[check_x][check_y] != -1){
                
                // 找到更短的路径
                if (dis[x][y] + 1 < dis[new_x][new_y]) {
                    dis[new_x][new_y] = dis[x][y] + 1;
                    path_cnt[new_x][new_y] = path_cnt[x][y];
                    prv[new_x][new_y] = make_pair(x, y);
                    q.push(Node(new_x, new_y, dis[new_x][new_y]));
                } 
                // 找到等长的另一条最短路径
                else if (dis[x][y] + 1 == dis[new_x][new_y]) {
                    path_cnt[new_x][new_y] += path_cnt[x][y];
                }
            }
        }
    }

    if(path_cnt[end_x][end_y] == 1){
        vector<pair<int, int>> shortest_path;
        int path_x = end_x, path_y = end_y;
        while(path_x != -1 && path_y != -1){
            shortest_path.push_back(make_pair(path_x, path_y));
            pair<int, int> prv_pos = prv[path_x][path_y];
            path_x = prv_pos.first;
            path_y = prv_pos.second;
        }

        int len = shortest_path.size();
        for(int i = len - 1; i >= 0; i--){
            cout << '(' << shortest_path[i].first << ',' << shortest_path[i].second << ')';
            if(i > 0){
                cout << '-';
            }
        }
        cout << endl;
    }
    else{
        cout << path_cnt[end_x][end_y] << endl;
    }
}

int main(){
    int start_x, start_y, end_x, end_y;
    int M;
    cin >> start_x >> start_y >> end_x >> end_y;
    cin >> M;
    int x, y;
    while(M--){
        cin >> x >> y;
        board[x][y] = -1;
    }
    find_path(start_x, start_y, end_x, end_y);
    return 0;
}