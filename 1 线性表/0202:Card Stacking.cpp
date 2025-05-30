// http://dsa.openjudge.cn/linearlist/0202/
// simulation with deque

#include <iostream>
#include <cstdlib>
#include <deque>
#include <vector>
#include <algorithm>

using namespace std;

deque<int> queue;
int N, K, P;
vector<int> ans;

int main(){
    cin >> N >> K >> P;
    for(int i = 1; i <= K; i++){
        queue.push_back(i);
    }
    int cur = 0;
    while(!queue.empty()) {
        int cur_card = queue.front();
        queue.pop_front();
        cur = (cur + 1) % N;
        if (cur == 0){
            // cout << cur_card << endl;
            ans.push_back(cur_card);
        }
        for(int i = 0; i < P; i++){
            queue.push_back(queue.front());
            queue.pop_front();
        }
    }
    sort(ans.begin(), ans.end());
    int ans_len = ans.size();
    for (int i = 0; i < ans_len; i++)
        cout << ans[i] << endl;
    return 0;
}