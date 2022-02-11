[https://zhuanlan.zhihu.com/p/335994370](https://zhuanlan.zhihu.com/p/335994370)

左值右值:  
1.左值可以取地址、位于等号左边；而右值没法取地址，位于等号右边。  
2.有地址的变量就是左值，没有地址的字面值、临时值就是右值。

左值引用: 能指向左值,不能指向右值
但是const左值引用: 能指向左值, 也能指向右值

右值引用: 能指向右值,不能指向左值
但是右值引用: 能指向std::move()过的左值

左值引用和右值引用本身都是左值, 参考[1_right_reference_is_left_value.cpp](https://github.com/apollo007fd/cpp_programmer_notes/blob/main/cpp_program_language/right_value_std_move/1_right_reference_is_left_value.cpp)

[右值引用既可能是左值，又可能是右值吗？](https://zhuanlan.zhihu.com/p/335994370#:~:text=%E7%9C%8B%E5%AE%8C%E5%90%8E%E4%BD%A0,%E5%B0%B1%E6%98%AF%E5%8F%B3%E5%80%BC%E3%80%82)  确实如此：右值引用既可以是左值也可以是右值，如果有名称则为左值，否则是右值。
