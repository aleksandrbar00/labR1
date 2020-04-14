#include <iostream>
#include <string>
#include "interface.h"

void run(void (*onStart)(), void (*onFileRead)(), void (*onTestsRun)()){
    
    int programmeStatus;

    showStudentInfo(1, 1);
    renderMenuItems();

    while(1){
        std::cout << "В ожидании команды...";
        std::cin >> programmeStatus;

        void (*params[3])() = {onStart, onFileRead, onTestsRun};

        checkUserInput(programmeStatus, params);
        std::cout << std::endl;


    }    

}

void showTitleInfo(){
    std::cout << "информация по лабе" << std::endl;
}



void checkUserInput(int userInput, void (*params[3])()){

    void (*onRunFunc)() =  params[0];
    void (*onShowTitleInfo)() = showTitleInfo;
    void (*onRunTests)() = params[2];
    void (*onFileRead)() = params[1];


    switch(userInput){
        case (1):
            onRunFunc();
            break;
        case (3):
            onShowTitleInfo();
            break;
        case (2):
            onRunTests();
            break;
        case (4):
            onFileRead();
            break;
        case (5):
            generateExit();
            break;

    }

}


void showStudentInfo(int workNumber, int typeNumber){
    std::cout << "имя: Рома" << std::endl;
    std::cout << "группа: 494" << std::endl; 
    std::cout << "учебное заведение: СПбГТУ (ТИ)" << std::endl;
    std::cout << "лабараторная работа " << workNumber << std::endl;
    std::cout << "вариант " << typeNumber << std::endl;

}

void renderMenuItems(){
    std::cout << "1: заппуск программы" << std::endl;
    std::cout << "2: запуск тестов" << std::endl; 
    std::cout << "3: информация" << std::endl;
    std::cout << "4: запуск с аргументами из файла" << std::endl;
    std::cout << "5: выход" << std::endl;
}


void generateExit(){
    std::exit(0);
}