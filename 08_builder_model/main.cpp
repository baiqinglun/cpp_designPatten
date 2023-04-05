/*
 * Created by 23984 on 2023/4/5.
 * 建造者模式
 * 将一个复杂对象的构建过程分离出来，使其可以独立于主要的业务逻辑而变化
 */

#include <iostream>
using namespace std;

// 要创建的复杂对象，通常由多个部件组成。 
class Product {
public:
    void set_part_a(const std::string& part_a) {
        part_a_ = part_a;
    }
    void set_part_b(const std::string& part_b) {
        part_b_ = part_b;
    }
    void set_part_c(const std::string& part_c) {
        part_c_ = part_c;
    }
    void print_parts() const {
        std::cout << "Part A: " << part_a_ << "\n";
        std::cout << "Part B: " << part_b_ << "\n";
        std::cout << "Part C: " << part_c_ << "\n";
    }
private:
    std::string part_a_;
    std::string part_b_;
    std::string part_c_;
};

// 负责定义产品的构建过程，以及如何组装各个部件。
class Builder {
public:
    virtual void build_part_a() = 0;
    virtual void build_part_b() = 0;
    virtual void build_part_c() = 0;
    virtual Product* get_product() = 0;
};

// 负责实现 Builder 接口，以定义产品的各个部件的具体构建方式。
class ConcreteBuilder : public Builder {
public:
    ConcreteBuilder() : product_(new Product()) {}
    virtual void build_part_a() {
        product_->set_part_a("Part A");
    }
    virtual void build_part_b() {
        product_->set_part_b("Part B");
    }
    virtual void build_part_c() {
        product_->set_part_c("Part C");
    }
    virtual Product* get_product() {
        return product_;
    }
private:
    Product* product_;
};

// 负责调用建造者来构建产品，并控制建造的流程。
class Director {
public:
    Director(Builder* builder) : builder_(builder) {}
    void construct() {
        builder_->build_part_a();
        builder_->build_part_b();
        builder_->build_part_c();
    }
private:
    Builder* builder_;
};

int main() {
    ConcreteBuilder builder1;
    Director director(&builder1);
    director.construct();
    Product* product = builder1.get_product();
    product->print_parts();
    delete product;
    return 0;
}