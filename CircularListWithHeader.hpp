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


#ifndef CircularListWithHeader_hpp
#define CircularListWithHeader_hpp

#include <iostream>
#include "Chain.hpp"
#include "IllegalParameterValue.hpp"

#pragma mark - 带头节点的循环链表

namespace LWTL {
    
    template <typename T>
    class CircularListWithHeader {
    public:
        
        CircularListWithHeader() {
            headerNode = new ChainNode<T>();
            headerNode -> next = headerNode;
            ListSize = 0;
        }
        
        int size() const {
            return ListSize;
        }
        
        int indexOf(const T& theElement) const {
            headerNode -> element = theElement;
            ChainNode<T>* node = headerNode -> next;
            int index = 0;
            
            while (theElement != node -> element) {
                node = node -> next;
                index ++;
            }
            
            if (node == headerNode) {
                return -1;
            }
            return index;
        }
        
        void insert(int theIndex, const T& theElement) {
            checkIndex(theIndex);
            //寻找前驱节点
            ChainNode<T>* p = headerNode;
            for (int i = 0; i < theIndex; i++) {
                p = p->next;
            }
            p->next = new ChainNode<T>(theElement,headerNode);
            ListSize ++;
        }
        
        
    protected:
        void checkIndex(int theIndex) const {
            if (theIndex < 0 || theIndex > ListSize) {
                throw IllegalParameterValue("the index must between [0 , ListSize)");
            }

        }
        ChainNode<T>* headerNode;//头节点
        int ListSize;
    };
}

#endif /* CircularListWithHeader_hpp */
