#include<iostream>
#include<vector>
using namespace std;

// 类的前向声明
class Mediator;

// 人的基类
class Person{
public:
    virtual void SendMessage(string msg){};
    virtual void GetMessage(string msg){};
    virtual void SetMediator(Mediator* mediator){};
};

// 中介基类
class Mediator{
public:
    virtual void AddPerson(Person* person){}
    virtual void SendMessage(string msg,Person* person){}
};

// 实际中介类
class MediatorA : public Mediator{
private:
    vector<Person*> person_vector_;
public:
    void AddPerson(Person* person){
        person_vector_.push_back(person);
    }
    void SendMessage(string msg,Person* person){
        for (auto aPerson : person_vector_){
            if(aPerson != person){
                aPerson->GetMessage(msg);
            }
        }
        
    }
};

// 实际人类
class PersonA : public Person{
protected:
    Mediator *mediator_;
    string name_;
public:
    PersonA(string name):name_(name){};
    void SendMessage(string msg){
        mediator_->SendMessage(msg,this);
    };
    void GetMessage(string msg){
        cout << name_ << "获得信息" << msg << endl;
    };
    void SetMediator(Mediator* mediator){
        this->mediator_ = mediator;
    };
};


int main()
{
    MediatorA med1;
    Person *personA = new PersonA("person1");
    Person *personB = new PersonA("person2");
    Person *personC = new PersonA("person3");

    personA->SetMediator(&med1);
    personB->SetMediator(&med1);

    med1.AddPerson(personA);
    med1.AddPerson(personB);
    med1.AddPerson(personC);

    personA->SendMessage("你好");

    return 0;
}