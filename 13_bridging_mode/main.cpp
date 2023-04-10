/*
 * Created by 23984 on 2023/4/5.
 * 桥接模式
 * 它旨在将抽象部分与实现部分分离开来，从而使它们可以独立地变化。
 */
#include <iostream>
using namespace std;

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