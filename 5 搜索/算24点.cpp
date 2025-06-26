// http://noi.openjudge.cn/ch0205/1789/

#include <bits/stdc++.h>

using namespace std;

bool solve(vector<double> nums){
    int n = nums.size();
    // for(int i = 0; i < n; i++){
    //     cout << nums[i] << ' ';
    // }
    // cout << endl;
    if(n == 1 && abs(nums[0] - 24) < 1e-6)
        return true;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            vector<double> next;
            double num1 = nums[i], num2 = nums[j];
            for(int k = 0; k < n; k++){
                if(k != i && k != j){
                    next.push_back(nums[k]);
                }
            }
            next.push_back(num1 + num2);
            if(solve(next))
                return true;
            next.pop_back();

            next.push_back(num1 - num2);
            if(solve(next))
                return true;
            next.pop_back();

            next.push_back(num2 - num1);
            if(solve(next))
                return true;
            next.pop_back();

            next.push_back(num1 * num2);
            if(solve(next))
                return true;
            next.pop_back();

            if(num2 != 0){
                next.push_back(num1 / num2);
                if(solve(next))
                    return true;
                next.pop_back();
            }

            if(num1 != 0){
                next.push_back(num2 / num1);
                if(solve(next))
                    return true;
                next.pop_back();
            }
        }
    }
    return false;
}

int main(){
    while(1){
        vector<double> nums(4, 0);
        for(int i = 0; i < 4; i++){
            cin >> nums[i];
        }
        if(nums[0] == 0)
            break;
        if(solve(nums))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}