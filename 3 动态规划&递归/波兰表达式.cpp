// http://bailian.openjudge.cn/practice/2694/

#include <iomanip>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> parse(string pre_exp){
    vector<string> res;
    string tmp;
    int len = pre_exp.length();
    for(int i = 0; i < len; i++){
        char cur = pre_exp[i];
        if(cur != ' '){
            tmp.push_back(cur);
        }
        else{
            res.push_back(tmp);
            tmp.clear();
        }
    }
    res.push_back(tmp);
    return res;
}

vector<string> pre2post(vector<string> parsed_pre_exp){
    vector<string> res;
    int n = parsed_pre_exp.size();
    for(int i = n - 1; i >= 0; i--){
        res.push_back(parsed_pre_exp[i]); 
    }
    return res;
}

double cal_post(vector<string> parsed_post_exp){
    stack<double> num_stack;
    int n = parsed_post_exp.size();
    for(int i = 0; i < n; i++){
        string cur = parsed_post_exp[i];
        if(cur != "+" && cur != "-" && cur != "*" && cur != "/"){
            double num = atof(cur.c_str());
            num_stack.push(num);
        }
        else{
            double num1 = num_stack.top();
            num_stack.pop();
            double num2 = num_stack.top();
            num_stack.pop();
            double res;
            switch (cur[0])
            {
            case '+':
                res = num1 + num2;
                break;
            case '-':
                res = num1 - num2;
                break;
            case '*':
                res = num1 * num2;
                break;
            case '/':
                res = num1 / num2;
                break;
            }
            num_stack.push(res);
        }
    }
    return num_stack.top();
}

int main(){
    string pre_exp;
    getline(cin, pre_exp);
    vector<string> parsed_pre_exp = parse(pre_exp);
    vector<string> parsed_post_exp = pre2post(parsed_pre_exp);
    cout << fixed << setprecision(6) << cal_post(parsed_post_exp) << endl;
    return 0;
}