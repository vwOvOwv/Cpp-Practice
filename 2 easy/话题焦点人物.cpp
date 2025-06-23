// http://bailian.openjudge.cn/xly2024062702/B/
// vector和unordered_map简单模拟即可

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int N;
int a, k, b;

vector<int> cnt(110, 0);
unordered_map<int, vector<int> > record;

int main(){
    cin >> N;
    int max_idx = -1;
    while(N--){
        cin >> a >> k;
        for(int i = 0; i < k; i++){
            cin >> b;
            max_idx = max(max_idx, b);
            cnt[b]++;
            record[b].push_back(a);
        }
    }
    int maximum = 0;
    int max_i = 0;
    for(int i = 1; i <= max_idx; i++){
        if(cnt[i] > maximum){
            maximum = cnt[i];
            max_i = i;
        }
    }
    cout << max_i << endl;
    vector<int> rec = record[max_i];
    sort(rec.begin(), rec.end());
    rec.erase(unique(rec.begin(), rec.end()), rec.end());
    int n = rec.size();
    for(int i = 0; i < n; i++){
        cout << rec[i];
        if(i < n - 1)
            cout << ' ';
    }
    cout << endl;
    return 0;
}