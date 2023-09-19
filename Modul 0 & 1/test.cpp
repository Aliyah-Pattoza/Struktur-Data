#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int tumpuk1, tumpuk2, tumpuk3, h1, h2, h3;
    cin >> tumpuk1 >> tumpuk2 >> tumpuk3;

    stack<int> tinggi1, tinggi2, tinggi3;
    int sum1 = 0, sum2 = 0, sum3 = 0;

    for (int i = 0; i < tumpuk1; i++) {
        cin >> h1;
        sum1 += h1;
        tinggi1.push(h1);
    }
    for (int i = 0; i < tumpuk2; i++) {
        cin >> h2;
        sum2 += h2;
        tinggi2.push(h2);
    }
 for (int i = 0; i < tumpuk3; i++) {
        cin >> h3;
        sum3 += h3;
        tinggi3.push(h3);
    }

    vector<int> v1, v2, v3;
    while (!tinggi1.empty()) {
        v1.push_back(tinggi1.top());
        tinggi1.pop();
    }
    while (!tinggi2.empty()) {
        v2.push_back(tinggi2.top());
        tinggi2.pop();
    }
    while (!tinggi3.empty()) {
        v3.push_back(tinggi3.top());
        tinggi3.pop();
    }

    for (int x : v1) {
        tinggi1.push(x);
    }
  for (int x : v2) {
        tinggi2.push(x);
    }
    for (int x : v3) {
        tinggi3.push(x);
    }

    while (true) {
        if (tinggi1.empty() || tinggi2.empty() || tinggi3.empty()) {
            cout << 0;
            return 0;
        }
        if (sum1 == sum2 && sum2 == sum3){
            cout << sum1;
            return 0;
        }

        if (sum1 > sum2 || sum1 > sum3){
            sum1 -= tinggi1.top();
            tinggi1.pop();
        }
        else if (sum2 > sum1 || sum2 > sum3){
            sum2 -= tinggi2.top();
            tinggi2.pop();
        }
    else if (sum3 > sum1 || sum > sum2){
            sum3 -= tinggi3.top();
            tinggi3.pop();
        }
    }
    return 0;    
}
