// http://bailian.openjudge.cn/practice/2746/

// n people (1, 2, ..., n) in a circle, every m-th person is killed
// j(n, m) is the index of the last person left.
// old index: 1,     2,     ..., m-1, m, m+1, ..., n
// new index: n-m+1, n-m+2, ..., n-1, 0, 1,   ..., n-m (0 represents 'killed')
// old = (new + m - 1) % n + 1
// initial old: 1

#include <iostream>

using namespace std;

int n, m;

int josephus(int n, int m){
    int res = 1;
    for(int i = 1; i <= n; i++){    // i: current number of people
        res = (res + m - 1) % i + 1; 
        // cout << res + 1 << endl;
    }
    return res;
}

int main(){
    while (cin >> n >> m){
        if (n == 0 && m == 0){
            break;
        }
        cout << josephus(n, m) << endl;
    }
    return 0;
}