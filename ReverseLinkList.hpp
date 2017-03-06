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

#ifndef ReverseLinkList_hpp
#define ReverseLinkList_hpp

#include <stdio.h>





namespace LWTL {
    
    template <typename T>
    struct LinkNode {
        T element;
        LinkNode* next;
        LinkNode(const T& theElement) : element(theElement) {
            next = NULL;
        }
    };
    
    
    //反转一个单链表
    template <typename T>
    LinkNode<T>* reverseLinkList (LinkNode<T>* theList) {
        
        if (theList == NULL) {
            return NULL;
        }
        
        LinkNode<T>* currentNode = theList;
        LinkNode<T>* reverseLink = new LinkNode<T> (currentNode -> element);
        
        while (currentNode -> next != NULL) {
            currentNode = currentNode -> next;
            LinkNode<T>* tmp = new LinkNode<T> (currentNode -> element);
            tmp -> next = reverseLink;
            reverseLink = tmp;
        }
        
        return reverseLink;
        
    };
    
    
    
}

#endif /* ReverseLinkList_hpp */
