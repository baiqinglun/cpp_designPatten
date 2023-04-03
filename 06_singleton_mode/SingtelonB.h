//
// Created by 23984 on 2023/4/2.
//

#ifndef DATA_STRUCTURE_ALGORITHM_SINGTELONB_H
#define DATA_STRUCTURE_ALGORITHM_SINGTELONB_H

#include "iostream"
#include "Singtelon.h"

class SingletonB : public Singleton{
    friend class Singleton; // 必须为友元，否则父类无法访问子类的构造函数
public:
    void show(){
        std::cout << "SingletonB" <<std::endl;
    }
private:
    SingletonB(){};
};
#endif //DATA_STRUCTURE_ALGORITHM_SINGTELONB_H
