#include <iostream>

unsigned encode(unsigned number, unsigned key) {
    return number ^ key;
}

unsigned decode(unsigned code, unsigned key) {
    return code ^ key;
}

int main()
{
   
}
