// http://bailian.openjudge.cn/practice/1004/

#include <iomanip>
#include <iostream>

using namespace std;

int main(){
    int N = 12;
    double sum = 0;
    double num;
    for(int i = 0; i < N; i++){
        cin >> num;
        sum += num;
    }
    // printf("$%.2f\n", sum / N); 
    cout << fixed << setprecision(2) << "$" << sum / N << endl;
    return 0;
}