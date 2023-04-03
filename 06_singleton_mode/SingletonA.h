//
// Created by 23984 on 2023/4/2.
//

#ifndef DATA_STRUCTURE_ALGORITHM_SINGLETONA_H
#define DATA_STRUCTURE_ALGORITHM_SINGLETONA_H

#include "Singtelon.h"
#include "iostream"

class SingletonA : public Singtelon{
    friend class Singleton; // 必须为友元，否则父类无法访问子类的构造函数
public:
    void show(){
        std::cout << "SingletonA" <<std::endl;
    }
private:
    SingletonA(){};
};


#endif //DATA_STRUCTURE_ALGORITHM_SINGLETONA_H
