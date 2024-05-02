#include <iostream>

bool is_palindrome(int x) {
    if (x < 0) return false;

    unsigned int rev = 0;
    int r;
    int y = x;
    while (x > 0) {
        r = x % 10;
        rev = rev * 10 + r;
         x /= 10;
    }
    return rev == y;
}