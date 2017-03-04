//
//  HashTable.hpp
//  DataStructures
//
//  Created by 刘微 on 2017/3/4.
//  Copyright © 2017年 刘微. All rights reserved.
//

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
