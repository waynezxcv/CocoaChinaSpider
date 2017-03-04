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


#ifndef Dictionary_hpp
#define Dictionary_hpp

#include <stdio.h>

/******************** 字典 *******************/

/*
 ADT
 创建一个字典
 撤销一个字典
 确定字典是否为空
 确定字典数对个数
 返回关键字对应的值
 插入一个关键字对
 删除一个关键字对
 */


using namespace std;

namespace LWTL {
    
    template <typename K,typename E>
    
    class Dictionary {
    public:
        
        virtual ~Dictionary() {};
        
        virtual bool empty() const = 0;
        
        virtual int size() const = 0;
        
        virtual pair<const K,E>* find(const K&) const = 0;
        
        virtual void insert(const pair<const K,E>&) = 0;
        
        virtual void erase(const K&) = 0;
    };
    
}

#endif /* Dictionary_hpp */
