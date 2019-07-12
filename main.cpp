//Permanent link: https://rextester.com/ZDT20874
//Microsoft (R) C/C++ Optimizing Compiler Version 19.00.23506 for x86
//Demo using standard library custom functions findall(), rotate()
//code by Twareintor (2017)

#include <iostream>
#include <algorithm>
#include <vector>

namespace vie
{

template <class T>
void rotate(T begin, T pivot, T beyond)
{
    std::reverse(begin, pivot);
    std::reverse(pivot, beyond);
    std::reverse(begin, beyond);
}

template <class T>
void rotate2(T begin, T pivot, T beyond)
{
    T reserve;
    int nMoved2End = pivot-begin;
    std::copy_n(begin, pivot-begin, reserve);
    int nMovedFw = beyond-pivot;
    std::copy_n(pivot, beyond-pivot, begin);
    std::copy_n(reserve, nMoved2End, begin+nMovedFw);

}
            
template <class T, class V>
const T& find(T begin, T end, const V& val)
{
    T it = begin;
    //... to be implemented
    return it;
}
   
template <class T, class V>
std::vector<T> findall(T begin, T end, const V& val)
{
    std::vector<T> Output;
    for(auto&& it=begin; it!=end; ++it)
    {
        if(val==*it) Output.push_back(it);
    }
    return Output;
}   

template <class T>
std::vector<T> findall(T begin, T end, const void* val)
{
    // compares the first character to find the match
    std::vector<T> Output;
    for(auto&& it=begin; it!=end; ++it)
    {
        char* szval = (char*)val;
        if(szval[0]==*it[0]) Output.push_back(it);
    }
    return Output;
}

}//namespace vie
    

int main()
{

    std::vector<int> values{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    vie::rotate(values.begin(), values.begin()+3, values.end()); // THIS WORKS
    // vie::rotate2(values.begin(), values.begin()+3, values.end()); // .. THIS NOT! 
    for(auto it = values.begin(); it!=values.end(); ++it)
    {
        std::cout<<*it;
    }
    std::cout<<std::endl;

    int vals[]{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    vie::rotate2(std::begin(vals), std::begin(vals)+3, std::end(vals));
    for(int i=0; i<10; i++)
    {
        std::cout<<vals[i];
    }
    std::cout<<std::endl;
    
    const char* Names[]{
                            "Alpha", "Bravo", "Charlie", "Delta", "Echo", "Foxtrot",
                            "Anton", "Bertha", "Caesar", "Dora", "Emil", "Friedrich",
                            "Anca", "Barbu", "Calin", "Dinu", "Ene", "Florea",
                       };
   
    std::vector<const char**> vOut2 = vie::findall(std::begin(Names), std::end(Names), (const void*)"Claudius");
    // std::vector<const char**> vOut2 = vie::findall(std::begin(Names), std::end(Names), "Claudius"); // this don't work!
    for(auto it=vOut2.begin(); it!=vOut2.end(); ++it)
    {
        std::cout<<**it;
        if(it!=vOut2.end()-1) std::cout<<", ";
    }
    std::cout<<std::endl;
    vie::rotate2(std::begin(Names), vOut2[1], std::end(Names));

    for(auto it=std::begin(Names); it!=std::end(Names); ++it)
    {
        std::cout<<*it;
        if(it!=std::end(Names)-1) std::cout<<", ";
    }

    std::cout<<std::endl;
    std::cout << "Game Over!\n";
}


