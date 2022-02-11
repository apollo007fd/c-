#include <iostream>
using namespace std;

class Test
{
public:
	// 构造函数
	Test(int a):t_a(a){
	cout<<"creat: "<<t_a<<endl;
	}

	// 拷贝构造函数
	Test(const Test& T)
	{
		t_a = T.t_a;
		cout<<"copy"<<endl;
	}

	// 析构函数
	~Test()
	{
		cout<<"delete: "<<t_a<<endl;
	}

	// 显示函数
	void show()
	{
		cout<<t_a<<endl; 
	}

private:
	int t_a;
};

// 全局函数，传入的是对象, 调用构造函数
void fun(Test C)
{
	cout<<"test"<<endl;
  // 函数退出之前, 对象析构
}

int main()
{
	Test t(1);
	// 函数中传入对象
	fun(t);
  // main函数退出之前, 对象析构
	return 0;
}
