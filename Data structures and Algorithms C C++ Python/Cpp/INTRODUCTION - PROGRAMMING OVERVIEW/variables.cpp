#include <iostream>

void variableEjemplo(){
    int var1, var2, var3;

    var1=100;
    var2=200;
    var3=var1+var2;

    std::cout<<"SUMAMOS "<<var1<<" Y "<<var2<<" Da "<<var3<<std::endl;
}

int main(int argc, char* argv[]){

    variableEjemplo();
    
    return 0;
}