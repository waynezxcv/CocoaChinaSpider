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





#ifndef Hash_hpp
#define Hash_hpp

#include <stdio.h>


using namespace std;

namespace LWTL {
    
    
    template <typename K>
    class Hash;
    
    
    
    //模板特例化,针对某种特定数据类型编写一个模板
    template<>
    class Hash<string> {
    public:
        //重载函数调用运算符
        size_t operator () (const string& theKey) const {
            //将字符串转化为一个非负整数
            unsigned long hashValue = 0;
            int length = (int)theKey.length();
            
            for (int i = 0; i < length; i ++) {
                hashValue = 5 * hashValue + theKey.at(i);
            }
            return size_t(hashValue);
        }
    };
    
    
    
    template<>
    class Hash<int> {
    public:
        size_t operator () (const int& theKey) const {
            return size_t(theKey);
        }
    };
    
    
    
    template<>
    class Hash<long> {
    public:
        size_t operator () (const long& theKey) const {
            return size_t(theKey);
        }
    };
    
    
}

#endif /* Hash_hpp */
