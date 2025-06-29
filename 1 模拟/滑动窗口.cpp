// http://dsa.openjudge.cn/stack/0301/
// 单调队列

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> nums(n, 0), max_indices, min_indices;
    deque<int> max_idx; // 保存可能成为当前窗口最大值的元素下标（按照下标从小到大的顺序）
    deque<int> min_idx; // 保存可能成为当前窗口最小值的元素下标

    int cur = 0;
    for(; cur < k; cur++){
        cin >> nums[cur];
        while(!max_idx.empty() && nums[max_idx.back()] < nums[cur])
            max_idx.pop_back(); // 被pop出去的元素都不可能是该窗口的最大值了
        max_idx.push_back(cur);
        
        while(!min_idx.empty() && nums[min_idx.back()] > nums[cur])
            min_idx.pop_back(); // 被pop出去的元素都不可能是该窗口的最小值了
        min_idx.push_back(cur);
    }
    max_indices.push_back(max_idx.front());
    min_indices.push_back(min_idx.front());

    for(; cur < n; cur++){
        cin >> nums[cur];

        // 去除已经不在窗口里的元素下标
        while(!max_idx.empty() && cur - k >= max_idx.front())
            max_idx.pop_front();
        while(!min_idx.empty() && cur - k >= min_idx.front())
            min_idx.pop_front();
        
        // 更新单调队列
        while(!max_idx.empty() && nums[max_idx.back()] < nums[cur])
            max_idx.pop_back();
        max_idx.push_back(cur);

        while(!min_idx.empty() && nums[min_idx.back()] > nums[cur])
            min_idx.pop_back();
        min_idx.push_back(cur);

        max_indices.push_back(max_idx.front());
        min_indices.push_back(min_idx.front());
    }

    int m = min_indices.size();

    for(int i = 0; i < m; i++){
        cout << nums[min_indices[i]];
        if(i < m - 1)
            cout << ' ';
    }
    cout << endl;

    for(int i = 0; i < m; i++){
        cout << nums[max_indices[i]];
        if(i < m - 1)
            cout << ' ';
    }
    cout << endl;
    return 0;
}