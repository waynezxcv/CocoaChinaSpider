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





#ifndef BubbleSort_hpp
#define BubbleSort_hpp

#include <stdio.h>


namespace LWTL {
    
    
    template <typename T>
    void swap_1(T* a,T* b) {
        T tmp = *a;
        *a = *b;
        *b = tmp;
    }
    
    
    template <typename T>
    void swap_2(T* a,T* b) {
        *a = *a + *b;
        *b = *a - *b;
        *a = *a - *b;
        
    }
    
    template <typename T>
    void swap_3(T* a,T* b) {
        *a = *a ^ *b;
        *b = *a ^ *b;
        *a = *a ^ *b;
    }
    
    
    template <typename T>
    void BubbleSort(T* elements,int size) {
        for (int i = 0; i < size; i ++) {
            for (int j = size - 1; j > i; j --) {
                if (elements[i] > elements[j]) {
                    swap_3(&elements[i], &elements[j]);
                }
            }
        }
        
    }
    
}

#endif /* BubbleSort_hpp */
