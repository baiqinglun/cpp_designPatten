/*
 * Created by 23984 on 2023/4/2.
 * 适配器模式
 * 适配器模式（Adapter Pattern）是一种结构型设计模式，它允许将不兼容的接口转换为客户端希望的接口。
 * STL实现了一种数据结构，称为双端队列（deque），支持前后两段的插入与删除。STL实现栈和队列时，没有从头开始定义它们，而是直接使用双端队列实现的。
 * 这里双端队列就扮演了适配器的角色。队列用到了它的后端插入，前端删除。而栈用到了它的后端插入，后端删除。
 * */

#include "iostream"
#include "Singtelon.h"

// 只有一个类
//class Singleton{
//public:
//    static Singleton* getInstance();
//private:
//    Singleton(){}
//    static Singleton *singleton;
//};
//Singleton* Singleton::singleton = nullptr;
//Singleton *Singleton::getInstance(){
//    if (singleton == nullptr)
//        singleton = new Singleton();
//    return singleton;
//}

int main(){
    Singleton *st = Singleton::getInstance("singletonA");
    st->show();
    st = Singleton::getInstance("singletonB");
    st->show();
    return 0;
}