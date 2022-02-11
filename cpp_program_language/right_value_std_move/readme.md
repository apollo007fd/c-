[https://zhuanlan.zhihu.com/p/335994370](https://zhuanlan.zhihu.com/p/335994370)

左值右值:  
1.左值可以取地址、位于等号左边；而右值没法取地址，位于等号右边。  
2.有地址的变量就是左值，没有地址的字面值、临时值就是右值。

左值引用: 能指向左值,不能指向右值
但是const左值引用: 能指向左值, 也能指向右值

右值引用: 能指向右值,不能指向左值
但是右值引用: 能指向std::move()过的左值

左值引用和右值引用本身都是左值, 参考[1_right_reference_is_left_value.cpp](https://github.com/apollo007fd/cpp_programmer_notes/blob/main/cpp_program_language/right_value_std_move/1_right_reference_is_left_value.cpp)

[右值引用既可能是左值，又可能是右值吗？](https://zhuanlan.zhihu.com/p/335994370#:~:text=%E7%9C%8B%E5%AE%8C%E5%90%8E%E4%BD%A0%E5%8F%AF%E8%83%BD%E6%9C%89%E4%B8%AA%E9%97%AE%E9%A2%98%EF%BC%8Cstd%3A%3Amove%E4%BC%9A%E8%BF%94%E5%9B%9E%E4%B8%80%E4%B8%AA%E5%8F%B3%E5%80%BC%E5%BC%95%E7%94%A8int%20%26%26%EF%BC%8C%E5%AE%83%E6%98%AF%E5%B7%A6%E5%80%BC%E8%BF%98%E6%98%AF%E5%8F%B3%E5%80%BC%E5%91%A2%EF%BC%9F%20%E4%BB%8E%E8%A1%A8%E8%BE%BE%E5%BC%8Fint%20%26%26ref%20%3D%20std%3A%3Amove(a)%E6%9D%A5%E7%9C%8B%EF%BC%8C%E5%8F%B3%E5%80%BC%E5%BC%95%E7%94%A8ref%E6%8C%87%E5%90%91%E7%9A%84%E5%BF%85%E9%A1%BB%E6%98%AF%E5%8F%B3%E5%80%BC%EF%BC%8C%E6%89%80%E4%BB%A5move%E8%BF%94%E5%9B%9E%E7%9A%84int%20%26%26%E6%98%AF%E4%B8%AA%E5%8F%B3%E5%80%BC%E3%80%82%E6%89%80%E4%BB%A5%E5%8F%B3%E5%80%BC%E5%BC%95%E7%94%A8%E6%97%A2%E5%8F%AF%E8%83%BD%E6%98%AF%E5%B7%A6%E5%80%BC%EF%BC%8C%E5%8F%88%E5%8F%AF%E8%83%BD%E6%98%AF%E5%8F%B3%E5%80%BC%E5%90%97%EF%BC%9F%20%E7%A1%AE%E5%AE%9E%E5%A6%82%E6%AD%A4%EF%BC%9A%E5%8F%B3%E5%80%BC%E5%BC%95%E7%94%A8%E6%97%A2%E5%8F%AF%E4%BB%A5%E6%98%AF%E5%B7%A6%E5%80%BC%E4%B9%9F%E5%8F%AF%E4%BB%A5%E6%98%AF%E5%8F%B3%E5%80%BC%EF%BC%8C%E5%A6%82%E6%9E%9C%E6%9C%89%E5%90%8D%E7%A7%B0%E5%88%99%E4%B8%BA%E5%B7%A6%E5%80%BC%EF%BC%8C%E5%90%A6%E5%88%99%E6%98%AF%E5%8F%B3%E5%80%BC%E3%80%82)  确实如此：右值引用既可以是左值也可以是右值，如果有名称则为左值，否则是右值。
