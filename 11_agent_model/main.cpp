/*
 * Created by 23984 on 2023/4/5.
 * 代理模式
 * 允许我们提供一个代理对象来控制对另一个对象的访问。代理模式使我们能够在不改变原始对象的情况下，增强其功能或控制其访问。
 */
#include <iostream>
using namespace std;

// 图片基类
class Image  
{  
public:  
    Image(string name): imageName_(name) {}  
    virtual ~Image() {}  
    virtual void Show() {}  
protected:  
    string imageName_;  
};  

// 大图片
class BigImage: public Image  
{  
public:  
    BigImage(string name):Image(name) {}  
    ~BigImage() {}  
    void Show() { cout<<"Show big image : "<<imageName_<<endl; }  
};  

// 大图片代理
class BigImageProxy: public Image  
{  
private:  
    BigImage *bigImage_;  // 大图片
public:  
    BigImageProxy(string name):Image(name),bigImage_(nullptr) {}  
    ~BigImageProxy() { delete bigImage_; }  
    void Show()   
    {  
        if(bigImage_ == nullptr)  
            bigImage_ = new BigImage(imageName_);  
        bigImage_->Show();  
    }  
};

int main() {
    Image *image = new BigImageProxy("proxy.jpg"); //代理  
    image->Show(); //需要时由代理负责打开  
    delete image;  

    return 0;
}
