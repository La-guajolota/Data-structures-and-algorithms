#include <iostream>

/*
    Arguments can be passed from one method to other using parameters. By default
    all, the variables, which are passed as parameters, are passed-by-value. That
    means a separate copy is created inside the called method and no changes done
    inside called method will reflect in calling method.
*/
//Parameter passing, Call by value
void incrementPassByValue(int var){
    var++;
}

/*
    If you need to change the value of the parameter inside the method, then you
    should use call by reference. C++ language by default passes by value.
    Therefore, to make it happen, you need to pass by reference by using “&”
    operator. The variable inside the called function also refer to the same variable
    inside the calling function. When the value of reference variable is changed then
    the original variable value also change.
*/
//Parameter passing, Call by Reference
void incrementPassByValue2(int& var){
    var++;
}

/*
    When we pass address of variable inside calling function to the called function
    then the changes done inside called function is also reflected inside calling
    function.
*/
//Parameter passing, Call by Pointer
void incrementPassByPointer3(int* ptr){
    (*ptr)++;
}


int main(){
    int i = 10;
    std::cout << "Value of i before increment is : " << i << std::endl;
    
    //incrementPassByValue(i);
    //incrementPassByValue2(i);
    incrementPassByPointer3(&i);

    std::cout << "Value of i after increment is : " << i << std::endl;
}