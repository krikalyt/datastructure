#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
int main(int number,char **args)
{

    vector<int> vint2 =  { 10, 20, 30 }; 
    vector<int> vint;
    vector<int> ::iterator it;

    vector<int> *intd = new vector<int>[5]; //this is for pointer of vector
    vint.push_back(15);
    for (it = vint.begin();it!=vint.end();++it) {
        cout << *(it) << endl;
    }
    vint.assign(3,10);//function will assign value 10 to all the first 3 element
    vint.emplace(vint.begin()+3,100); //first arg in postition rest is value
    for (it = vint.begin();it!=vint.end();it++) {
        cout << *(it) << endl;
    }

    cout << *(vint.end()-1);
    //vint.end() is for address of last+1
    //vint.begin() first address
    //vint.start() value
    //vint.back() last value
    vint.pop_back(); // dothe pop operation from last
    vint.erase(vint.begin()); // it takes position of vector
    cout << endl;
    for (it = vint.begin();it!=vint.end();it++) {
        cout << *(it) << endl;
    }
    vint.clear(); //it will clear the array;

    return 0;
}
