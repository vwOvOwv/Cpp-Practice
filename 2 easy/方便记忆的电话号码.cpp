// http://bailian.openjudge.cn/practice/1002/
// 哈希表 + 模拟

#include <iostream>
#include <unordered_map>
#include <string>
#include <map>

using namespace std;

map<string, int> cnt;
unordered_map<char, char> char2int;

int main(){
    char2int['A'] = '2';
    char2int['B'] = '2';
    char2int['C'] = '2';
    char2int['D'] = '3';
    char2int['E'] = '3';
    char2int['F'] = '3';
    char2int['G'] = '4';
    char2int['H'] = '4';
    char2int['I'] = '4';
    char2int['J'] = '5';
    char2int['K'] = '5';
    char2int['L'] = '5';
    char2int['M'] = '6';
    char2int['N'] = '6';
    char2int['O'] = '6';
    char2int['P'] = '7';
    char2int['R'] = '7';
    char2int['S'] = '7';
    char2int['T'] = '8';
    char2int['U'] = '8';
    char2int['V'] = '8';
    char2int['W'] = '9';
    char2int['X'] = '9';
    char2int['Y'] = '9';
    int n;
    cin >> n;
    while(n--){
        string s;
        string std_s;
        int valid_num_cnt = 0;
        bool seperation_added = false;
        cin >> s;
        int len = s.length();
        for(int i = 0; i < len; i++){
            if(s[i] >= '0' && s[i] <= '9'){
                valid_num_cnt++;
                std_s.push_back(s[i]);
            }
            else if(s[i] >= 'A' && s[i] <= 'Z'){
                valid_num_cnt++;
                std_s.push_back(char2int[s[i]]);
            }
            if(valid_num_cnt == 3 && !seperation_added){
                std_s.push_back('-');
                seperation_added = true;
            }
        }
        if(cnt.find(std_s) == cnt.end()){
            cnt[std_s] = 1;
        }
        else{
            cnt[std_s]++;
        }
    }
    bool duplicated_founded = false;
    for(auto i = cnt.begin(); i != cnt.end(); ++i){
        if(i->second >= 2){
            cout << i->first << ' ' << i->second << endl;
            duplicated_founded = true;
        }
    }
    if(!duplicated_founded)
        cout << "No duplicates." << endl;
    return 0;
}