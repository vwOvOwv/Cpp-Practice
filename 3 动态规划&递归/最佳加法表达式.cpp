// http://bailian.openjudge.cn/practice/4152/
// dp[k][i]: 在前k个数字中插入i个等号可得的最小值，k = 1, 2, ..., n, i = 0, 1, ..., min{k - 1, m}
// dp[k][i] = min{dp[k-1][i-1] + num_k, 
//              dp[k-2][i-1] + num_{k-1, k}, ... ,
//              dp[i][i-1] + num_{i+1,...,k}}

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string reverse_str(string s){
    string res;
    int len = s.length();
    for(int i = len - 1; i >= 0; i--){
        res.push_back(s[i]);
    }
    return res;
}

string add(string a, string b){
    string res;
    string reverse_a = reverse_str(a);
    string reverse_b = reverse_str(b);
    int len_a = reverse_a.length();
    int len_b = reverse_b.length();
    if(len_a < len_b){
        string tmp = reverse_a;
        reverse_a = reverse_b;
        reverse_b = tmp;
        int tmp_len = len_a;
        len_a = len_b;
        len_b = tmp_len;
    }
    int carry_out = 0;
    int i;
    for(i = 0; i < len_b; i++){
        char sum = reverse_a[i] + (reverse_b[i] - '0') + carry_out;
        if(sum > '9'){
            carry_out = 1;
            sum -= 10;
        }
        else{
            carry_out = 0;
        }
        res.push_back(sum);
    }
    for(; i < len_a; i++){
        char sum = reverse_a[i] + carry_out;
        if(sum > '9'){
            carry_out = 1;
            sum -= 10;
        }
        else {
            carry_out = 0;
        }
        res.push_back(sum);
    }
    if(carry_out != 0){
        res.push_back('1');
    }
    return reverse_str(res);
}

bool is_less_than(string a, string b){
    if(a == "inf")
        return false;
    if(b == "inf")
        return true;
    int len_a = a.length();
    int len_b = b.length();
    if(len_a < len_b)
        return true;
    else if(len_a > len_b)
        return false;
    else
        return a < b;
}

int main(){
    int m;
    string s;
    while(cin >> m >> s){
        int n = s.length();
        vector<vector<string> > dp(n + 1, vector<string>(m + 1, "inf"));
        for(int k = 1; k <= n; k++){
            dp[k][0] = s.substr(0, k);
        }
        for(int k = 1; k <= n; k++){
            for(int i = 1; i <= min(k - 1, m); i++){
                string min_sum = "inf";
                for(int j = i; j <= k - 1; j++){
                    string sum = add(dp[j][i - 1], s.substr(j, k - j));
                    if(is_less_than(sum, min_sum)){
                        min_sum = sum;
                    }
                }
                dp[k][i] = min_sum;
            }
        }
        cout << dp[n][m] << endl;
    }
    return 0;
}