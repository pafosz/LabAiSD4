#include <iostream>

using namespace std;
size_t lcg() {
    static size_t x = 0;
    x = (1021 * x + 24631) % 116640;
    return x;
}

int main() {
    
    cout << lcg();
    
    return 0;
}