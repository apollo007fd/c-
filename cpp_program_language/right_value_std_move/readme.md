[https://zhuanlan.zhihu.com/p/335994370](https://zhuanlan.zhihu.com/p/335994370)

左值右值:  
1.左值可以取地址、位于等号左边；而右值没法取地址，位于等号右边。  
2.有地址的变量就是左值，没有地址的字面值、临时值就是右值。

左值引用: 能指向左值,不能指向右值
但是const左值引用: 能指向左值, 也能指向右值

右值引用: 能指向右值,不能指向左值
但是右值引用: 能指向std::move()过的左值

左值引用和右值引用本身都是左值, 参考[1_right_reference_is_left_value.cpp](https://github.com/apollo007fd/cpp_programmer_notes/blob/main/cpp_program_language/right_value_std_move/1_right_reference_is_left_value.cpp)
