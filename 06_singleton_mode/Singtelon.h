//
// Created by 23984 on 2023/4/2.
//

#ifndef DATA_STRUCTURE_ALGORITHM_SINGTELON_H
#define DATA_STRUCTURE_ALGORITHM_SINGTELON_H

#include "iostream"
#include "SingletonA.h"
#include "SingtelonB.h"

class Singleton{
public:
    static Singleton* getInstance(const char* name);
    virtual void show(){};
protected:
    // 这里的构造函数必须为protected，否则子类不法访问父类构造函数
    Singleton(){};
private:
    static Singleton *singleton;
};

Singleton* Singleton::singleton = nullptr;

Singleton *Singleton::getInstance(const char* name){
    if (singleton == nullptr){
        if(strcmp(name,"SingletonA") == 0){
            singleton = new SingletonA();
        }
        else if(strcmp(name,"SingletonB") == 0){
            singleton = new SingletonB();
        }
        else{
            singleton = new Singleton();
        }
    }
    return singleton;
}

#endif //DATA_STRUCTURE_ALGORITHM_SINGTELON_H
