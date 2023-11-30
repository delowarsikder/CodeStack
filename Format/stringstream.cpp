#include <iostream>
#include <sstream> //for string stream
#include <string>
using namespace std;

int main()
{

    string line = "MRX 10 CSE";// We need to take the value 10 from middle of that string to a int variable

    int val;//That is where 10 needs to go
    stringstream sin(line);//sin will act like cin but now the input will come from the string named line

    //First skip MRX by reading it to a dummy variable
    string dummy;
    sin>>dummy;
    cout<<dummy<<endl;
    //next sin will read 10 so store it to val
    sin>>val;
    cout<<val<<endl;
    return 0;
}

