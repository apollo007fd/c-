#include <iostream>
#include <assert.h>    
using namespace std;

class Test
{
public:
	Test(){
		p = new int(10);
	}

	~Test(){
		assert(p != NULL);     // assert()作用是如果他的条件返回错误，则终止程序执行 
		delete p;
	}
/*默认的拷贝构造函数相当于:
  Test(const Test& t){
    this->x = t.x;
    this->y = t.y;
    this->p = t.p; // 浅拷贝, 指向同一块内存
  }*/
private:
	int x;
	int y;
	int* p;
};

int main()
{
	Test t1;
  /*浅拷贝, p指向的内存会析构2次, 导致程序崩溃*/
	Test t2(t1);    // 调用默认拷贝构造函数
	return 0;
}
