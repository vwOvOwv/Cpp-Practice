// http://bailian.openjudge.cn/practice/1003/

#include <iostream>
#include <vector>

using namespace std;

vector<double> sum;

int main(){
    sum.push_back(-1);
    double res = 0;
    for(int i = 1; ; i++){
        res += 1 / (double(i) + 1);
        sum.push_back(res);
        if(res > 5.21)
            break;
    }
    int size = sum.size();
    double num;
    double eps = 1e-8;
    while(cin >> num){
        if(num <= eps)
            return 0;
        for(int i = 1; i < size; i++){
            if(sum[i] >= num){
                cout << i << ' ' << "card(s)" << endl;
                break;
            }
        }
    }   
}