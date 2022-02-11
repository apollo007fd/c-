#include <iostream>
#include <assert.h>    
using namespace std;

class Test
{
public:
	Test(){
		x = 0;
		y = 0;
		p = new int(10);
	}

	Test(const Test& t)
	{
		x = t.x;
		y = t.y;
		p = new int(10);
		*p = *(t.p);
	}

	~Test(){
		assert(p != NULL);     // assert()作用是如果他的条件返回错误，则终止程序执行 
		delete p;
	}

	int get_x(){return x;}
	int get_y(){return y;}
private:
	int x;
	int y;
	int* p;
};

int main()
{
	Test t1;
	Test t2(t1);    // 调用默认拷贝构造函数
	cout<<"("<<t1.get_x()<<", "<<t1.get_y()<<")"<<endl
		<<"("<<t2.get_x()<<", "<<t2.get_y()<<")"<<endl;
	return 0;
}
