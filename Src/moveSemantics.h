//
// Created by Manoloon on 08/03/2022.
//

#ifndef LEARNINGBASES_MOVESEMANTICS_H
#define LEARNINGBASES_MOVESEMANTICS_H
#include <iostream>
#include <string>
#include <cstring>

class String{
public:
    String() = default;

    String(const char *string)
    {
        std::cout << "Create!\n";
        m_size = std::strlen(string);
        m_data = new char[m_size];
        memcpy(m_data, string, m_size);
    }

    // Copy constructor
    String(const String& other):m_size(other.m_size)
    {
        std::cout << "Copied!\n";
        m_data = new char[m_size];
        memcpy(m_data, m_data, m_size);
    }
    // move constructor
    String(String&& other) noexcept
    {
     m_data=other.m_data;
     m_size=other.m_size;
     std::cout << "Moved!\n";

     other.m_data = nullptr;
     other.m_size = 0;
    }
    // having move semantics we dont need the destructor.
    ~String()
    {
        std::cout << "Destroyed!\n";
        delete m_data;
    }

    void Print() const
    {
        for(int i=0;i<m_size;i++)
        {
            printf("%c",m_data[i]);
        }
        printf("\n");
    }
private:
    char *m_data;
    uint32_t m_size;
};

class Entity{
public:
    Entity()=default;
    explicit Entity(const String& name):m_name(name){
        std::cout << "Construct Entity\n";
        m_name.Print();
    }
    // using the move constructor of String.
    Entity(String&& name): m_name(std::move(name)){
        std::cout << "move Construct Entity\n";
        m_name.Print();
    };
private:
    String m_name;
};
#endif //LEARNINGBASES_MOVESEMANTICS_H
