/*
 * Created by 23984 on 2023/4/5.
 * 原型模式
 * 用原型实例指定创建对象的种类，并且通过拷贝这些原型创建新的对象。
 */
#include <iostream>
#include "cstring"
using namespace std;

class Shape
{
public:
  virtual Shape *clone() = 0;
  virtual void draw() = 0;
};

class Circle : public Shape
{
public:
  Circle() {}
  Circle(const Circle &other) {}
  virtual Circle *clone()
  {
    return new Circle(*this);
  }
  virtual void draw()
  {
    std::cout << "Drawing a circle.\n";
  }
};

class Square : public Shape
{
public:
  Square() {}
  Square(const Square &other) {}
  virtual Square *clone()
  {
    return new Square(*this);
  }
  virtual void draw()
  {
    std::cout << "Drawing a square.\n";
  }
};

int main()
{
  Circle *prototypeCircle = new Circle();
  Square *prototypeSquare = new Square();

  Shape *circle1 = prototypeCircle->clone();
  Shape *circle2 = prototypeCircle->clone();
  circle1->draw();
  circle2->draw();
  Shape *square1 = prototypeSquare->clone();
  square1->draw();

  return 0;
}