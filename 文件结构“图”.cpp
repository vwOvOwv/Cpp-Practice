// http://bailian.openjudge.cn/practice/2775/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int global_p = 0;

void print_layout(vector<string> record, int end, int cur_depth){
    if(cur_depth == 0){
        cout << "ROOT" << endl;
    }
    else{
        for(int i = 0; i < cur_depth; i++){
            cout << "|     ";
        }
        cout << record[global_p] << endl;
        global_p++;
    }
    vector<string> dir_buffer;
    while(global_p < end){
        if(record[global_p][0] == 'f'){
            dir_buffer.push_back(record[global_p]);
        }
        else if(record[global_p][0] == 'd'){
            print_layout(record, end, cur_depth + 1);
        }
        else if (record[global_p][0] == ']'){
            sort(dir_buffer.begin(), dir_buffer.end());
            int n = dir_buffer.size();
            for(int i = 0; i < n; i++){
                for(int j = 0; j < cur_depth; j++){
                    cout << "|     ";
                }
                cout << dir_buffer[i] << endl;
            }
            return;
        }
        global_p++;
    }
    sort(dir_buffer.begin(), dir_buffer.end());
    int n = dir_buffer.size();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < cur_depth; j++){
            cout << "|     ";
        }
        cout << dir_buffer[i] << endl;
    }
    return;
}

int main(){
    int case_cnt = 1;
    string s;
    vector<string> record;
    while(cin >> s){
        if(s == "*"){
            if(case_cnt != 1){
                cout << endl;
            }
            cout << "DATA SET " << case_cnt << ":" << endl;
            int n = record.size();
            print_layout(record, n, 0);
            record.clear();
            global_p = 0;
            case_cnt++;
        }
        else if(s == "#"){
            return 0;
        }
        else{
            record.push_back(s);
        }
    }
}