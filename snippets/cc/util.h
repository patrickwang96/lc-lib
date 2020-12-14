// Created by Ruochen Wang (ruochwang@gmail.com)
#ifndef UTIL_H
#define UTIL_H


#define likely(x)      __builtin_expect(!!(x), 1)
#define unlikely(x)    __builtin_expect(!!(x), 0)

// forceinline
#ifdef _MSC_VER
    #define forceinline __forceinline
#elif defined(__GNUC__)
    #define forceinline inline __attribute__((__always_inline__))
#elif defined(__CLANG__)
    #if __has_attribute(__always_inline__)
        #define forceinline inline __attribute__((__always_inline__))
    #else
        #define forceinline inline
    #endif
#else
    #define forceinline inline
#endif

#define DISALLOW_COPY_AND_ASSIGN(class_name) class_name(const class_name&) = delete;\
                                 class_name& operator=(const class_name&) = delete

#endif // UTIL_H
