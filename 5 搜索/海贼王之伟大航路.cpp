// http://bailian.openjudge.cn/practice/4124/
// 状压dp

#include <bits/stdc++.h>

using namespace std;

int min_time = 0x7fffffff;
int N;
vector<vector<int> > dis;
vector<unordered_map<unsigned, int> > visit_time_record;
unsigned visited = 0;

int get_visited_bit(int idx){
    return (visited >> idx) & 0x1;
}

void set_visited_bit(int idx, int val){
    if(val == 0){
        unsigned mask = ~(1 << idx);
        visited &= mask;
    }
    else{
        unsigned mask = 1 << idx;
        visited |= mask;
    }
}

void dfs(int start, int cur_time){
    if(start == N - 1){
        bool visit_all = true;
        for(int i = 0; i < N - 1; i++){
            if(get_visited_bit(i) == 0){
                visit_all = false;
                break;
            }
        }
        if(visit_all){
            min_time = min(min_time, cur_time);
            // cout << cur_time << endl;
        }
        return;
    }
    set_visited_bit(start, 1);
    for(int i = 1; i < N; i++){
        if(get_visited_bit(i) == 0){
            int new_time = cur_time + dis[start][i];
            if(visit_time_record[i].find(visited) == visit_time_record[i].end() || 
            visit_time_record[i][visited] > new_time){
                visit_time_record[i][visited] = new_time;
                dfs(i, new_time);
            }
        }
    }
    set_visited_bit(start, 0);
    return;
}

int main(){
    cin >> N;
    dis.assign(N, vector<int>(N, 0));
    visit_time_record.assign(N, unordered_map<unsigned, int>());
    visit_time_record[0][visited] = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> dis[i][j];
        }
    }
    dfs(0, 0);
    cout << min_time << endl;
    return 0;
}