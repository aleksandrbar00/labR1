#include <iostream>
#include <fstream>
#include <string>

std::fstream checkFileAndReturn(std::string filePath){
    std::fstream file;
    
    if(file.is_open()){
        return file;
    }else
    {
        throw std::exception();
    }
    
    
}


void saveToFile(double a, double b, double e, double result){
    
    bool savedFile = false;

    int userPick;

    std::string filePath;


    while(!savedFile){
        try{
            std::cout << "введите название файла: " << std::endl;
            std::cin >> filePath;
            std::ofstream file;
            file.open(filePath, std::ios::app);
            if(file.is_open()){
                std::cout << "нажмите (1) для перезаписи файла, или (2) для ввода нового пути";
                std::cin >> userPick;

                switch(userPick){
                    case (1):
                        file << "a= " << a << ", " << "b= " << b << ", " << "e=" << e << "," << "результат= " << result << std::endl;  
                        savedFile = true;
                        break;
                    case (2):
                        continue;
                        break;

                }

            }
        }catch(std::exception){
            continue;
        }
    }

}