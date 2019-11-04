//
//  Rolodex.h
//  David_Lewellyn_Rolodex_Proj
//
//  Created by DAVID LEWELLYN on 10/10/19.
//  Copyright © 2019 DAVID LEWELLYN. All rights reserved.
//

#ifndef Rolodex_h
#define Rolodex_h
/*
 For the definitions of the Rolodex class we are going to reference the Card class interface
 since the Rolodex class will be manipulating the Card obejects.
 Since we want this to grow dynamically we are goin to implement the list STL rather use an array of objects. for sorting we are implementing the the <algorithms> STL rather then build the sort utility. Plus why build a function when it is already provided to us. The interator STL provides with means to access the memory address of the Card objects in manner that again we do not have to build ourselves. The cctype STL is implemented because rather then compare an exatc string value is is generally easier to convert it to either all upper or lower for validation.
 */
/*
 Access to Card.h also means we don't have to use additional includes for the Rolodex class
 */
#include "Card.h"
#include <algorithm>
#include <list>
#include <iterator>
#include <cctype>

class Rolodex{
    
public:
    void add(Card obj);
    Card remove();
    Card flip();
    Card getCurrentCard();
    void show(std::ostream& os);
    bool search(const std::string lName, const std::string fName);
    
    std::list<Card>::iterator nextRoloFunc(std::list<Card>::iterator value);
private:
    std::list<Card> rolodex;
    std::list<Card>::iterator rolodexmove;
protected:
    
};

#endif /* Rolodex_h */
