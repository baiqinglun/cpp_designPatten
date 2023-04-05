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