#include <iostream>
#include "interface.h"
#include "interfaceHandlers.h"


int main(){

    run(onStart, onFileRead, onTests);

    return 0;
}