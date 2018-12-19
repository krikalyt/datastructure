#include <iostream>
#include <string>
#include <stdlib.h>
#include <sys/time.h>
using namespace std;
class Dog{
private:
//private member are member that could be accessed by internal class only...

protected:
//protected member are member that could be accessed by internal class only and child class...

public:
    int dog;
    Dog(int dog){
        this->dog = dog;
    }
    Dog(int dog,int dogges){
        this->dog = dog+dogges;
    }

    int operator + (Dog num){
        return this->dog + num.dog;
    }

    int operator - (Dog num){
        return this->dog - num.dog;
    }

//template
    template <typename T>
    T findSmaller(T input,T input2){
        if(input<input2){
            return input2;
        }
        return input;
    }
    
    template <typename T,typename U,typename V>
    T findSmaller(T input, U input2, V input3){
        return input+input2+input3;
    }
};


int main(int number,char **args)
{
    Dog dog(2);
    int dothis= dog.findSmaller(5,9);
    cout << dothis;
    return 0;
}
