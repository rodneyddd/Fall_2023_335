#include <iostream>
#include <string>

int main(){
    string c = "89";

    if ('1' < c < "90")
        std::cout << "Hey";
    else
        std::cout << "Doesnt Work";
}   