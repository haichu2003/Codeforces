#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

int main() {
    vector<int> numbers = { 123, -123, 120, 534236469, 1534236469 };
    for (int y : numbers) {
        int x = y;
        int result = 0;
        int sign = x > 0 ? 1 : -1;
        vector<int> component;
        while (abs(x) > 0) {
            component.push_back(abs(x) % 10);
            x /= 10;
        }
        // reverse(component.begin(), component.end());
        for (int i : component) {
            if (result < (pow(2, 31) - 1) / 10) {
                result *= 10;
                result += i;
            }
            else {
                result = 0;
                break;
            }
        }
        result *= sign;
        // if (result > pow(2, 31) - 1 || result < -1 * pow(2, 31)) result = 0;

        cout << y << endl << result << endl << endl;
    }
}