# cpp_objectModel
c++对象模型

# 1、工厂模式

## 1.1 简单工厂

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
单例模式是一种常见的软件设计模式，它保证*一个类只有一个实例*，并且提供一个全局访问点来访问该实例。

在单例模式中，通常会将类的构造函数私有化，以避免外部代码直接创建该类的对象实例。同时，该类会定义一个静态方法或静态成员变量来访问类的唯一实例。如果该实例不存在，则该静态方法或成员变量会创建一个新的实例，并返回该实例；如果实例已经存在，则直接返回该实例。

单例模式的优点是：
1. 保证系统中只有一个实例，减少了资源的占用，避免了不必要的内存浪费。
2. 对于某些需要频繁创建和销毁对象的场景，使用单例模式可以减少系统的开销。
3. 单例模式可以全局访问，方便统一管理和调用。

单例模式也存在一些缺点:
1. 单例模式会对代码的可测试性造成影响，因为单例实例在整个系统中只存在一个，很难进行单元测试。
2. 单例模式的实现有时会牵扯到复杂的线程同步操作，如果实现不当，可能会导致死锁等问题。

```c++
// 只有一个类
class Singleton
{
public:
   static Singleton *getInstance(const char *name);
   virtual void show(){};
   ~Singleton()
   {
      cout << "Singleton析构函数调用" << endl;
      singleton = nullptr;
      delete singleton;
   };

protected:
   // 这里的构造函数必须为protected，否则子类不法访问父类构造函数
   Singleton()
   {
      cout << "Singleton构造函数调用" << endl;
   };

private:
   static Singleton *singleton;
};

// SingletonA
class SingletonA : public Singleton
{
   friend class Singleton; // 必须为友元，否则父类无法访问子类的构造函数
public:
   void show()
   {
      std::cout << "SingletonA的show调用" << std::endl;
   }

   ~SingletonA()
   {
      cout << "SingletonA析构函数调用" << endl;
   };

private:
   SingletonA()
   {
      cout << "SingletonA构造函数调用" << endl;
   };
};

// SingletonB
class SingletonB : public Singleton
{
   friend class Singleton; // 必须为友元，否则父类无法访问子类的构造函数
public:
   void show()
   {
      std::cout << "SingletonB的show调用" << std::endl;
   }

   ~SingletonB()
   {
      cout << "SingletonB析构函数调用" << endl;
   };

private:
   SingletonB()
   {
      cout << "SingletonB构造函数调用" << endl;
   };
};

// 初始化静态成员变量singleton
Singleton *Singleton::singleton = nullptr;
// 初始化实例函数
Singleton *Singleton::getInstance(const char *name)
{
   if (singleton == nullptr)
   {
      if (strcmp(name, "singletonA") == 0)
      {
         singleton = new SingletonA();
      }
      else if (strcmp(name, "singletonB") == 0)
      {
         singleton = new SingletonB();
      }
      else
      {
         singleton = new Singleton();
      }
   }
   return singleton;
}
```

测试
```c++
int main()
{
   Singleton *st = Singleton::getInstance("singletonA");
   st->show();
   delete st;
   st = Singleton::getInstance("singletonB");
   st->show();
   return 0;
}
```
如果不delete掉st，再赋值为singletonB没有反应

```c++
int main()
{
   Singleton *st = Singleton::getInstance("singletonA");
   st->show();
   // st = nullptr;
   // delete st;
   Singleton *st1 = Singleton::getInstance("singletonB");
   st1->show();
   return 0;
}
```
这样也不行，还是只要st存在，就会返回Singleton::singleton

# 5、原型模式
1. 原型模式（Prototype Pattern）是一种**创建型设计模式**，它允许通过复制现有对象来创建新的对象，而无需知道对象的具体实现细节。在原型模式中，我们可以将现有对象作为原型，然后通过复制该原型来创建新的对象。
2. 使用原型模式的一个显著优点是可以避免重复创建相似的对象，从而提高程序的性能和效率。另外，原型模式也可以用来隐藏对象创建的细节，从而使代码更加简洁和易于维护。
3. 在实现原型模式时，通常需要在原型类中定义一个clone()方法，用于创建并返回一个新的对象实例。**clone()**方法通常会先创建一个与原型对象相同类型的新对象，然后将原型对象的状态复制到新对象中，最后返回新对象。在C++中，我们可以使用拷贝构造函数或赋值运算符来实现对象的复制。

![](https://test-123456-md-images.oss-cn-beijing.aliyuncs.com/img/20230405153846.png)


**代码示例**
```c++
class Shape {
public:
    virtual Shape* clone() = 0;
    virtual void draw() = 0;
};

class Circle : public Shape {
public:
    Circle() {}
    Circle(const Circle& other) {}
    virtual Shape* clone() {
        // return new Circle(*this) 的作用是创建一个新的 Circle 对象，并返回该对象的指针，从而实现了原型模式的复制功能
        // *this指的是当前的Circle对象
        // new Circle(*this)会调用拷贝构造函数
        return new Circle(*this); 
    }
    virtual void draw() {
        std::cout << "Drawing a circle.\n";
    }
};

class Square : public Shape {
public:
    Square() {}
    Square(const Square& other) {}
    virtual Shape* clone() {
        return new Square(*this);
    }
    virtual void draw() {
        std::cout << "Drawing a square.\n";
    }
};
```
> `return new Circle(*this);`
> // return new Circle(*this) 的作用是创建一个新的 Circle 对象，并返回该对象的指针，从而实现了原型模式的复制功能
> // *this指的是当前的Circle对象
> // new Circle(*this)会调用拷贝构造函数

**测试**
```c++

int main()
{
  Circle* prototypeCircle = new Circle();
  Square* prototypeSquare = new Square();

  Shape* circle1 = prototypeCircle->clone();
  Shape* circle2 = prototypeCircle->clone();
  circle1->draw();
  circle2->draw();
  Shape* square1 = prototypeSquare->clone();
  square1->draw();
  
  return 0;
}
```

# 6、建造者模式

建造者模式（Builder Pattern）是一种创建型设计模式，它允许你使用相同的构建过程来创建不同的表示形式。

建造者模式的主要目的是将一个复杂对象的构建过程分离出来，使其可以独立于主要的业务逻辑而变化。通过使用建造者模式，我们可以更加灵活地创建复杂的对象，而不需要关心其具体的构建过程。

建造者模式通常由以下几个角色组成：

1. Director（指挥者）：负责调用建造者来构建产品，并控制建造的流程。
2. Builder（建造者）：负责定义产品的构建过程，以及如何组装各个部件。
3. Concrete Builder（具体建造者）：负责实现 Builder 接口，以定义产品的各个部件的具体构建方式。
4. Product（产品）：要创建的复杂对象，通常由多个部件组成。

![](https://test-123456-md-images.oss-cn-beijing.aliyuncs.com/img/20230405160820.png)

```c++
/*
 * Created by 23984 on 2023/4/5.
 * 建造者模式
 * 将一个复杂对象的构建过程分离出来，使其可以独立于主要的业务逻辑而变化
 */

#include <iostream>
using namespace std;

// 要创建的复杂对象，通常由多个部件组成。 
class Product {
public:
    void set_part_a(const std::string& part_a) {
        part_a_ = part_a;
    }
    void set_part_b(const std::string& part_b) {
        part_b_ = part_b;
    }
    void set_part_c(const std::string& part_c) {
        part_c_ = part_c;
    }
    void print_parts() const {
        std::cout << "Part A: " << part_a_ << "\n";
        std::cout << "Part B: " << part_b_ << "\n";
        std::cout << "Part C: " << part_c_ << "\n";
    }
private:
    std::string part_a_;
    std::string part_b_;
    std::string part_c_;
};

// 负责定义产品的构建过程，以及如何组装各个部件。
class Builder {
public:
    virtual void build_part_a() = 0;
    virtual void build_part_b() = 0;
    virtual void build_part_c() = 0;
    virtual Product* get_product() = 0;
};

// 负责实现 Builder 接口，以定义产品的各个部件的具体构建方式。
class ConcreteBuilder : public Builder {
public:
    ConcreteBuilder() : product_(new Product()) {}
    virtual void build_part_a() {
        product_->set_part_a("Part A");
    }
    virtual void build_part_b() {
        product_->set_part_b("Part B");
    }
    virtual void build_part_c() {
        product_->set_part_c("Part C");
    }
    virtual Product* get_product() {
        return product_;
    }
private:
    Product* product_;
};

// 负责调用建造者来构建产品，并控制建造的流程。
class Director {
public:
    Director(Builder* builder) : builder_(builder) {}
    void construct() {
        builder_->build_part_a();
        builder_->build_part_b();
        builder_->build_part_c();
    }
private:
    Builder* builder_;
};

int main() {
    ConcreteBuilder builder1;
    Director director(&builder1);
    director.construct();
    Product* product = builder1.get_product();
    product->print_parts();
    delete product;
    return 0;
}
```

# 7、外观模式
C++外观模式是一种设计模式，它提供了一个简单的接口，用于访问复杂系统的子系统。外观模式隐藏了系统的复杂性，并为客户端提供了一个简单的接口，以便于使用系统。

在C++中，外观模式通常涉及到一个外观类，该类封装了**子系统**的复杂性，并提供了一个简单的接口，用于访问子系统的功能。客户端只需要与外观类交互，并不需要了解子系统的工作原理。

下面以数值迷你过程举例，数值模拟一般包括建模、划分网格、计算和后处理4部分。

![](https://test-123456-md-images.oss-cn-beijing.aliyuncs.com/img/20230405200558.png)

示例代码如下

```c++
/*
 * Created by 23984 on 2023/4/5.
 * 外观模式
 * 当一个系统很复杂时，系统提供给客户的是一个简单的对外接口，而把里面复杂的结构都封装了起来。
 */

#include <iostream>
using namespace std;

class Model{
public:
  void createModel(){
    cout << "建模" << endl;
  }
};

class Mesh{
public:
  void createMesh(){
    cout << "划分网格" << endl;
  }
};

class Caculate{
public:
  void numericalCalculation(){
    cout << "数值计算" << endl;
  }
};

class PostProcess{
public:
  void pprocess(){
    cout << "后处理" << endl;
  }
};

class Simulation{
public:
  Simulation():model_(new Model()),mesh_(new Mesh()),cal_(new Caculate()),post_(new PostProcess()){};
  void simulate(){
    model_->createModel();
    mesh_->createMesh();
    cal_->numericalCalculation();
    post_->pprocess();
  }
private:
  Model *model_;
  Mesh *mesh_;
  Caculate *cal_;
  PostProcess *post_;
};

int main()
{
  Simulation s;
  s.simulate();

  return 0;
}
```

# 8、组合模式

C++组合模式是一种设计模式，它允许我们将对象组成<u>**树形**</u>结构，以表示“整体/部分”层次结构。组合模式使我们能够以一致的方式处理单个对象和对象的组合。

在C++中，组合模式通常涉及到一个组件类，该类定义了表示“整体/部分”层次结构的所有对象的通用接口。组件类可以是抽象的，也可以是具体的。

组件类可以有子类，这些子类可以是叶子节点，也可以是组合节点。叶子节点表示树中的单个对象，而组合节点表示树中的对象组合。组合节点可以包含一个或多个子节点，这些子节点可以是叶子节点，也可以是组合节点。

![](https://test-123456-md-images.oss-cn-beijing.aliyuncs.com/img/20230405205839.png)

```c++
/*
 * Created by 23984 on 2023/4/5.
 * 组合模式
 * 对象组合成树形结构以表示“部分-整体”的层次结构。组合使得用户对单个对象和组合对象的使用具有一致性
 */
#include <iostream>
#include <list>
using namespace std;

class Item
{
public:
  Item(string name) : name_(name){};
  virtual ~Item(){};
  virtual void Add(Item *aItem){};
  virtual void Show(int depth){};

protected:
  string name_;
};

class Folder : public Item
{
public:
  Folder(string name) : Item(name){};
  ~Folder() override{};
  void Add(Item *aItem)
  {
    item_list_.push_back(aItem);
  };
  void Show(int depth)
  {
    for (int i = 0; i < depth; i++)
    {
      /* code */
      cout << "-";
    }
    cout << name_ << endl;
    list<Item *>::iterator iter = item_list_.begin();
    for (; iter != item_list_.end(); iter++)
    {
      /* code */
      (*iter)->Show(depth + 2);
    }
  }

private:
  list<Item *> item_list_;
};

class GraphicsA : public Item
{
public:
  GraphicsA(string name) : Item(name){};
  ~GraphicsA() override{};
  void Show(int depth)
  {
    for (int i = 0; i < depth; i++)
    {
      cout << "-";
    }
    cout << name_ << endl;
  }
};

class GraphicsB : public Item
{
public:
  GraphicsB(string name) : Item(name){};
  ~GraphicsB() override{};
  void Show(int depth)
  {
    for (int i = 0; i < depth; i++)
    {
      cout << "-";
    }
    cout << name_ << endl;
  }
};

int main()
{
  Item *root = new Folder("总分组");
  Item *b1 = new GraphicsA("球1");
  Item *c1 = new GraphicsB("立方体1");
  root->Add(b1);
  root->Add(c1);

  Item *f1 = new Folder("分组1");
  Item *b2 = new GraphicsA("球2");
  Item *c2 = new GraphicsB("立方体2");
  f1->Add(b2);
  f1->Add(c2);
  root->Add(f1);

  root->Show(0);

  delete root;
  delete b1;
  delete c1;
  delete f1;
  delete b2;
  delete c2;
  return 0;
}
```
输出

![](https://test-123456-md-images.oss-cn-beijing.aliyuncs.com/img/20230405204311.png)

> 注意这里的show函数传入了一个深度，深度递增+2.root调用时show传入的为0，b1、c1和f1传入时show调用的是2，b2和c2调用时传入的是4.
> 
上面的实现方式有缺点，就是内存的释放不好，需要客户自己动手，非常不方便。有待改进，比较好的做法是让Folder类来释放。因为所有的指针都是存在Folder类的链表中。

# 9、代理模式

允许我们提供一个代理对象来<u>**控制对另一个对象的访问**</u>。代理模式使我们能够在不改变原始对象的情况下，增强其功能或控制其访问。

在C++中，代理模式通常涉及到一个代理类和一个原始类。代理类实现了与原始类相同的接口，并在其内部维护一个对原始对象的引用。代理类可以拦截对原始对象的访问，并根据需要将其转发给原始对象。

主要分为（1）远程代理，（2）虚代理，（3）保护代理，（4）智能引用。本文主要介绍虚代理和智能引用两种情况。

## 9.1 虚代理

![代理模式](https://mmbiz.qpic.cn/mmbiz_jpg/8pECVbqIO0y4v6U2GWEqj1wOpq0tQgnKBOPUTlooMiaDichaA8sjurqucSvLElA54Ib0IayKdpXhia3p0Bz6ZwxpQ/640?wx_fmt=jpeg&tp=wxpic&wxfrom=5&wx_lazy=1&wx_co=1)

```c++
/*
 * Created by 23984 on 2023/4/5.
 * 代理模式
 * 允许我们提供一个代理对象来控制对另一个对象的访问。代理模式使我们能够在不改变原始对象的情况下，增强其功能或控制其访问。
 */
#include <iostream>
using namespace std;

// 图片基类
class Image  
{  
public:  
    Image(string name): imageName_(name) {}  
    virtual ~Image() {}  
    virtual void Show() {}  
protected:  
    string imageName_;  
};  

// 大图片
class BigImage: public Image  
{  
public:  
    BigImage(string name):Image(name) {}  
    ~BigImage() {}  
    void Show() { cout<<"Show big image : "<<imageName_<<endl; }  
};  

// 大图片代理
class BigImageProxy: public Image  
{  
private:  
    BigImage *bigImage_;  // 大图片
public:  
    BigImageProxy(string name):Image(name),bigImage_(nullptr) {}  
    ~BigImageProxy() { delete bigImage_; }  
    void Show()   
    {  
        if(bigImage_ == nullptr)  
            bigImage_ = new BigImage(imageName_);  
        bigImage_->Show();  
    }  
};

int main() {
    Image *image = new BigImageProxy("proxy.jpg"); //代理  
    image->Show(); //需要时由代理负责打开  
    delete image;  

    return 0;
}

```

## 9.2 引用代理
手写一个auto_ptr
```c++
#include <iostream>
using namespace std;

template <typename T>
class auto_ptr
{
public:
  explicit auto_ptr(T *p = nullptr) : pointee(p){};
  auto_ptr(auto_ptr<T> &rhs) : pointee(rhs.release()){};
  ~auto_ptr() { delete pointee; };
  auto_ptr<T> &operator=(auto_ptr &rhs)
  {
    if (this != &rhs)
      reset(rhs.release());
    return *this;
  }
  T &operator*() const { return *pointee; };
  T &operator->() const { return pointee; };
  T *get() const { return pointee; };
  T *release()
  {
    T *oldPointee = pointee;
    pointee = nullptr;
    return oldPointee;
  }
  void reset(T *p = nullptr)
  {
    if (pointee != p)
    {
      delete pointee;
      pointee = p;
    }
  }

private:
  T *pointee;
};

int main()
{
  auto_ptr<int> p1(new int(42));
  auto_ptr<int> p2 = p1;
  cout << *p2 <<endl;
  auto p3 = new int(50);
  p2.reset(p3);
  cout << *p2 <<endl;

  return 0;
}
```
# 10、享元模式
1. C++中的享元模式是一种**结构型设计模式**，它旨在通过共享对象来最小化内存使用和对象创建的开销。
2. 在享元模式中，对象的状态被分为**内部状态**和**外部状态**，其中内部状态是对象的固有属性，而外部状态则是在运行时由客户端传递给对象的信息。
3. 在C++中，实现享元模式需要定义一个享元工厂类和一个享元类。
4. 享元工厂类负责创建和管理享元对象，而享元类则负责存储和处理对象的内部状态和外部状态。

比如：在设计一款游戏时，里面有很多的怪物，这些怪物虽然分为不同的类别，但每种都有自己的血条、攻击力和防御力。
1. 定义一个map，用于存储哥布林、兽人和龙；
2. 创建哥布林对象，如果已经存在哥布林对象，返回已存在的哥布林的引用，否则新建哥布林对象；
3. 可以验证g1和g2是同一个对象的引用。

```c++
/*
 * Created by 23984 on 2023/4/5.
 * 享元模式
 * C++中的享元模式是一种结构型设计模式，它旨在通过共享对象来最小化内存使用和对象创建的开销。
 * 在享元模式中，对象的状态被分为内部状态和外部状态，其中内部状态是对象的固有属性，而外部状态则是在运行时由客户端传递给对象的信息。
 * 在C++中，实现享元模式需要定义一个享元工厂类和一个享元类。
 * 享元工厂类负责创建和管理享元对象，而享元类则负责存储和处理对象的内部状态和外部状态。
 */
#include <iostream>
#include <map>
using namespace std;

class Monster
{
public:
  Monster(int hp, int atk, int def) : hp_(hp), atk_(atk), def_(def){};
  void stack()
  {
  }

private:
  int hp_;
  int atk_;
  int def_;
};

class MonsterFactory
{
public:
  Monster *getMonster(const std::string &name)
  {
    auto it = monsterMap_.find(name);
    if (it != monsterMap_.end())
    {
      return it->second;
    }
    Monster *monster = createMonster(name);
    monsterMap_[name] = monster;
    return monster;
  }

private:
  std::map<std::string, Monster *> monsterMap_;
  Monster *createMonster(const std::string &name)
  {
    if (name == "Goblin")
    {
      return new Monster(50, 10, 5);
    }
    else if (name == "Orc")
    {
      return new Monster(100, 20, 10);
    }
    else
    {
      return new Monster(200, 30, 20);
    }
  }
};

int main()
{
  MonsterFactory monsterFactory;
  Monster *g1 = monsterFactory.getMonster("Goblin");
  Monster *g2 = monsterFactory.getMonster("Goblin");
  Monster *o1 = monsterFactory.getMonster("Orc");
  Monster *o2 = monsterFactory.getMonster("Orc");
  Monster *d1 = monsterFactory.getMonster("Dragon");
  Monster *d2 = monsterFactory.getMonster("Dragon");

  cout << (g1 == g2) << endl;
  cout << (o1 == o2) << endl;
  cout << (d1 == d2) << endl;
  cout << g1->second << endl;

  return 0;
}
```

## 绘制棋盘案例
1. 虽然棋盘上有很多的棋子，但他们不是白色都是黑色，每种颜色的属性都一致，只是位置不同。我们将位置单独存放。
2. 创建白色棋子时，如果已经存在一个对象，就直接向容器中添加位置；如果不存在，则需要先创建，再添加位置；
3. 这样所有的白色只享一个对象，极大地节约内存空间。


```c++
#include <iostream>
#include <vector>
using namespace std;

//棋子颜色  
enum PieceColor {BLACK, WHITE};  
//棋子位置  
struct PiecePos  
{  
    int x;  
    int y;  
    PiecePos(int a, int b): x(a), y(b) {}  
};  
//棋子定义  
class Piece  
{  
protected:  
    PieceColor m_color; //颜色  
public:  
    Piece(PieceColor color): m_color(color) {}  
    ~Piece() {}  
    virtual void Draw() {}  
};  
class BlackPiece: public Piece  
{  
public:  
    BlackPiece(PieceColor color): Piece(color) {}  
    ~BlackPiece() {}  
    void Draw() { cout<<"绘制一颗黑棋\n"; }  
};  
class WhitePiece: public Piece  
{  
public:  
    WhitePiece(PieceColor color): Piece(color) {}  
    ~WhitePiece() {}  
    void Draw() { cout<<"绘制一颗白棋\n";}  
};

class PieceBoard  
{  
private:  
    vector<PiecePos> m_vecPos; //存放棋子的位置  
    // 虽然棋盘上有很多的棋子，但他们不是白色都是黑色，每种颜色的属性都一致，只是位置不同。我们将位置单独存放。
    Piece *m_blackPiece;        
    Piece *m_whitePiece;       
    string m_blackName;  
    string m_whiteName;  
public:  
    PieceBoard(string black, string white): m_blackName(black), m_whiteName(white)  
    {  
        m_blackPiece = null;  
        m_whitePiece = NULL;  
    }  
    ~PieceBoard() { delete m_blackPiece; delete m_whitePiece;}  
    void SetPiece(PieceColor color, PiecePos pos)  
    {  
        if(color == BLACK)  
        {  
            if(m_blackPiece == NULL)  //只有一颗黑棋  
                m_blackPiece = new BlackPiece(color);     
            cout<<m_blackName<<"在位置("<<pos.x<<','<<pos.y<<")";  
            m_blackPiece->Draw();  
        }  
        else  
        {  
            if(m_whitePiece == NULL)  
                m_whitePiece = new WhitePiece(color);  
            cout<<m_whiteName<<"在位置("<<pos.x<<','<<pos.y<<")";  
            m_whitePiece->Draw();  
        }  
        m_vecPos.push_back(pos);  
    }  
};

int main()  
{  
    PieceBoard pieceBoard("A","B");  
    pieceBoard.SetPiece(BLACK, PiecePos(4, 4));  
    pieceBoard.SetPiece(WHITE, PiecePos(4, 16));  
    pieceBoard.SetPiece(BLACK, PiecePos(16, 4));  
    pieceBoard.SetPiece(WHITE, PiecePos(16, 16));  
}
```

# 11、桥接模式

C++中的桥接模式是一种结构型设计模式，**它旨在将抽象部分与实现部分分离开来，从而使它们可以独立地变化**。在桥接模式中，抽象部分和实现部分通过一个桥接接口进行连接，从而实现解耦和灵活性。

在C++中，实现桥接模式需要定义一个-**抽象基类**和一个**实现基类**，其中抽象基类定义了抽象部分的接口，而实现基类定义了实现部分的接口。然后，我们通过继承和组合来实现不同的抽象部分和实现部分的组合。

举一个操作系统的例子：

```c++
#include <iostream>
using namespace std;

//操作系统  
class OS  
{  
public:  
    virtual void InstallOS_Imp() {}  
};  
class WindowOS: public OS  
{  
public:  
    void InstallOS_Imp() { cout<<"安装Window操作系统"<<endl; }   
};  
class LinuxOS: public OS  
{  
public:  
    void InstallOS_Imp() { cout<<"安装Linux操作系统"<<endl; }   
};  
class UnixOS: public OS  
{  
public:  
    void InstallOS_Imp() { cout<<"安装Unix操作系统"<<endl; }   
};


//计算机  
class Computer  
{  
public:  
    virtual void InstallOS(OS *os) {}  
};  
class DellComputer: public Computer  
{  
public:  
    void InstallOS(OS *os) { os->InstallOS_Imp(); }  
};  
class AppleComputer: public Computer  
{  
public:  
    void InstallOS(OS *os) { os->InstallOS_Imp(); }  
};  
class HPComputer: public Computer  
{  
public:  
    void InstallOS(OS *os) { os->InstallOS_Imp(); }  
};

int main()  
{  
    OS *os1 = new WindowOS();  
    OS *os2 = new LinuxOS();  
    Computer *computer1 = new AppleComputer();  
    computer1->InstallOS(os1);  
    computer1->InstallOS(os2);  
}
```

## 绘制图形
```c++
/*
 * Created by 23984 on 2023/4/5.
 * 桥接模式
 * 它旨在将抽象部分与实现部分分离开来，从而使它们可以独立地变化。
 */
#include <iostream>
using namespace std;


// 抽象部分的接口
class Shape
{
public:
  virtual void draw() = 0;
};

// 抽象部分的实现
class Circle : public Shape
{
public:
  Circle(double x, double y, double radius, DrawingAPI *drawingAPI)
      : m_x(x), m_y(y), m_radius(radius), m_drawingAPI(drawingAPI) {}
  void draw() override
  {
    m_drawingAPI->drawCircle(m_x, m_y, m_radius);
  }

private:
  double m_x;
  double m_y;
  double m_radius;
  DrawingAPI *m_drawingAPI;
};

// 抽象部分的实现
class Rectangle : public Shape
{
public:
  Rectangle(double x1, double y1, double x2, double y2, DrawingAPI *drawingAPI)
      : m_x1(x1), m_y1(y1), m_x2(x2), m_y2(y2), m_drawingAPI(drawingAPI) {}
  void draw() override
  {
    m_drawingAPI->drawRectangle(m_x1, m_y1, m_x2, m_y2);
  }

private:
  double m_x1;
  double m_y1;
  double m_x2;
  double m_y2;
  DrawingAPI *m_drawingAPI;
};

// 实现部分的接口
class DrawingAPI
{
public:
  virtual void drawCircle(double x, double y, double radius) = 0;
  virtual void drawRectangle(double x1, double y1, double x2, double y2) = 0;
};

// 具体的实现部分
class DrawingAPI1 : public DrawingAPI
{
public:
  void drawCircle(double x, double y, double radius) override
  {
    cout << "API1.circle at " << x << ',' << y << ' ' << radius << endl;
  }
  void drawRectangle(double x1, double y1, double x2, double y2) override
  {
    cout << "API1.rectangle at " << x1 << ',' << y1 << " to " << x2 << ',' << y2 << endl;
  }
};

// 具体的实现部分
class DrawingAPI2 : public DrawingAPI
{
public:
  void drawCircle(double x, double y, double radius) override
  {
    cout << "API2.circle at " << x << ',' << y << ' ' << radius << endl;
  }
  void drawRectangle(double x1, double y1, double x2, double y2) override
  {
    cout << "API2.rectangle at " << x1 << ',' << y1 << " to " << x2 << ',' << y2 << endl;
  }
};



int main()
{
  DrawingAPI1 api1;
  DrawingAPI2 api2;

  Circle circle1(1, 2, 3, &api1);
  Rectangle rectangle1(0, 0, 1, 1, &api1);

  Circle circle2(4, 5, 6, &api2);
  Rectangle rectangle2(2, 2, 3, 3, &api2);

  circle1.draw();
  rectangle1.draw();
  circle2.draw();
  rectangle2.draw();

  return 0;
}
```