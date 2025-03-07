#include"container.h"
 /**
     * @brief 
     * `std::set`是一个有序集合，存储唯一的元素，不允许重复。
     * 
     */
void set_example()
{
   set<int> s;
   s.insert(1);
   s.insert(2);
   s.insert(3);
   try
   {
    s.insert(1);
   }
   catch(const std::exception& e)
   {
    std::cerr << e.what() << '\n';
    cout<<"set不允许重复元素"<<endl;
   }
   for(auto i:s)
   {
       cout<<i<<endl;
   }
   
}