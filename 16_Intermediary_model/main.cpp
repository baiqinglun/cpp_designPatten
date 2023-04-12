#include <iostream>
#include <string>
#include <vector>

class Colleague;

// 中介者类
class Mediator {
public:
    virtual void sendMessage(const std::string& message, Colleague* colleague) = 0;
};

// 同事类
class Colleague {
public:
    Colleague(Mediator* mediator) : m_mediator(mediator) {}

    virtual void sendMessage(const std::string& message) {
        m_mediator->sendMessage(message, this);
    }

    virtual void receiveMessage(const std::string& message) = 0;

protected:
    Mediator* m_mediator;
};

// 具体同事类
class ConcreteColleagueA : public Colleague {
public:
    ConcreteColleagueA(Mediator* mediator) : Colleague(mediator) {}

    void receiveMessage(const std::string& message) override {
        std::cout << "ConcreteColleagueA received message: " << message << std::endl;
    }
};

class ConcreteColleagueB : public Colleague {
public:
    ConcreteColleagueB(Mediator* mediator) : Colleague(mediator) {}

    void receiveMessage(const std::string& message) override {
        std::cout << "ConcreteColleagueB received message: " << message << std::endl;
    }
};

class ConcreteColleagueC : public Colleague {
public:
    ConcreteColleagueC(Mediator* mediator) : Colleague(mediator) {}

    void receiveMessage(const std::string& message) override {
        std::cout << "ConcreteColleagueC received message: " << message << std::endl;
    }
};

// 具体中介者类
class ConcreteMediator : public Mediator {
public:
    void addColleague(Colleague* colleague) {
        m_colleagues.push_back(colleague);
    }

    void sendMessage(const std::string& message, Colleague* sender) override {
        for (auto colleague : m_colleagues) {
            if (colleague != sender) {
                colleague->receiveMessage(message);
            }
        }
    }

private:
    std::vector<Colleague*> m_colleagues;
};

int main() {
    ConcreteMediator mediator;

    ConcreteColleagueA colleagueA(&mediator);
    ConcreteColleagueB colleagueB(&mediator);
    ConcreteColleagueC colleagueC(&mediator);

    mediator.addColleague(&colleagueA);
    mediator.addColleague(&colleagueB);
    mediator.addColleague(&colleagueC);

    colleagueA.sendMessage("Hello, colleagueB和C!");
    colleagueB.sendMessage("Hi, colleagueA和C!");

    return 0;
}