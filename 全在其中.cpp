// http://dsa.openjudge.cn/string/0403/

#include <iostream>
#include <string>

using namespace std;

int main(){
    string s, t;
    while(cin >> s >> t){
        int p1 = 0, p2 = 0;
        int len1 = s.length(), len2 = t.length();
        if(len1 > len2){
            cout << "No" << endl;
            continue;
        }
        while(p1 < len1 && p2 < len2){
            if(s[p1] == t[p2]){
                p1++;
                p2++;
            }
            else{
                p2++;
            }
        }
        if(p1 == len1)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}