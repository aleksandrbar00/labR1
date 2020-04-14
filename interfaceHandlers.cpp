#include <iostream>
#include <exception>
#include <fstream>
#include <string>
#include "mathHelpers.h"
#include "fileHelpers.h"
#include "tests.h"


void onStart(){

    double a, b, alpha, funcResult;
    int userPick;

    std::cout << "введите a, b, e";
    std::cin >> a >> b >> alpha;
    std::cout << std::endl;

    try{
        funcResult = findFuncValue(funcToTest, a, b, alpha);
        std::cout << "x=" << funcResult << std::endl;
        std::cout << "хотите сохранить результат в файл: (1) - да, (2) - нет";
        std::cin >> userPick;

        switch(userPick){
            case (1):
                saveToFile(a, b, alpha, funcResult);
                break;
            case (2):
                break;
        }
    }catch(std::exception){
        std::cout << "введите корректный интервал";
    }

}



void onFileRead(){

    std::string fileLine;
    std::ifstream file;

    double* args = new double[3](); 
    double funcResult;

    std::string filePath;
    std::cout<<"Введите путь к файлу";
    std::cin>>filePath;
    file.open(filePath);

    int i = 0;
    if(file.is_open()){
        while(getline(file, fileLine)){
            args[i] = std::stod(fileLine);
            i++;
        }
    }
    try{
        funcResult = findFuncValue(funcToTest, args[0], args[1], args[2]);
        std::cout << "x=" << funcResult << std::endl;
    }catch(std::exception){
        std::cout << "неверный формат данных";
    }



}   


void onTests(){
    goTests();
}