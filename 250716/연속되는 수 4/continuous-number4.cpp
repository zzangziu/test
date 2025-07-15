#include <iostream>

using namespace std;

int N;
int arr[1000];

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int max = 0;
    int tm = 1;

    // Please write your code here.
    for (int i=0; i<N; i++) {
        if(arr[i+1]>arr[i]) {
            tm++;
        }
        else {
            if(max < tm) max =tm;
            tm = 1;
        }
    }

    cout << max;
    return 0;
}