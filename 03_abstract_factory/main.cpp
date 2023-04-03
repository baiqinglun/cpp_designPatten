/*
 * Created by 23984 on 2023/4/2.
 * 抽象工厂方法
 * 是工厂方法模式的一种演变。有时候我们需要创建静态或者会动的球形或者长方体，抽象工厂应运而生。
 * 1. 定义一个图形抽象类,类中添加绘制图形的纯虚函数,球形类和长方体继承该图形抽象类,并重写纯虚函数.
 * 2. 定义一个抽象工厂Factory，纯虚函数创建图形.创建球形工厂和创建长方体工厂继承自该工厂。并重写纯虚函数。
 * */

#include "iostream"

// 静态图形
class StaticGraphics{
public:
    virtual void painter() = 0;
};
// 球形
class StaticSphere : public StaticGraphics{
public:
    void painter() override{
        std::cout << "绘制静态球体"<<std::endl;
    }
};
// 长方体
class StaticCube : public StaticGraphics{
public:
    void painter() override{
        std::cout << "绘制静态长方体"<<std::endl;
    }
};

// 动态图形
class DynamicGraphics{
public:
    virtual void painter() = 0;
};
// 球形
class DynamicSphere : public DynamicGraphics{
public:
    void painter() override{
        std::cout << "绘制动态球体"<<std::endl;
    }
};
// 长方体
class DynamicCube : public DynamicGraphics{
public:
    void painter() override{
        std::cout << "绘制动态长方体"<<std::endl;
    }
};

// 工厂方法
class Factory{
public:
    virtual StaticGraphics* createStaticGraphics() = 0;
    virtual DynamicGraphics* createDynamicGraphics() = 0;
};
// 球体
class SphereFactory : public Factory{
public:
    StaticGraphics * createStaticGraphics() override{
        return new StaticSphere;
    }
    DynamicGraphics * createDynamicGraphics() override{
        return new DynamicSphere;
    }
};
// 长方体
class CubeFactory : public Factory{
public:
    StaticGraphics * createStaticGraphics() override{
        return new StaticCube;
    }
    DynamicGraphics * createDynamicGraphics() override{
        return new DynamicCube;
    }
};

int main(){
    // 定义工厂和图形
    SphereFactory sphereFactory;
    CubeFactory cubeFactory;
    StaticGraphics* staticGraphics;
    DynamicGraphics* dynamicGraphics;

    // 创建球体
    staticGraphics = sphereFactory.createStaticGraphics();
    dynamicGraphics = sphereFactory.createDynamicGraphics();
    staticGraphics->painter();
    dynamicGraphics->painter();

    // 创建长方体
    staticGraphics = cubeFactory.createStaticGraphics();
    dynamicGraphics = cubeFactory.createDynamicGraphics();
    staticGraphics->painter();
    dynamicGraphics->painter();
    return 0;
}

// 输出
// 绘制静态球体
// 绘制动态球体
// 绘制静态长方体
// 绘制动态长方体
