/*
 * Created by 23984 on 2023/4/2.
 * 工厂方法模式
 * 简单工厂每次新增创建图形类，就需要修改Factory工厂的创建方法,违反了开放开放封闭原则。
 * 1. 定义一个图形抽象类,类中添加绘制图形的纯虚函数,球形类和长方体继承该图形抽象类,并重写纯虚函数.
 * 2. 定义一个抽象工厂Factory，纯虚函数创建图形.创建球形工厂和创建长方体工厂继承自该工厂。并重写纯虚函数。
 * */

#include "iostream"

class Graphics{
public:
    virtual void painter() = 0;
};

// 球形
class Sphere : public Graphics{
public:
    void painter() override{
        std::cout << "绘制球形"<<std::endl;
    }
};

// 长方体
class Cube : public Graphics{
public:
    void painter() override{
        std::cout << "绘制长方体"<<std::endl;
    }
};

class Factory{
public:
    virtual Graphics* createGraphics() = 0;
};

class SphereFactory : public Factory{
public:
    Graphics * createGraphics() override{
        return new Sphere;
    }
};

class CubeFactory : public Factory{
public:
    Graphics * createGraphics() override{
        return new Cube;
    }
};

int main(){
    Graphics* graphics;
    SphereFactory sphereFactory;
    graphics = sphereFactory.createGraphics();
    graphics->painter();
    CubeFactory cubeFactory;
    graphics = cubeFactory.createGraphics();
    graphics->painter();
    return 0;
}

// 输出
// 绘制球形
// 绘制长方体
