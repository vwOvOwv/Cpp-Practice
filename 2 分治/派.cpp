// http://noi.openjudge.cn/ch0111/05/
// 二分查找

#include <cmath>
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

double pi = acos(-1);
double eps = 1e-5;

int main(){
    int N, F;
    cin >> N >> F;
    vector<double> v(N, 0);
    double v_total = 0;
    for(int i = 0; i < N; i++){
        cin >> v[i];
        v[i] = pi * v[i] * v[i];
        v_total += v[i];
    }
    double L = 0;
    double R = v_total / (F + 1);
    while(R - L >= eps){
        double mid = (R + L) / 2;
        int num_pie = 0;
        for(int i = 0; i < N; i++){
            num_pie += int(v[i] / mid); 
        }
        if(num_pie < F + 1){
            R = mid;
        }
        else{
            L = mid;
        }
    }
    cout << fixed << setprecision(3) << L << endl;  // eps足够小，输出L和R都可以
    return 0;
}