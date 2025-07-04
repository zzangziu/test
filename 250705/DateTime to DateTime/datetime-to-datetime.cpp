#include <iostream>

using namespace std;

int A, B, C;

int main() {
    cin >> A >> B >> C;

    int min = 0;
    if(A>12) {
        min+=(A-12)*24*60;
        min+=B*60+C;
        min+=(24-12)*60+49;
    }
    else if(A==12) {
        min+=B*60+C;
        min+=(24-12)*60+49;
    }
    else if(A==11) {
        if(B<11 || (B==11 && C<11)) {
            cout << "-1";
            return 0;
        }
        if(C>=11) {
            min+=C-11;
            min+=(B-11)*60;
        }
        else {
            min+=C-11+60;
            min+=(B-12)*60;
        }
    }
    cout << min;
    return 0;
}