// 快排模板

#include <iostream>
#include <vector>

using namespace std;

vector<int> A = {0,2,3,10,4,5,9,7,8,6,1};

int partition(vector<int> &A, int l, int r){
    int i = l, j = r;
    while(true){
        while(A[j] > A[l]){
            j--;
        }
        while(A[i] <= A[l]){
            i++;
        }
        if(i < j){
            int tmp = A[i];
            A[i] = A[j];
            A[j] = tmp;
        }
        else {
            return j;
        }
    }
}

void quick_sort(vector<int> &A, int l, int r){
    if(l > r)
        return;
    int pivot = partition(A, l, r);
    int tmp = A[pivot];
    A[pivot] = A[l];
    A[l] = tmp;
    quick_sort(A, l, pivot - 1);
    quick_sort(A, pivot + 1, r);
}

int main(){
    int size = A.size();
    quick_sort(A, 0, size - 1);
    for(int i = 0; i < size; i++){
        cout << A[i] << ' ';
    }
    cout << endl;
    return 0 ;
}