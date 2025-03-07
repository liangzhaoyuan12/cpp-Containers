#include"container.h"
void map_example()
{
    map<int, string> m;
/**
 * @brief 插入元素的三种方式
 * 
 */
    m.insert(pair<int, string>(1, "one"));
    m.insert(pair<int, string>(2, "two"));

    m.insert(make_pair(3, "three"));

    m[4] = "four";

    cout<<"1的英文"<<m[1]<<endl;

    for(auto it: m)
    {
        cout<<it.first<<" "<<it.second<<endl;
    }
    cout<<endl;
    auto it=m.find(2);//it是指向键为2的元素的迭代器，指针
    cout<<it->first<<" "<<it->second<<endl;


}