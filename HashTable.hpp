/*
 Copyright (c) 2017 waynezxcv <liuweiself@126.com>
 
 https://github.com/waynezxcv/Playground
 
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 */

#ifndef HashTable_hpp
#define HashTable_hpp

#include <stdio.h>
#include "Dictionary.hpp"


namespace LWTL {
    
    //哈希表的每一个位置叫一个桶bucket
    //对关键字为k的数对，f（k）是起始桶。
    //桶的数量等于散列表的长度或大小。
    //因为散列函数可以将多个关键字映射到同一个桶，所以桶要能容纳多个数对。
    
    //除法散列函数: f(k) = k % D
    
    
    
    //用散列实现的字典
    template <typename K,typename E>
    class HashTable : public Dictionary <K,E> {
        
    public:
        
        
    private:
        
        
    };
    
    
}

#endif /* HashTable_hpp */
