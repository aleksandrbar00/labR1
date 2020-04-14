#include <string>
#include <iostream>
#include "mathHelpers.h"

void printTestResult(int testNum, bool result){
    if(result){
        std::cout << "тест" << testNum << " успешно пройден";
    }else{
        std::cout << "тест" << testNum << " провален";
    }
}

void goTests(){

        double test[4][4] = {
            {2, 3, 0.001, 1},
            {1, 1, 1, 1},
            {1, 1, 1, 1},
            {1, 1, 1, 1,}
        };

        for(int i = 0; i < 4; i++){
            double a, b, e, result;
            a = test[i][0];
            b = test[i][1];
            e = test[i][2];
            result = test[i][3];

            double funcRes = findFuncValue(funcToTest, a, b, e);


            if(funcRes == result){
                printTestResult(i, true);
            }else{
                printTestResult(i, false);
            }
        }

}