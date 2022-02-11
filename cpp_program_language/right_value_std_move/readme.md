[https://zhuanlan.zhihu.com/p/335994370](https://zhuanlan.zhihu.com/p/335994370)

左值右值:  
1.左值可以取地址、位于等号左边；而右值没法取地址，位于等号右边。  
2.有地址的变量就是左值，没有地址的字面值、临时值就是右值。

左值引用: 能指向左值,不能指向右值
但是const左值引用: 能指向左值, 也能指向右值

右值引用: 能指向右值,不能指向左值
但是右值引用: 能指向std::move()过的左值

参考[1_right_reference_is_left_value.cpp](https://github.com/apollo007fd/cpp_programmer_notes/blob/main/cpp_program_language/right_value_std_move/1_right_reference_is_left_value.cpp):  
1.左值引用和右值引用本身都是左值 
2.对这3个左值取地址, 地址一样: 变量a, a的左值引用, a的右值引用

[右值引用既可能是左值，又可能是右值吗？](https://zhuanlan.zhihu.com/p/335994370#:~:text=%E7%9C%8B%E5%AE%8C%E5%90%8E%E4%BD%A0,%E5%B0%B1%E6%98%AF%E5%8F%B3%E5%80%BC%E3%80%82)  确实如此：右值引用既可以是左值也可以是右值，如果有名称则为左值，否则是右值。

[总结:](https://zhuanlan.zhihu.com/p/335994370#:~:text=%E4%BB%8E%E6%80%A7%E8%83%BD%E4%B8%8A,%E6%9C%89%E4%B8%80%E5%AE%9A%E5%B1%80%E9%99%90%E6%80%A7%E3%80%82)  
1. 从性能上讲, 左右值引用没有区别, 传参使用左右值都可以避免拷贝  
2. 右值引用可以直接指向右值, 也可以通过std::move指向左值; 而左值引用只能指向左值(const左值引用也能指向右值)  
3. 作为函数形参时, 右值比const左值引用更灵活, 可修改  

std::move()不一定会让变量失效, 是传入std::move()参数的函数,让变量失效 参考[这里](https://zhuanlan.zhihu.com/p/335994370#:~:text=class%20Array%20%7B%0Apublic%3A%0A%20%20%20%20......%0A%20%0A%20%20%20%20//%20%E4%BC%98%E9%9B%85%0A%20%20%20%20Array(Array%26%26%20temp_array)%20%7B%0A%20%20%20%20%20%20%20%20data_%20%3D%20temp_array.data_%3B%0A%20%20%20%20%20%20%20%20size_%20%3D%20temp_array.size_%3B%0A%20%20%20%20%20%20%20%20//%20%E4%B8%BA%E9%98%B2%E6%AD%A2temp_array%E6%9E%90%E6%9E%84%E6%97%B6delete%20data%EF%BC%8C%E6%8F%90%E5%89%8D%E7%BD%AE%E7%A9%BA%E5%85%B6data_%20%20%20%20%20%20%0A%20%20%20%20%20%20%20%20temp_array.data_%20%3D%20nullptr%3B%0A%20%20%20%20%7D%0A%20%20%20%20%20%0A%20%0Apublic%3A%0A%20%20%20%20int%20*data_%3B%0A%20%20%20%20int%20size_%3B%0A%7D%3B)
