#include"container.h"
void vector_example()
{
    vector<int> v1;
    /**
     * 添加元素
     */
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);
    v1.push_back(5);
    v1.push_back(6);
    v1.push_back(7);
    v1.push_back(8);
    v1.push_back(9);

    /**
     * @brief 单独取出一个元素
     */
    cout<<"1:"<<v1[0]<<endl;
    /**
     * @brief Construct a new for object
     * 遍历
     * @param num:v1 
     */
    for(auto num:v1)
    {
        cout<<num<<" ";
    }
    cout<<endl;

    cout<<"size:"<<v1.size()<<endl;
}