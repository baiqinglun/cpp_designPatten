/*
 * Created by 23984 on 2023/4/2.
 * 单例模式
 * 单例模式是一种常见的软件设计模式，它保证*一个类只有一个实例*，并且提供一个全局访问点来访问该实例.
 * 在单例模式中，通常会将类的构造函数私有化，以避免外部代码直接创建该类的对象实例。同时，该类会定义一个静态方法或静态成员变量来访问类的唯一实例。如果该实例不存在，则该静态方法或成员变量会创建一个新的实例，并返回该实例；如果实例已经存在，则直接返回该实例。

单例模式的优点是：
1. 保证系统中只有一个实例，减少了资源的占用，避免了不必要的内存浪费。
2. 对于某些需要频繁创建和销毁对象的场景，使用单例模式可以减少系统的开销。
3. 单例模式可以全局访问，方便统一管理和调用。

单例模式也存在一些缺点:
1. 单例模式会对代码的可测试性造成影响，因为单例实例在整个系统中只存在一个，很难进行单元测试。
2. 单例模式的实现有时会牵扯到复杂的线程同步操作，如果实现不当，可能会导致死锁等问题。
*/

#include "iostream"
#include "cstring"
using namespace std;

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
   // 这里的构造函数必须为protected，否则子类无法访问父类构造函数
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