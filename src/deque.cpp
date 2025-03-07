#include"container.h"
/**
 * @brief deque可以在头部和尾部添加元素
 * 
 */
void deque_example()
{
    deque<int> d;
    /**
     * @brief 尾部添加元素
     * 
     */
    d.push_back(1);
    d.push_back(2);
    d.push_back(3);
    /**
     * @brief 头部添加元素
     * 
     */
    d.push_front(0);
    d.push_front(-1);
    d.push_front(-2);
    d.push_front(-3);
    d.push_front(-4);
    d.push_front(-5);
    d.push_front(-6);
    
    cout<<"deque size: "<<d.size()<<endl;
    cout<<"第一个元素："<<d.front()<<endl;
    cout<<"最后一个元素："<<d.back()<<endl;

    /**
     * @brief 遍历
     * 
     * @param i:d 
     */
    for(auto i:d)
    {
        cout<<i<<" ";
    }
    cout<<endl;
}