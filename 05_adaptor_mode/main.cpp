/*
 * Created by 23984 on 2023/4/2.
 * 适配器模式
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
