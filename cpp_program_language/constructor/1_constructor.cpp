	#include <iostream>
	using namespace std;
	
	class Coordinate
	{
	public:
		// 无参构造函数
		// 如果创建一个类你没有写任何构造函数，则系统自动生成默认的构造函数，函数为空，什么都不干
		// 如果自己显示定义了一个构造函数，则不会调用系统的构造函数
		Coordinate()
		{
			c_x = 0;
			c_y = 0;
      cout << "call default constructor" << endl;
		}     
	
		// 一般构造函数
		Coordinate(double x, double y):c_x(x), c_y(y){ cout << "call constructor with parameters" << endl; }   //列表初始化
		// 一般构造函数可以有多个，创建对象时根据传入的参数不同调用不同的构造函数
	
		Coordinate(const Coordinate& c)
		{
			// 复制对象c中的数据成员
			c_x = c.c_x;
			c_y = c.c_y;
      cout << "call copy constructor" << endl;
		}
	
		// 等号运算符重载
		Coordinate& operator= (const Coordinate& rhs)
		{
			// 首先检测等号右边的是否就是等号左边的对象本身，如果是，直接返回即可
			if(this == &rhs)
				return* this;
			// 复制等号右边的成员到左边的对象中
			this->c_x = rhs.c_x;
			this->c_y = rhs.c_y;
      cout << "call \'=\' operator" << endl;
			return* this;
		}
	
		double get_x()
		{
			return c_x;
		}
	
		double get_y()
		{
			return c_y;
		}
	
	private:
		double c_x;
		double c_y;
	};
	
	int main()
	{
		// 调用无参构造函数，c1 = 0，c2 = 0
		Coordinate c1, c2;
		// 调用一般构造函数，调用显示定义构造函数
		Coordinate c3(1.0, 2.0);
		c1 = c3;    //将c3的值赋值给c1，调用"="重载
		Coordinate c5(c2);
		Coordinate c4 = c2;    // 调用浅拷贝函数，参数为c2
		cout<<"c1 = "<<"("<<c1.get_x()<<", "<<c1.get_y()<<")"<<endl
			<<"c2 = "<<"("<<c2.get_x()<<", "<<c2.get_y()<<")"<<endl
			<<"c3 = "<<"("<<c3.get_x()<<", "<<c3.get_y()<<")"<<endl
			<<"c4 = "<<"("<<c4.get_x()<<", "<<c4.get_y()<<")"<<endl
			<<"c5 = "<<"("<<c5.get_x()<<", "<<c5.get_y()<<")"<<endl;
		return 0;
}
