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

  return 0;
}