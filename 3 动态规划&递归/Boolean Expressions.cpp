// http://bailian.openjudge.cn/practice/2106/

#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

unordered_map<char, int> op_pri;

string mid2post(string mid_exp){
    stack<char> op_stack;
    string post_exp;
    int len = mid_exp.length();
    for(int i = 0; i < len; i++){
        if(mid_exp[i] == '('){
            op_stack.push('(');
        }
        else if(mid_exp[i] == 'V' || mid_exp[i] == 'F'){
            post_exp.push_back(mid_exp[i]);
        }
        else if(mid_exp[i] == '!'){
            op_stack.push('!');
        }
        else if(mid_exp[i] == '&' or mid_exp[i] == '|'){
            while(!op_stack.empty() && 
            op_pri[op_stack.top()] >= op_pri[mid_exp[i]]){
                post_exp.push_back(op_stack.top());
                op_stack.pop();
            }
            op_stack.push(mid_exp[i]);
        }
        else if(mid_exp[i] == ')'){
            while(!op_stack.empty() && op_stack.top() != '('){
                post_exp.push_back(op_stack.top());
                op_stack.pop();
            }
            if(!op_stack.empty())
                op_stack.pop();
        }
        else{
            continue;
        }
    }
    while(!op_stack.empty()){
        post_exp.push_back(op_stack.top());
        op_stack.pop();
    }
    return post_exp;
}

char cal_post(string post_exp){
    stack<bool> num_stack;
    int len = post_exp.length();
    for(int i = 0; i < len; i++){
        char cur = post_exp[i];
        if(cur == 'V'){
            num_stack.push(true);
        }
        else if (cur == 'F'){
            num_stack.push(false);
        }
        else if(cur == '|' || cur == '&'){
            bool num1 = num_stack.top();
            num_stack.pop();
            bool num2 = num_stack.top();
            num_stack.pop();
            if(cur == '|'){
                num_stack.push(num1 || num2);
            }
            else{
                num_stack.push(num1 && num2);
            }
        }
        else if(cur == '!'){
            bool num = num_stack.top();
            num_stack.pop();
            num_stack.push(!num);
        }
    }
    bool res = num_stack.top();
    if(res){
        return 'V';
    }
    return 'F';
}

int main(){
    string mid_exp;
    op_pri['('] = 0;
    op_pri['&'] = 1;
    op_pri['|'] = 1;
    op_pri['!'] = 2;
    int cnt = 0;
    while(getline(cin, mid_exp)){
        cnt++;
        string post_exp = mid2post(mid_exp);
        // cout << post_exp << endl;
        cout << "Expression " << cnt << ": ";
        cout << cal_post(post_exp) << endl;
    }
    return 0;
}