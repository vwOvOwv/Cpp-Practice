// http://dsa.openjudge.cn/stack/0306/

#include <bits/stdc++.h>

using namespace std;

stack<int> st;
vector<string> op_record;
vector<int> num_record;

void my_push(int num){
    st.push(num);
    op_record.push_back("PUSH ");
    num_record.push_back(num);
    // cout << "PUSH " << num << endl;
}

void my_pop(){
    int num = st.top();
    st.pop();
    op_record.push_back("POP ");
    num_record.push_back(num);
    // cout << "POP " << num << endl;
}

int main(){
    int n;
    cin >> n;
    vector<int> nums(n, 0);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
        if(nums[i] < 1 || nums[i] > n){
            cout << "NO" << endl;
            return 0;
        }
    }
    st.push(0);
    int cur = 0;
    for(int i = 0; i < n; i++){
        while(cur < nums[i]){
            my_push(++cur);
        }
        if(st.top() != nums[i]){
            cout << "NO" << endl;
            return 0;
        }
        my_pop();
    }
    int len = op_record.size();
    for(int i = 0; i < len; i++){
        cout << op_record[i] << num_record[i] << endl;
    }
    return 0;
}