//
//  PairNode.hpp
//  DataStructures
//
//  Created by 刘微 on 2017/3/4.
//  Copyright © 2017年 刘微. All rights reserved.
//

#ifndef PairNode_hpp
#define PairNode_hpp

#include <stdio.h>


template <typename K,typename E>
class PairNode {
    
public:
    typedef pair<const K,E> PairType;
    
    
    PairType element;
    PairNode<K,E>* next;
    
    PairNode(const PairType& thePair) : element(thePair) {};
    PairNode(const PairType& thePair,PairNode<K,E>* theNext) : element(thePair) {
        next = theNext;
    };
};


#endif /* PairNode_hpp */
