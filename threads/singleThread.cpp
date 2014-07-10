/**
* The code above is an example of a serial coded program.
* main() is executed and gives control to function1() - function1()
* gives control back to main() - main() gives control to function2()
* - function2() finally gives control back to main() again. 
**/

#include <iostream>
extern "C"
{
    #include <unistd.h>
}

using namespace std;

void function1();
void function2();

int main()
{
    function1();
    function2();
    return 0;
}

void function1()
{

    cout << "hello..." << endl ;
    sleep(2); // fall asLeep here for 2 seconds...

}

void function2()
{
    cout << " ....world" << endl ;
}
/**
* The problem with this program, is that we have to wait 2 seconds 
* before "hello world" is displayed. We do not want that. We want 
* to see "hello world" ASAP, and no we're not going to remove sleep(2);. 
**/
