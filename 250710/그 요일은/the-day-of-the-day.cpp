#include <iostream>
#include <string>

using namespace std;

int m1, m2, d1, d2;
string A;

int main() {
    cin >> m1 >> d1 >> m2 >> d2;
    cin >> A;

    // Please write your code here.
    int sub = 0;
    int day;
    int month[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    string week[] = {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};

    for(int i=0; i<7; i++) {
        if(A==week[i]) day=i;
    }

    for(int i=m1+1; i<m2; i++) {
        sub+=month[i];
    }
    sub+=month[m1]-d1+d2;
    
    int cnt=sub/7;

    if(sub%7>=day) cnt++;

    cout << cnt;

    return 0;
}