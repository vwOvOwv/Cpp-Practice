// http://noi.openjudge.cn/ch0406/8469/

#include <iostream>

using namespace std;

void change_single_state(string &s, int idx){
    if(s[idx] == '0'){
        s[idx] = '1';
    }
    else{
        s[idx] = '0';
    }
}

void change_state(string &s, int idx){
    change_single_state(s, idx);
    if(idx == 0){
        change_single_state(s, idx + 1);
    }
    else if(idx == s.length() - 1){
        change_single_state(s, idx - 1);
    }
    else{
        change_single_state(s, idx - 1);
        change_single_state(s, idx + 1);
    }
}

int main(){
    string input_str;
    string target_str;
    cin >> input_str >> target_str;
    int len = input_str.length();

    int op_cnt1 = 0;
    string tmp_str = input_str;
    for(int i = 1; i < len; i++){
        if(tmp_str[i - 1] != target_str[i - 1]){
            change_state(tmp_str, i);
            op_cnt1++;
        }
    }
    if(tmp_str[len - 1] != target_str[len - 1]){
        op_cnt1 = 0x7fffffff;
    }

    int op_cnt2 = 0;
    tmp_str = input_str;
    change_state(tmp_str, 0);
    op_cnt2++;
    for(int i = 1; i < len; i++){
        if(tmp_str[i - 1] != target_str[i - 1]){
            change_state(tmp_str, i);
            op_cnt2++;
        }
    }
    if(tmp_str[len - 1] != target_str[len - 1]){
        op_cnt2 = 0x7fffffff;
    }

    int ans = min(op_cnt1, op_cnt2);
    if(ans == 0x7fffffff)
        cout << "impossible";
    else
        cout << ans;

    return 0;
}