#include<iostream>
using namespace std;

// 抽象状态(State)基类
class State {
public:
    virtual void Handle() = 0;
};

// 具体状态
class ConcreteStateA : public State {
public:
    void Handle() override {
        std::cout << "Handle state A." << std::endl;
    }
};

class ConcreteStateB : public State {
public:
    void Handle() override {
        std::cout << "Handle state B." << std::endl;
    }
};

// 创建一个Context类，它包含一个当前状态对象和一些可以在状态对象之间转换的方法
class Context {
public:
    void SetState(State* state) {
        m_state = state;
    }
    void Request() {
        m_state->Handle();
    }
private:
    State* m_state;
};


int main(){
    ConcreteStateA stateA;
    ConcreteStateB stateB;

    Context context;
    context.SetState(&stateA);
    context.Request();

    context.SetState(&stateB);
    context.Request();

}