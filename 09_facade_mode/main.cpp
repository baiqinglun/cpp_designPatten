/*
 * Created by 23984 on 2023/4/5.
 * 外观模式
 * 当一个系统很复杂时，系统提供给客户的是一个简单的对外接口，而把里面复杂的结构都封装了起来。
 */

#include <iostream>
using namespace std;

class Model{
public:
  void createModel(){
    cout << "建模" << endl;
  }
};

class Mesh{
public:
  void createMesh(){
    cout << "划分网格" << endl;
  }
};

class Caculate{
public:
  void numericalCalculation(){
    cout << "数值计算" << endl;
  }
};

class PostProcess{
public:
  void pprocess(){
    cout << "后处理" << endl;
  }
};

class Simulation{
public:
  Simulation():model_(new Model()),mesh_(new Mesh()),cal_(new Caculate()),post_(new PostProcess()){};
  void simulate(){
    model_->createModel();
    mesh_->createMesh();
    cal_->numericalCalculation();
    post_->pprocess();
  }
private:
  Model *model_;
  Mesh *mesh_;
  Caculate *cal_;
  PostProcess *post_;
};

int main()
{
  Simulation s;
  s.simulate();

  return 0;
}