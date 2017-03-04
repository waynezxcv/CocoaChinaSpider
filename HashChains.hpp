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





#ifndef HashChains_hpp
#define HashChains_hpp

#include <stdio.h>
#include "Hash.hpp"
#include "Dictionary.hpp"
#include "SortedChain.hpp"






//链式散列，每一个桶可以容纳无限个记录，没有溢出问题。
namespace LWTL {
    
    template<typename K,typename E>
    class HashChains : public Dictionary<K,E> {
    public:
        
        HashChains(const int& theDivisor) : divisor(theDivisor) {
            dSize = 0;
            
            new SortedChain<K, E> [divisor];
            table = new SortedChain<K, E> [divisor];
        }
        
        ~HashChains() {
            delete [] table;
        }
        
        
        pair<const K, E>* find (const K& theKey) const override {
            return table[hash(theKey) % divisor].find(theKey);//先根据theKey的哈希函数找到桶，再调用起始桶sortedChain的find();
        }
        
        
        void insert(const pair<const K,E>& thePair) override {
            int homeBucket = (int) hash(thePair.first) % divisor;
            int homeSize = table[homeBucket].size();
            table[homeBucket].insert(thePair);
            
            if (table[homeBucket].size() > homeSize) {
                dSize ++;
            }
        }
        
        void erase (const K& theKey) override {
            table[hash(theKey) % divisor].erase(theKey);
        }
        
        bool empty () const override {
            return dSize == 0;
        }
        
        int size () const override {
            return dSize;
        }
        
    private:
        SortedChain<K, E>* table;//哈希表，每一个桶是一个链表
        Hash<K> hash;//把类型K映射到一个非负整数
        int dSize;//字典中的数对个数
        int divisor;//散列函数 f(k) = k%D 的除数D,即桶的个数
    };
    
    
}

#endif /* HashChains_hpp */
