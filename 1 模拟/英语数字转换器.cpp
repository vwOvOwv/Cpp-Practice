// http://dsa.openjudge.cn/string/0401/
// hundred可能会和thousand/million配合使用，而thousand/million一旦出现就可以对前面计算得到的中间结果进行结算

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

unordered_map<string, long> str2long;

vector<string> parse(string s){
    int len = s.length();
    string tmp;
    vector<string> res;
    int cur = 0;
    while(cur < len){
        if(s[cur] == ' '){
            if(tmp.length() > 0){
                res.push_back(tmp);
                tmp.clear();
            }
            cur++;
            continue;
        }
        tmp.push_back(s[cur]);
        cur++;
    }
    if(tmp.length() > 0)
        res.push_back(tmp);
    return res;
}

int main(){
    string s;
    str2long["zero"] = 0;
    str2long["one"] = 1;
    str2long["two"] = 2;
    str2long["three"] = 3;
    str2long["four"] = 4;
    str2long["five"] = 5;
    str2long["six"] = 6;
    str2long["seven"] = 7;
    str2long["eight"] = 8;
    str2long["nine"] = 9;
    str2long["ten"] = 10;
    str2long["eleven"] = 11;
    str2long["twelve"] = 12;
    str2long["thirteen"] = 13;
    str2long["fourteen"] = 14;
    str2long["fifteen"] = 15;
    str2long["sixteen"] = 16;
    str2long["seventeen"] = 17;
    str2long["eighteen"] = 18;
    str2long["nineteen"] = 19;
    str2long["twenty"] = 20;
    str2long["thirty"] = 30;
    str2long["forty"] = 40;
    str2long["fifty"] = 50;
    str2long["sixty"] = 60;
    str2long["seventy"] = 70;
    str2long["eighty"] = 80;
    str2long["ninety"] = 90;
    while(getline(cin, s)){
        if(s.empty())
            return 0;
        vector<string> parsed_s = parse(s);
        int n = parsed_s.size();
        long ans = 0;
        long tmp = 0;
        for(int i = 0; i < n; i++){
            string cur = parsed_s[i];
            if(cur == "negative")
                cout << "-";
            else if(cur == "hundred"){
                tmp *= 100;
            }
            else if(cur == "thousand"){
                tmp *= 1000;
                ans += tmp;
                tmp = 0;
            }
            else if(cur == "million"){
                tmp *= 1000000;
                ans += tmp;
                tmp = 0;
            }
            else{
                tmp += str2long[cur];
            }
            // cout << ans << endl;
        }
        ans += tmp;
        cout << ans << endl;
    }
    return 0;
}