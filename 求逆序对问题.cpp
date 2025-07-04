// http://bailian.openjudge.cn/xly2018/E/
// https://www.luogu.com.cn/problem/T515924

#include <bits/stdc++.h>

using namespace std;

int N;
vector<long long> nums;

long long merge(int l, int mid, int r){
    int i = l, j = mid + 1;
    long long cnt = 0;
    while(i <= mid){    // 先计算逆序对数量
        while(j <= r && nums[i] > 2 * nums[j])
            j++;
        cnt += j - mid -1;
        i++;
    }

    vector<long long> tmp(N, 0);
    int cur = l;
    i = l, j = mid + 1;
    while(i <= mid && j <= r){
        if(nums[i] <= nums[j]){
            tmp[cur] = nums[i];
            i++;
        }
        else{
            tmp[cur] = nums[j];
            j++;
        }
        cur++;
    }
    while(i <= mid){
        tmp[cur] = nums[i];
        cur++, i++;
    }
    while(j <= r){
        tmp[cur] = nums[j];
        cur++, j++;
    }
    for(int i = l; i <= r; i++)
        nums[i] = tmp[i];
    return cnt;
}

long long merge_sort(int l, int r){
    if(l >= r)
        return 0;
    int mid = l + (r - l) / 2;
    long long c1 = merge_sort(l, mid);
    long long c2 = merge_sort(mid + 1, r);
    long long c3 = merge(l, mid, r);
    return c1 + c2 + c3;
}

int main(){
    while(cin >> N && N){
        nums.assign(N, 0);
        for(int i = 0; i < N; i++){
            cin >> nums[i];
        }
        cout << merge_sort(0, N - 1) << endl;   
    }
    return 0;
}