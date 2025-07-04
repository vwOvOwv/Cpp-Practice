// http://noi.openjudge.cn/ch0206/1808/
// dp[i][j]: s1[1, ..., i]和s2[1, ..., j]的最长公共子序列长度

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    string s1, s2;
    while(cin >> s1 >> s2){
        int len1 = s1.length();
        int len2 = s2.length();
        s1.insert(0, "-");
        s2.insert(0, "-");
        vector<vector<int> > dp(len1 + 1, vector<int>(len2 + 1, 0));
        for(int i = 1; i <= len1; i++){
            for(int j = 1; j <= len2; j++){
                if(s1[i] == s2[j]){
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else{
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        cout << dp[len1][len2] << endl;
    }
    return 0;
}