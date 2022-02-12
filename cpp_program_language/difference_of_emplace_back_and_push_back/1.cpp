#include <vector>  
#include <string>  
#include <iostream>  

struct President  
{  
    std::string name;  
    std::string country;  
    int year;  

    President(std::string p_name, std::string p_country, int p_year)  
        : name(std::move(p_name)), country(std::move(p_country)), year(p_year)  
    {  
        std::cout << "I am being constructed.\n";  
    }
    President(const President& other)
        : name(std::move(other.name)), country(std::move(other.country)), year(other.year)
    {
        std::cout << "I am being copy constructed.\n";
    }
    President(President&& other)  
        : name(std::move(other.name)), country(std::move(other.country)), year(other.year)  
    {  
        std::cout << "I am being moved.\n";  
    }  
    President& operator=(const President& other);  
};  

int main()  
{  
    std::vector<President> elections;
    elections.reserve(32);
    std::cout << "0.emplace_back:\n";  
    elections.emplace_back("Nelson Mandela", "South Africa", 1994); //没有类的创建  

    std::cout << "\n1.emplace_back:\n";
    President temp1("Nelson Mandela", "South Africa", 1994);
    elections.emplace_back(std::move(temp1));

    std::cout << "\n2.emplace_back:\n";  
    elections.emplace_back(President("Nelson Mandela", "South Africa", 1994)); //有类的创建, 且会调用移动构造函数  

    std::cout << "\n3.emplace_back:\n";
    auto temp3 = President("Nelson Mandela", "South Africa", 1994);
    elections.emplace_back(temp3); //会调用复制构造函数, 可能是因为入参temp3是左值的原因?

    std::cout << "\n4.emplace_back:\n";
    President temp4 = President("Nelson Mandela", "South Africa", 1994);
    elections.emplace_back(std::move(temp4)); //会调用移动构造函数

    std::vector<President> reElections;
    std::cout << "\n5.push_back:\n";
    reElections.push_back(President("Franklin Delano Roosevelt", "the USA", 1936)); // 注释掉移动构造函数, 如果有定义拷贝构造函数, push_back则会优先调用拷贝构造函数 

    std::cout << "\n6.push_back:\n";
    auto temp6 = President("Franklin Delano Roosevelt", "the USA", 1936);
    reElections.push_back(temp6); 

    std::cout << "\n7:\n";
    auto temp7 = President("Franklin Delano Roosevelt", "the USA", 1936);

    std::cout << "\n8.push_back:\n";
    auto&& temp8 = std::move(temp7);
    reElections.push_back(temp8); 

    std::cout << "\n9.push_back:\n";
    auto&& temp9 = std::move(temp7);
    reElections.push_back(std::move(temp9)); 

    std::cout << "\nContents:\n";  
    for (President const& president: elections) {  
       std::cout << president.name << " was elected president of "  
            << president.country << " in " << president.year << ".\n";  
    }  
    for (President const& president: reElections) {  
        std::cout << president.name << " was re-elected president of "  
            << president.country << " in " << president.year << ".\n";  
    }

}

