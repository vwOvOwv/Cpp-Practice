// http://dsa.openjudge.cn/linearlist/0204/

// KMP algorithm, leverage `next` to get the shortest repeat

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void get_next(vector<int> &next, string pattern){
    next[0] = -1;
    int j = 0;
    int k = -1;
    int pattern_len = pattern.size();
    while(j < pattern_len + 1){
        while(k >= 0 && pattern[j] != pattern[k])
            k = next[k];
        j++;
        k++;
        if(j == pattern_len + 1)
            break;
        // cannot apply optimization since we only need longest common substr
        // if(pattern[j] == pattern[k])
        //     next[j] = next[k];
        else
            next[j] = k;
    }
}

int n;
string s;

int main(){
    int case_count = 0;
    while(cin >> n){
        if(n == 0)
            return 0;
        case_count++;
        cin >> s;
        cout << "Test case #" << case_count << endl;
        vector<int> next(n + 1, 0);
        get_next(next, s);
        // for(int i = 0; i < n + 1; i++)
        //     cout << next[i] << ' ';
        // cout << endl;
        for(int i = 1; i < n; i++){ // prefix: s[0, ..., i]
            int j = next[i + 1];    // s[0, ..., j-1] = s[i-j+1, ..., i]
            int potential_repeat_len = i - j + 1;    // s[j, ..., i] = s[2j-i-1, ..., j-1] = ..., if it's a repeat, it must be shortest repeat
            int prefix_len = i + 1;
            if(prefix_len % potential_repeat_len == 0 && 
               prefix_len != potential_repeat_len){
                cout << prefix_len << ' ' << prefix_len / potential_repeat_len << endl;
            }
        }
        cout << endl;
    }
}