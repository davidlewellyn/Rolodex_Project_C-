//
//  Card.h
//  David_Lewellyn_Rolodex_Proj
//
//  Created by DAVID LEWELLYN on 10/08/19.
//  Copyright © 2019 DAVID LEWELLYN. All rights reserved.
//

#ifndef Card_h
#define Card_h

#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>

class Card {
    public:
        /*
         Provide a default constructor for the card class
         */
        Card();
        /*
         The card class as per the requirements will take in 5 string arguments
         -First Name
         -Last Name
         -Occupation
         -Address
         -Phone number
         */
        Card( std::string first, std::string last, std::string occup, std::string address, std::string phone );
        /*
         Define set anf get methods for last name
         */
        void setLast(const std::string last);
        std::string getLast();
        /*
         Define set and get methods for first name
         */
        void setFirst(const std::string first);
        std::string getFirst();
        /*
         Define set and get methods for Occupation
         */
        void setOccupation(const std::string occup);
        std::string getOccupation();
        /*
         Define set and get methods for Address
         */
        void setAddress(const std::string add);
        std::string getAddress();
        /*
         Define set and get methods for phone number
         */
        void setPhone(const std::string phone);
        std::string getPhone();
        /*
         Provide a show method to display the card with the params provided
         */
        void showCard(std::ostream& os);
    /*
     Maintain all the personal information in private variable for
     data encapsulation of each instantiation of the Card class
     */
    private:
        std::string lName, fName, occupation, sAddress, pNumber;
    
    protected:
    
};

#endif /* Card_h */
