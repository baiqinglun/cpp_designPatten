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