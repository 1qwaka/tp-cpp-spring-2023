#include <iostream>
#include <string>


int main(int argc, char *argv[]) {

    std::string s = "abcdefgh";

    std::cout << s.substr(2, 3) << std::endl;

    return 0;
}