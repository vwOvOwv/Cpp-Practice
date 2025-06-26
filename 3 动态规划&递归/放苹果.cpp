// http://dsa.openjudge.cn/linearlist/0215/
// recursion
// f(M, N) = f(M, N - 1) + f(M - N, N)
// 1. At least one plate doest not have any apple.
// 2. All plates have apples.
// Never consider anything that has to do with the **order** of different plates

#include <iostream>

using namespace std;

int t, M, N;

int solve(int M, int N){
    if(M == 0)
        return 1;
    if(N == 0)
        return 0;
    if(N > M)   // pruning
        N = M;
    return solve(M, N - 1) + solve(M - N, N);
}

int main(){
    cin >> t;
    while(t--){
        cin >> M >> N;
        cout << solve(M, N) << endl;
    }
    return 0;
}