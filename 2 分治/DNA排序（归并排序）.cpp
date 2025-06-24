// http://bailian.openjudge.cn/practice/1007/
// 分治，归并排序模版题

#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

map<int, vector<string>> res_record;

int merge(string &s, int l, int mid, int r){    // s[l...mid]和s[mid+1...r]已经排好序
    int res = 0;
    int i = l, j = mid + 1;
    string tmp = s;
    int cur = l;
    while(i <= mid && j <= r){
        if(s[i] <= s[j]){
            tmp[cur++] = s[i++];
        }
        else{
            tmp[cur++] = s[j++];
            res += (mid - i + 1);   // 归并的同时计算逆序对数
        }
    }
    while(i <= mid){
        tmp[cur++] = s[i++];
    }
    while(j <= r){
        tmp[cur++] = s[j++];
    }
    s = tmp;
    return res;
}

int mergesort(string &s, int l, int r){
    if(l == r)
        return 0;
    int mid = (l + r) / 2;
    int count1 = mergesort(s, l, mid);
    int count2 = mergesort(s, mid + 1, r);
    int count3 = merge(s, l, mid, r);
    return count1 + count2 + count3;
}

int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        string seq;
        cin >> seq;
        string tmp_seq = seq;
        res_record[mergesort(seq, 0, n - 1)].push_back(tmp_seq);
    }
    map<int, vector<string>>::iterator i;
    for(i = res_record.begin(); i != res_record.end(); ++i){
        int num_str = i->second.size();
        for(int j = 0; j < num_str; j++){
            cout << i->second[j] << endl;
        }
    }
}