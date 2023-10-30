#include <iostream>

template <typename T>
class Traits
{
public:
    void name(int index);
};

template <typename T>
void Traits<T>::name(int index)
{
}
