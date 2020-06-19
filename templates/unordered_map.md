# unordered_map

## 定义

```cpp
unordered_map<string, string> dict;
```

## 查找
```cpp
if (dict.count("hello") == 0) 
    std::cout << "dict doesn't contain this string"<< std::endl;
```

## 持key索value

```cpp
std::cout << "value is " << dict["hello"];
```
