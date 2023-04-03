/*
 * Created by 23984 on 2023/4/2.
 * 简单工厂模式
 * 1. 定义一个图形抽象类,类中添加绘制图形的纯虚函数,球形类和长方体继承该图形抽象类,并重写纯虚函数.
 * 2. 定义一个工厂Factory用于创建图形.工厂中有个create函数可以根据传入的参数new一个相应的图形并返回.
 * */

#include "iostream"
using namespace std;
enum GRAPHICS_TYPE{
    SPHERE,
    CUBE
};

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
    static Graphics* createGraphics(enum GRAPHICS_TYPE type){
        switch (type) {
            case SPHERE:
                return new Sphere;
                break;
            case CUBE:
                return new Cube;
                break;
            default:
                return nullptr;
        }
    }

};

int main(){
    Graphics* graphics = Factory::createGraphics(GRAPHICS_TYPE::SPHERE);
    graphics->painter();
    graphics = Factory::createGraphics(GRAPHICS_TYPE::CUBE);
    graphics->painter();
    return 0;
}

// 输出
// 绘制球形
// 绘制长方体
