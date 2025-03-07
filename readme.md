该项目旨在运用cpp标准库内的所有容器，通过实践达到记忆的目的
以下内容全部来自ai

# C++标准库容器和算法详解
C++标准库（Standard Template Library，简称STL）是C++编程中非常重要的一部分，它提供了丰富的容器、算法和迭代器等组件，极大地提高了开发效率。本文将详细介绍C++标准库中常用的容器和算法的使用方法。

## 一、标准库容器

容器是用于存储和管理数据的对象，C++标准库提供了多种类型的容器，每种容器都有其特定的用途和性能特点。常用的容器包括序列容器、关联容器和无序关联容器。

### 1. 序列容器（Sequence Containers）

序列容器按元素的顺序存储数据，支持通过位置访问元素。

#### （1）`std::vector`

`std::vector`是一个动态数组，支持快速的随机访问，适合需要频繁访问元素的场景。

**基本用法：**
```cpp
#include <iostream>
#include <vector>

int main() {
    // 创建一个空的vector
    std::vector<int> vec;

    // 添加元素
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);

    // 访问元素
    std::cout << "第一个元素: " << vec[0] << std::endl; // 输出: 10
    std::cout << "第二个元素: " << vec.at(1) << std::endl; // 输出: 20

    // 遍历元素
    for (int num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // 获取大小
    std::cout << "大小: " << vec.size() << std::endl;

    return 0;
}
```

#### （2）`std::deque`

`std::deque`（双端队列）支持在两端高效地插入和删除元素，适合需要在两端进行频繁操作的场景。

**基本用法：**
```cpp
#include <iostream>
#include <deque>

int main() {
    std::deque<int> deq = {1, 2, 3};

    // 在头部添加元素
    deq.push_front(0);

    // 在尾部添加元素
    deq.push_back(4);

    // 访问元素
    std::cout << "第一个元素: " << deq.front() << std::endl; // 输出: 0
    std::cout << "最后一个元素: " << deq.back() << std::endl; // 输出: 4

    // 遍历元素
    for (int num : deq) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
```

#### （3）`std::list`

`std::list`是一个双向链表，支持在任何位置高效地插入和删除元素，但不支持随机访问。

**基本用法：**
```cpp
#include <iostream>
#include <list>

int main() {
    std::list<int> lst = {1, 2, 3};

    // 在链表中间插入元素
    auto it = lst.begin();
    ++it; // 指向第二个元素
    lst.insert(it, 10);

    // 删除元素
    lst.remove(2);

    // 遍历元素
    for (int num : lst) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
```

### 2. 关联容器（Associative Containers）

关联容器通过键（key）来存储和访问元素，内部通常使用平衡二叉树实现，支持有序存储和快速查找。

#### （1）`std::set`

`std::set`是一个有序集合，存储唯一的元素，不允许重复。

**基本用法：**
```cpp
#include <iostream>
#include <set>

int main() {
    std::set<int> s = {3, 1, 4, 1, 5};

    // 插入元素
    s.insert(2);

    // 尝试插入重复元素
    s.insert(3); // 不会插入

    // 遍历元素（自动排序）
    for (int num : s) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // 查找元素
    if (s.find(4) != s.end()) {
        std::cout << "找到元素4" << std::endl;
    }

    return 0;
}
```

#### （2）`std::map`

`std::map`是一个有序键值对容器，每个键对应一个唯一的值。

**基本用法：**
```cpp
#include <iostream>
#include <map>

int main() {
    std::map<std::string, int> m;

    // 插入键值对
    m["apple"] = 1;
    m["banana"] = 2;
    m.insert(std::make_pair("cherry", 3));

    // 访问元素
    std::cout << "apple的数量: " << m["apple"] << std::endl;

    // 遍历元素
    for (const auto& pair : m) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    // 查找元素
    auto it = m.find("banana");
    if (it != m.end()) {
        std::cout << "找到banana，数量: " << it->second << std::endl;
    }

    return 0;
}
```

### 3. 无序关联容器（Unordered Associative Containers）

无序关联容器使用哈希表实现，提供平均常数时间的查找性能，但不保证元素的顺序。

#### （1）`std::unordered_set`

`std::unordered_set`是一个无序且不重复的集合。

**基本用法：**
```cpp
#include <iostream>
#include <unordered_set>

int main() {
    std::unordered_set<int> uset = {3, 1, 4, 1, 5};

    // 插入元素
    uset.insert(2);

    // 遍历元素（无序）
    for (int num : uset) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
```

#### （2）`std::unordered_map`

`std::unordered_map`是一个无序的键值对容器。

**基本用法：**
```cpp
#include <iostream>
#include <unordered_map>

int main() {
    std::unordered_map<std::string, int> umap;

    // 插入键值对
    umap["apple"] = 1;
    umap["banana"] = 2;
    umap["cherry"] = 3;

    // 遍历元素（无序）
    for (const auto& pair : umap) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}
```

## 二、标准库算法

C++标准库提供了丰富的算法，用于对容器中的数据进行各种操作，如排序、查找、替换、遍历等。这些算法通常通过迭代器来访问容器中的元素。

### 1. 排序算法

#### `std::sort`

`std::sort`用于对序列进行排序，默认按升序排列。

**基本用法：**
```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec = {5, 2, 9, 1, 5, 6};

    // 排序
    std::sort(vec.begin(), vec.end());

    // 输出排序结果
    for (int num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // 自定义排序（降序）
    std::sort(vec.begin(), vec.end(), [](int a, int b) {
        return a > b;
    });

    for (int num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
```

### 2. 查找算法

#### `std::find`

`std::find`用于在序列中查找特定值的元素，返回指向该元素的迭代器，如果未找到则返回容器的`end()`。

**基本用法：**
```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};

    // 查找元素3
    auto it = std::find(vec.begin(), vec.end(), 3);
    if (it != vec.end()) {
        std::cout << "找到元素3，位置: " << std::distance(vec.begin(), it) << std::endl;
    } else {
        std::cout << "未找到元素3" << std::endl;
    }

    return 0;
}
```

#### `std::binary_search`

`std::binary_search`用于在已排序的序列中进行二分查找，返回布尔值表示是否存在。

**基本用法：**
```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    std::sort(vec.begin(), vec.end()); // 确保有序

    // 查找元素4
    if (std::binary_search(vec.begin(), vec.end(), 4)) {
        std::cout << "找到元素4" << std::endl;
    } else {
        std::cout << "未找到元素4" << std::endl;
    }

    return 0;
}
```

### 3. 替换和修改算法

#### `std::replace`

`std::replace`用于替换序列中所有等于特定值的元素。

**基本用法：**
```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec = {1, 2, 3, 2, 4, 2};

    // 将所有2替换为99
    std::replace(vec.begin(), vec.end(), 2, 99);

    for (int num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
```

### 4. 遍历和操作算法

#### `std::for_each`

`std::for_each`用于对序列中的每个元素执行指定的操作。

**基本用法：**
```cpp
#include <iostream>
#include <vector>
#include <algorithm>

void print(int n) {
    std::cout<< n << " ";
}

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};

    // 使用普通函数
    std::for_each(vec.begin(), vec.end(), print);
    std::cout << std::endl;

    // 使用Lambda表达式
    std::for_each(vec.begin(), vec.end(), [](int n) {
        std::cout << n * 2 << " ";
    });
    std::cout << std::endl;

    return 0;
}
```

### 5. 其他常用算法

- `std::accumulate`：计算序列中元素的总和或其他二元操作的结果。
- `std::transform`：对序列中的每个元素应用一个操作，并将结果存储到另一个序列中。
- `std::sort`、`std::stable_sort`：排序算法。
- `std::unique` 和 `std::erase`：移除相邻的重复元素。

**示例：使用`std::accumulate`计算总和**
```cpp
#include <iostream>
#include <vector>
#include <numeric>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};

    int sum = std::accumulate(vec.begin(), vec.end(), 0);
    std::cout << "总和: " << sum << std::endl;

    return 0;
}
```

## 三、迭代器

迭代器是连接容器和算法的桥梁，提供了一种统一的方式来访问容器中的元素。C++标准库定义了多种类型的迭代器，如输入迭代器、输出迭代器、前向迭代器、双向迭代器和随机访问迭代器。

**常用迭代器类型：**
- `begin()` 和 `end()`：指向容器的第一个元素和最后一个元素的下一个位置。
- `rbegin()` 和 `rend()`：指向容器的最后一个元素和第一个元素的前一个位置（反向迭代器）。

**示例：使用迭代器遍历`std::vector`**
```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};

    // 使用正向迭代器
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // 使用反向迭代器
    for (std::vector<int>::reverse_iterator rit = vec.rbegin(); rit != vec.rend(); ++rit) {
        std::cout << *rit << " ";
    }
    std::cout << std::endl;

    // 使用范围for循环（底层使用迭代器）
    for (int num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
```

## 四、总结

C++标准库通过丰富的容器和算法，提供了强大的数据存储和处理能力。掌握常用的容器（如`std::vector`、`std::map`等）和算法（如排序、查找等）的使用，可以显著提高编程效率和代码质量。此外，理解迭代器的概念和使用方法，有助于更好地结合容器和算法进行编程。

### 学习资源推荐

- **书籍**
  - 《C++ Primer》（Stanley B. Lippman等著）：全面介绍C++标准库的权威书籍。
  - 《Effective STL》（Scott Meyers著）：深入讲解如何高效使用STL的实用指南。
- **在线教程**
  - [C++ Reference](https://en.cppreference.com/w/)：详细的C++标准库参考文档。
  - [菜鸟教程 - C++ STL](https://www.runoob.com/cplusplus/cpp-stl-tutorial.html)：适合初学者的C++ STL教程。
- **实践项目**
  - 尝试实现一些常见的项目，如学生管理系统、图书管理系统等，应用所学的容器和算法知识。

通过系统学习和不断实践，您将能够熟练掌握C++标准库的使用，编写出高效、优雅的C++程序。