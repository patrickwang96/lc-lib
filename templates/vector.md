# vector 用法

## 初始化
```cpp
std::vector<int> v1(5, 0);
std::vector<int> v2;
std::vector<int> v3 = {1,2,3};
std::vector<std::vector<int>> v4(M, vector<int>(N, default_value));
```
以上提供了四种初始化一个vector的方式，其中`v1`的长度为5，所有值初始化为0。`v2`为空vector，`v3` 为拷贝赋值。`v4`为一个M*N的二维数组，初始值为`default_value`。

## 访问

迭代器在leetcode里面用的不多，暂且不与介绍。

```cpp
for (int i = 0; i < v1.size(); i++) {
    v1[i] = i;
}

for (int i: v1) {
    std::cout << i << std::endl;
}

std::cout << v1.front();
std::cout << v2.back();

```

## 添加/删除
emplace_back函数会调用T的构造函数，并且将新构造的对象置于vector末尾。

```cpp
v1.push_back(1);
v1.pop_back();

std::vector<TreeNode*> vec;
vec.emplace_back(0);
```

## 标准库函数的使用

```cpp
std::sort(v1.begin(), v1.end());
std::sort(v1.rbegin(), v1.rend()); // sort in reverse order
std::stable_sort(v1.begin(), v1.end());

std::accumulate(v1.begin(), v1.end(), 0); // sum all element

for_each(v1.begin(), v1.end(), [](int &a) {a++;});

std::lower_bound(v1.begin(), v1.end(), 3); // binary search
std::equal_range(v1.begin(), v1.end(), 3); // binary search for upper and lower bound

std::count(v1.begin(), v1.end(), 3); 
std::count_if(v1.begin(), v1.end(), [](int i) {return i % 3 == 0;});

std::max_element(v1.begin(), v1.end());
std::min_element(v1.begin(), v1.end());

std::reverse(v1.begin(), v1.end());
```

