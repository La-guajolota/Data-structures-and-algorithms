#include <iostream>

//Parameter passing, Call by value
void incrementPassByValue(int var){
    var++;
}

//Parameter passing, Call by Reference
void incrementPassByValue2(int& var){
    var++;
}

int main(){
    int i = 10;
    std::cout << "Value of i before increment is : " << i << std::endl;
    
    //incrementPassByValue(i);
    incrementPassByValue2(i);

    std::cout << "Value of i after increment is : " << i << std::endl;
}