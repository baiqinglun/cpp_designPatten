# cpp_objectModel
c++对象模型

# 1、工厂模式

### 1.1 简单工厂

1. 定义一个图形抽象类,类中添加绘制图形的纯虚函数,球形类和长方体继承该图形抽象类,并重写纯虚函数.
2. 定义一个工厂Factory用于创建图形.工厂中有个create函数可以根据传入的参数new一个相应的图形并返回.

```c++
/*
 * Created by 23984 on 2023/4/2.
 * 简单工厂模式
 * 1. 定义一个图形抽象类,类中添加绘制图形的纯虚函数,球形类和长方体继承该图形抽象类,并重写纯虚函数.
 * 2. 定义一个工厂Factory用于创建图形.工厂中有个create函数可以根据传入的参数new一个相应的图形并返回.
 * */

#include "iostream"

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

```

## 1.2 工厂方法模式

简单工厂每次新增创建图形类，就需要修改Factory工厂的创建方法,违反了开放开放封闭原则。

使用工厂模式为每个图形添加一个工厂。

1. 定义一个图形抽象类,类中添加绘制图形的纯虚函数,球形类和长方体继承该图形抽象类,并重写纯虚函数.
2. 定义一个抽象工厂Factory，纯虚函数创建图形.创建球形工厂和创建长方体工厂继承自该工厂。并重写纯虚函数。

```c++
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

```

## 1.3 抽象工厂

是工厂方法模式的一种演变。有时候我们需要创建静态或者会动的球形或者长方体，抽象工厂应运而生。

1. 定义一个图形抽象类,类中添加绘制图形的纯虚函数,球形类和长方体继承该图形抽象类,并重写纯虚函数.
2. 定义一个抽象工厂Factory，纯虚函数创建图形.创建球形工厂和创建长方体工厂继承自该工厂。并重写纯虚函数。

```c++
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

```

# 2、策略模式

将一个类的行为委托给另一个类实现。

**策略模式是指定义一系列的算法，把它们一个个封装起来，并且使它们可相互替换**。
这里以Cache中的替换算法举例。本案例中Cache中replaceAlgorithm不自己实现，通过其他算法类实现。

![image.png](https://test-123456-md-images.oss-cn-beijing.aliyuncs.com/img/20230402154638.png)

1、定义算法类

```c++
class ReplaceAlgorithm{  
public:  
    virtual void replace() = 0;  
};  
  
class FIFO_ReplaceAlgorithm : public ReplaceAlgorithm{  
public:  
    void replace() override{  
        std::cout << "FIFO_ReplaceAlgorithm被调用" << std::endl;  
    }  
};  
class LRU_ReplaceAlgorithm : public ReplaceAlgorithm{  
public:  
    void replace() override{  
        std::cout << "LRU_ReplaceAlgorithm被调用" << std::endl;  
    }  
};  
class Random_ReplaceAlgorithm : public ReplaceAlgorithm{  
public:  
    void replace() override{  
        std::cout << "Random_ReplaceAlgorithm被调用" << std::endl;  
    }  
};
```

实现Cache调用上述算法有3种方法

- 构造函数传入算法对象；
- 构造函数传入算法类型，在构造函数中new一个算法；
- 避免传入参数，使用模板实现。
  **方法一**

```c++
// 方法一  
class Cache{  
private:  
    ReplaceAlgorithm *m_ra;  
public:  
    Cache(ReplaceAlgorithm *ra):m_ra(ra){};  
    ~Cache(){  
        delete m_ra;  
    };  
    void replaceAlgorithm(){  
        m_ra->replace();  
    }  
};

int main()
{
   Cache cache(new FIFO_ReplaceAlgorithm());  
   Cache cache1(new LRU_ReplaceAlgorithm());  
   Cache cache2(new Random_ReplaceAlgorithm());  
   cache.replaceAlgorithm();  
   cache1.replaceAlgorithm();  
   cache2.replaceAlgorithm();  
// 输出  
// FIFO_ReplaceAlgorithm被调用  
// LRU_ReplaceAlgorithm被调用  
// Random_ReplaceAlgorithm被调用
}
```

**方法二**

```c++
enum ALGORITHM_TYPE{  
    FIFO,  
    LRU,  
    RANDOM  
};  
class Cache{  
private:  
    ReplaceAlgorithm *m_ra;  
public:  
    Cache(enum ALGORITHM_TYPE type){  
        switch (type) {  
            case FIFO:  
                m_ra = new FIFO_ReplaceAlgorithm;  
                break;  
            case LRU:  
                m_ra = new LRU_ReplaceAlgorithm;  
                break;  
            case RANDOM:  
                m_ra = new Random_ReplaceAlgorithm;  
                break;  
            default:  
                m_ra = nullptr;  
        }    };
    ~Cache(){  
        delete m_ra;  
    };
    void replaceAlgorithm(){  
        m_ra->replace();  
    }
};
    
int main(){
    方法二  
   Cache cache(ALGORITHM_TYPE::FIFO);  
   cache.replaceAlgorithm();  
   Cache cache1(ALGORITHM_TYPE::LRU);  
   cache1.replaceAlgorithm();  
   Cache cache2(ALGORITHM_TYPE::RANDOM);  
   cache2.replaceAlgorithm();  
// 输出  
// FIFO_ReplaceAlgorithm被调用  
// LRU_ReplaceAlgorithm被调用  
// Random_ReplaceAlgorithm被调用
}
```

**方法三**

```c++
template <class RA>  
class Cache{  
private:  
    RA m_ra;  
public:  
    Cache(){};  
    ~Cache(){};  
    void replaceAlgorithm(){  
        m_ra.replace();  
    }  
};

int main(){
	Cache<FIFO_ReplaceAlgorithm> cache;  
	cache.replaceAlgorithm();  
	return 0;
}
```

> 这里需要注意，使用这一种方法时，m_ra不能是一个指针，写成指针的形式，只是将FIFO_ReplaceAlgorithm传入过来，并没有实例化对象。如果非要写成指针形式，需要自己new对象。

```c++
template <class RA>  
class Cache{  
private:  
    RA *m_ra = new RA;  
public:  
    Cache(){};  
    ~Cache(){};  
    void replaceAlgorithm(){  
        m_ra-:>replace();  
    }  
};

int main(){
	Cache<FIFO_ReplaceAlgorithm> cache;  
	cache.replaceAlgorithm();  
	return 0;
}
```

# 3、适配器模式

C++适配器模式（Adapter Pattern）是一种结构型设计模式，它允许将不兼容的接口转换为客户端希望的接口。
适配器模式通常使用在以下场景：

1.  当**已有的类**无法满足客户端的需求时，可以使用适配器模式**对已有类的接口进行转换**，以满足客户端的需求。
2.  当需要使用某个类，但该类的接口与另一个类的接口不兼容时，可以使用适配器模式进行转换。

适配器模式通常包含以下角色：

1.  目标接口（Target）：客户端希望使用的接口。
2.  源接口（Adaptee）：已有的接口，需要被转换。
3.  适配器（Adapter）：实现目标接口，并通过调用源接口的方法，实现目标接口与源接口的适配

适配器模式可以分为类适配器模式和对象适配器模式：

1.  类适配器模式：使用继承的方式实现适配器。
2.  对象适配器模式：使用组合的方式实现适配器。

![image.png](https://test-123456-md-images.oss-cn-beijing.aliyuncs.com/img/20230402170122.png)
**代码示例**

```c++
/*  
 * Created by 23984 on 2023/4/2. * 适配器模式  
 * 适配器模式（Adapter Pattern）是一种结构型设计模式，它允许将不兼容的接口转换为客户端希望的接口。  
 * STL实现了一种数据结构，称为双端队列（deque），支持前后两段的插入与删除。STL实现栈和队列时，没有从头开始定义它们，而是直接使用双端队列实现的。  
 * 这里双端队列就扮演了适配器的角色。队列用到了它的后端插入，前端删除。而栈用到了它的后端插入，后端删除。  
 * */  
#include "iostream"  
  
class Deque{  
public:  
    void push_back(int x){  
        std::cout << "Deque push_back" << std::endl;  
    }  
    void push_front(int x){  
        std::cout << "Deque push_front" << std::endl;  
    }  
    void pop_back(){  
        std::cout << "Deque pop_back" << std::endl;  
    }  
    void pop_front(){  
        std::cout << "Deque pop_front" << std::endl;  
    }  
};  
  
class Sequence{  
public:  
    virtual void push(int x) = 0;  
    virtual void pop() = 0;  
};  
class Stack : public Sequence{  
public:  
    void push(int x) override{  
        deque.push_back(x);  
    }  
    void pop() override{  
        deque.pop_back();  
    };  
private:  
    Deque deque;  
};  
class Queue : public Sequence{  
public:  
    void push(int x) override{  
        deque.push_front(x);  
    }  
    void pop() override{  
        deque.pop_front();  
    };  
private:  
    Deque deque;  
};  
  
int main(){  
    Sequence *s1 = new Stack();  
    Sequence *s2 = new Queue();  
    s1->push(1);  
    s1->pop();  
    s2->push(1);  
    s2->pop();  
    return 0;  
}  
  
// 输出  
// Deque push_back  
// Deque pop_back  
// Deque push_front  
// Deque pop_front
```

# 4、单例模式
