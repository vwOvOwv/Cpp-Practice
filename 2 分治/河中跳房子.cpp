// http://noi.openjudge.cn/ch0111/10/
// 求min-max/max-min 一般用二分查找


#include <iostream>
#include <vector>

using namespace std;

int main(){
    int L, M, N;
    cin >> L >> N >> M;
    vector<int> pos(N + 2, 0);
    int min_dis = 0x7fffffff;
    for(int i = 1; i <= N; i++){
        cin >> pos[i];
        min_dis = min(min_dis, pos[i] - pos[i - 1]);
    }
    pos[N + 1] = L;
    min_dis = min(min_dis, pos[N + 1] - pos[N]);
    int lower_bound = min_dis;
    int upper_bound = L;
    int mid;
    while(lower_bound <= upper_bound){
        // cout << lower_bound << ' ' << upper_bound << endl;
        mid = lower_bound + (upper_bound - lower_bound) / 2;
        // cout << mid << endl;
        int removed_cnt = 0;
        int tmp_dis = 0;
        for(int i = 1; i <= N + 1; i++){
            int dis = pos[i] - pos[i - 1];
            if(dis + tmp_dis < mid){
                removed_cnt++;
                tmp_dis += dis;
            }
            else{
                tmp_dis = 0;
            }
        }
        // cout << removed_cnt << endl;
        if(removed_cnt > M){
            upper_bound = mid - 1;
        }
        else{
            lower_bound = mid + 1;
        }
    }
    cout << upper_bound << endl;
    return 0;
}
