#include <math.h>
#include <exception>


double funcToTest(double x){
    return pow(x, 2) - 5 * x + 16;
}


double findFuncValue(double (*func)(double), double a, double b, double alpha){
    double num;

    if(func(a) > func(b)){
        throw std::exception();
    }

    while((b - a) / 2 > alpha){
        num = (a + b) / 2;

        if((func(a) * func(num)) > 0){
            a = num;
        }else{
            b = num;
        }
    }

    return num;
}