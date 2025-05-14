// http://dsa.openjudge.cn/linearlist/0203/
// STL API

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main(){
    string str, substr;
    while(cin >> str >> substr){
        int str_len = str.size();
        char max_char = str[0];
        int max_pos = 0;
        for(int i = 1; i < str_len; i++){
            if(str[i] > max_char){
                max_char = str[i];
                max_pos = i;
            }
        }
        str.insert(max_pos + 1, substr);
        cout << str << endl;
    }
    return 0;
}