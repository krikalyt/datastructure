//operator overloading
#include <iostream>
#include <string>
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

};
int main(int number,char **args)
{
    //number is for command line args number...
    //args is array of string.. but array[0] is project directory and rest is args passed by command line...
    Dog dog(5,12);
    Dog dog2(4);
    int total = dog+dog2;
    int total2 = dog - dog2;
    cout << dog.dog << endl;
    cout << total << endl;
    cout << total2 << endl;

    cout  << "don't need //" << endl;
    return 0;
}
