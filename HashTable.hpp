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
#include "Hash.hpp"
#include "IllegalParameterValue.hpp"




namespace LWTL {
    
    
    //哈希表的每一个位置叫一个桶bucket
    //对关键字为k的数对，f（k）是起始桶。
    //桶的数量等于散列表的长度或大小。
    //因为散列函数可以将多个关键字映射到同一个桶，所以桶要能容纳多个数对。
    
    //除法散列函数: f(k) = k % D
    
    //用散列实现的字典
    template <typename K,typename E>
    class HashTable : public Dictionary<K, E> {
        
    public:
        
        //构造函数
        HashTable(int theDivisor) {
            divisor = theDivisor;
            dSize = 0;
            
            //分配和初始化哈希表数组
            table = new pair<const K, E>* [divisor];
            for (int i = 0; i < divisor; i ++) {
                
                table[i] = NULL;
            }
        }
        
        
        ~HashTable () {
            
            for (int i = 0; i < divisor; i ++) {
                if (table[i] != NULL) {
                    delete table[i];
                }
            }
            delete [] table;
        }
        
        //搜索一个关键字为theKey的数对，如果匹配的数对存在返回它的地址，否则如果散列不满，则返回theKey可以插入的位置
        int search(const K& theKey) const {
            int i = (int)hash(theKey) % divisor;
            int j = i;
            
            do {
                if (table[i] == NULL || table[j] -> first == theKey) {
                    return j;
                }
                j = (j + 1) % divisor;
            }while (j != i);
            return j;
        }
        
        
        
        pair<const K, E>* find (const K& theKey) const override {
            //搜索哈希表
            int b = search(theKey);
            
            //判断table[b]是否是匹配数对
            if (table[b] == NULL || table[b] -> first != theKey) {
                return NULL;
            }
            return table[b];
        }
        
        
        void insert (const pair<const K,E>& thePair) override {
            //把数对插入字典，如果存在关键字相同的数对，则覆盖
            int b = search(thePair.first);//搜索哈希表
            
            //如果数对不存在
            if (table[b] == NULL) {
                //插入这个数对
                table[b] = new pair<const K, E>(thePair);
                dSize ++;
            } else {
                //数对存在
                
                //检查是否重复
                if (table[b] -> first == thePair.first) {
                    table[b] -> second = thePair.second;
                }else {
                    //溢出
                    throw IllegalParameterValue("the hash table is overflow");
                }
            }
        }
        
        void erase (const K& theKey) override {
            int b = search(theKey);//搜索哈希表
            if (table[b] != NULL) {
                if (table[b] -> first == theKey) {
                    delete table[b];
                    dSize --;
                }
            } else {
                throw IllegalParameterValue("the pair is not exsit");
            }
        }
        
        
        bool empty () const override {
            return dSize == 0;
        }
        
        int size () const override {
            return dSize;
        }
        
        
        
    private:
        pair<const K, E>** table;//哈希表
        Hash<K> hash;//把类型K映射到一个非负整数
        int dSize;//字典中的数对个数
        int divisor;//散列函数 f(k) = k%D 的除数D,即桶的个数
    };
    
    
}

#endif /* HashTable_hpp */
