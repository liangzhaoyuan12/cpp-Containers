#include"container.h"
/**
 * @brief list可以在任何位置插入和删除元素
 * 不支持随机访问
 * 双向链表
 */
void list_example()
{
    list<int> l1;
    l1.push_back(1);
    l1.push_back(2);
    l1.push_back(3);
    l1.push_back(4);
    l1.push_back(5);
    l1.push_back(6);
    l1.push_back(7);
    l1.push_back(8);
    l1.push_back(9);
    l1.push_back(10);
    l1.push_back(11);
    l1.push_back(12);
    l1.push_back(13);
    l1.push_back(14);
    l1.push_back(15);

    auto it = l1.begin();
    /**
     * @brief it是list的迭代器，可以用来访问list中的元素
     * 可以通过it++来移动迭代器
     */
    it++;//指向第二个元素
    l1.insert(it, 100);
    l1.remove(3);//删除值为3的元素
    it++;//指向第三个元素
    l1.erase(it);//删除迭代器指向的元素
    //遍历  
    for(auto i : l1)
    {
        cout << i << " ";
    }
    cout<<endl;
}