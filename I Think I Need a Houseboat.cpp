// http://bailian.openjudge.cn/practice/1005/
// r_n^2 = n * \frac{100}{\pi}

#include <iostream>

using namespace std;

double pi = 3.1415926;

int main(){
    int N;
    cin >> N;
    for(int i = 1; i <= N; i++){
        double x, y;
        cin >> x >> y;
        cout << "Property " << i << ": This property will begin eroding in year ";
        cout << int((x * x + y * y) / 100 * pi) + 1 << "." << endl;
    }
    cout << "END OF OUTPUT." << endl;
    return 0;
}
