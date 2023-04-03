/*
 * Created by 23984 on 2023/4/2.
 * 策略模式
 * 策略模式是指定义一系列的算法，把它们一个个封装起来，并且使它们可相互替换。
 * */

#include "iostream"

class ReplaceAlgorithm{
public:
    virtual void replace() = 0;
};

class FIFO_ReplaceAlgorithm : public ReplaceAlgorithm{
public:
    void replace() override{
        std::cout << "FIFO_ReplaceAlgorithm被调用" << std::endl;
    }
};
class LRU_ReplaceAlgorithm : public ReplaceAlgorithm{
public:
    void replace() override{
        std::cout << "LRU_ReplaceAlgorithm被调用" << std::endl;
    }
};
class Random_ReplaceAlgorithm : public ReplaceAlgorithm{
public:
    void replace() override{
        std::cout << "Random_ReplaceAlgorithm被调用" << std::endl;
    }
};

// 方法一
//class Cache{
//private:
//    ReplaceAlgorithm *m_ra;
//public:
//    Cache(ReplaceAlgorithm *ra):m_ra(ra){};
//    ~Cache(){
//        delete m_ra;
//    };
//    void replaceAlgorithm(){
//        m_ra->replace();
//    }
//};

// 方法二
//enum ALGORITHM_TYPE{
//    FIFO,
//    LRU,
//    RANDOM
//};
//class Cache{
//private:
//    ReplaceAlgorithm *m_ra;
//public:
//    Cache(enum ALGORITHM_TYPE type){
//        switch (type) {
//            case FIFO:
//                m_ra = new FIFO_ReplaceAlgorithm;
//                break;
//            case LRU:
//                m_ra = new LRU_ReplaceAlgorithm;
//                break;
//            case RANDOM:
//                m_ra = new Random_ReplaceAlgorithm;
//                break;
//            default:
//                m_ra = nullptr;
//        }
//    };
//    ~Cache(){
//        delete m_ra;
//    };
//    void replaceAlgorithm(){
//        m_ra->replace();
//    }
//};

// 方法三
template <class RA>
class Cache{
private:
    RA m_ra;
public:
    Cache(){};
    ~Cache(){};
    void replaceAlgorithm(){
        m_ra.replace();
    }
};

int main(){
    // 方法一
//    Cache cache(new FIFO_ReplaceAlgorithm());
//    Cache cache1(new LRU_ReplaceAlgorithm());
//    Cache cache2(new Random_ReplaceAlgorithm());
//    cache.replaceAlgorithm();
//    cache1.replaceAlgorithm();
//    cache2.replaceAlgorithm();
// 输出
// FIFO_ReplaceAlgorithm被调用
// LRU_ReplaceAlgorithm被调用
// Random_ReplaceAlgorithm被调用

//     方法二
//    Cache cache(ALGORITHM_TYPE::FIFO);
//    cache.replaceAlgorithm();
//    Cache cache1(ALGORITHM_TYPE::LRU);
//    cache1.replaceAlgorithm();
//    Cache cache2(ALGORITHM_TYPE::RANDOM);
//    cache2.replaceAlgorithm();
// 输出
// FIFO_ReplaceAlgorithm被调用
// LRU_ReplaceAlgorithm被调用
// Random_ReplaceAlgorithm被调用

    // 方法三
    Cache<FIFO_ReplaceAlgorithm> cache;
    cache.replaceAlgorithm();
    return 0;
}

// 输出
