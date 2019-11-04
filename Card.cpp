//
//  Program:Card.cpp
//  Project:David_Lewellyn_Rolodex_Proj
//
//  Created by DAVID LEWELLYN on 10/08/19.
//  Copyright © 2019 DAVID LEWELLYN. All rights reserved.
//
/*
Summary: The Card.cpp simply contains tha set and get methods for the Card class object. the manipulation and movement of these object is handed through the lists of objects handled in the Rolodex Class.


*/
#include "Card.h"

/*
 Here we actually define the meat and potatoes of each method in the Card class
 */
/*
 With a default constructor we want to ste all the vaules to a NULL terminated string
 */
Card::Card(){
    this->lName = '\0';
    this->fName = '\0';
    this->occupation = '\0';
    this->sAddress = '\0';
    this->pNumber = '\0';
}

Card::Card(std::string first, std::string last, std::string occup, std::string address, std::string phone){
    
    this->fName=first;
    this->lName=last;
    this->occupation=occup;
    this->sAddress=address;
    this->pNumber=phone;
    
}

/*
 Now we define the set and get accessor methods for the Card class. This is honestly the easiest part of the project
 */

void Card::setLast(const std::string last){
    lName = last;
}
std::string Card::getLast(){
    return lName;
}
void Card::setFirst(const std::string first){
    fName = first;
}
std::string Card::getFirst(){
    return fName;
}
void Card::setOccupation(const std::string occup){
    occupation=occup;
}
std::string Card::getOccupation(){
    return occupation;
}
void Card::setAddress(const std::string add){
    sAddress=add;
}
std::string Card::getAddress(){
    return sAddress;
}
void Card::setPhone(const std::string phone){
    pNumber=phone;
}
std::string Card::getPhone(){
    return pNumber;
}


/*
 Using the ostream we will print out the value of each card when the function is called
 */
void Card::showCard(std::ostream &os){
    os << "\n----------------------\n"
    <<std::left << std::setw(11)<<"\nLast:"
    <<"First:\n"
    << std::left << std::setw(10)<<getLast()
    << getFirst()
    << std::left << std::setw(10) << "\nOccupation:\n"
    <<getOccupation()<<"\nAddress:\n"<<getAddress()<<"\nPhone Number:\n"<<getPhone()
    << std::endl << std::endl;
}





