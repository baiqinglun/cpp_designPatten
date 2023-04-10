#include <iostream>
using namespace std;

// 手机类
class Phone
{
public:
  Phone(){};
  virtual ~Phone(){};
  virtual void ShowDecorate(){};
};

class iPhone : public Phone
{
private:
  string m_name;

public:
  iPhone(string name) : m_name(name){};
  ~iPhone(){};
  void ShowDecorate() override { cout << m_name << "的装饰："; }
};

class NokiiaPhone : public Phone
{
private:
  string m_name;

public:
  NokiiaPhone(string name) : m_name(name){};
  ~NokiiaPhone(){};
  void ShowDecorate() override { cout << m_name << "的装饰："; }
};

// 装饰器基类
class DecoratorPhone : public Phone
{
private:
  Phone *m_phone;

public:
  DecoratorPhone(Phone *phone) : m_phone(phone){};
  ~DecoratorPhone(){};
  virtual void ShowDecorate() { m_phone->ShowDecorate(); };
};

// 挂件装饰器
class DecoratorPhoneA : public DecoratorPhone
{
public:
  DecoratorPhoneA(Phone *phone) : DecoratorPhone(phone){};
  void ShowDecorate()
  {
    DecoratorPhone::ShowDecorate();
    AddDecorate();
  }

private:
  void AddDecorate()
  {
    cout << "增加挂件" << endl;
  }
};

// 贴膜装饰器
class DecoratorPhoneB : public DecoratorPhone
{
public:
  DecoratorPhoneB(Phone *phone) : DecoratorPhone(phone){};
  void ShowDecorate()
  {
    DecoratorPhone::ShowDecorate();
    AddDecorate();
  }

private:
  void AddDecorate()
  {
    cout << "屏幕贴膜" << endl;
  }
};

int main()
{
  Phone *iphone = new NokiiaPhone("6300");
  Phone *dpa = new DecoratorPhoneA(iphone);
  Phone *dpb = new DecoratorPhoneB(iphone);
  dpb->ShowDecorate();
  delete dpa;
  delete dpb;
  delete iphone;
  return 0;
}
