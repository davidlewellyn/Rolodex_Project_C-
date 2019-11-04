//
//  Program:Rolodex.cpp
//  Project: David_Lewellyn_Rolodex_Proj
//
//  Created by DAVID LEWELLYN on 10/10/19.
//  Copyright © 2019 DAVID LEWELLYN. All rights reserved.
//
/*
Summary: The Rolodex.cpp contains the ethods used to manipulate the Card objects as container class, much like a real rolodex carries, updates, and moves card.
 
 Files included: Rolodex.h


*/
#include "Rolodex.h"

/*
 Implement an internal sort method prior to the class methods or else the Calss methods
 will not recognize the internal method since while we are doing OO programming in its base case it is still procedural.
 */

bool sortLast(Card head, Card next){
    //create local variable to be used by this function only
    std::string header, nextone;
    int h = 0;
    header = head.getLast();
    nextone = next.getLast();
    
    //next we are going to sort and assign place values for the objects
    
    while( (h < header.length()) && (h < nextone.length())){
        //if the ascii of the header is less than the next Card then the list is sorted
        if(tolower(header[h]) < tolower(nextone[h]))
            return true;
        else{
            //Increment the value of h to continue the sort loop but make it
            //possible to break out of the loop as well
            ++h;
            return false;
        }
        
    }
    //if the header value is less then we are good.
    if (header.length() < nextone.length())
        return true;
    else
        return false;
    
}

/*
 Add a card to the Rolodex
 */
void Rolodex::add(Card obj){
    //set the new card at the begining of the int list of Card obj
    rolodexmove=rolodex.begin();
    //insert the new Card at the list of Card objects
    rolodex.insert(rolodex.begin(), obj);
    //sort out the last inserted objects to ensure
    rolodex.sort(sortLast);
    /*
     Add a while loop that while the interation is not at the end it will continute to increment the iterator;
     */
    while(rolodexmove != rolodex.end()){
        if (!obj.getLast().compare(rolodexmove->getLast()))
            return;
        else
            rolodexmove++;
    }
}
/*
 Implement the show method for the Rolodex class
 */
void Rolodex::show(std::ostream& os) {
    /*
     To keep the list in order make a copy of the list prior to execution
     */
    std::list< Card >::iterator temp = rolodexmove;
    /*
     Start at the beginning of the list an iterate to the end
     */
    for ( rolodexmove = rolodex.begin(); rolodexmove != rolodex.end(); rolodexmove++ )
        rolodexmove->showCard(os);
    /*
     Restore the list once the for loop has completed
     */
    rolodexmove = temp;
}

/*
 Get the current card for the Rolodex
 */
Card Rolodex::getCurrentCard(){
    return *rolodexmove;
}
/*
 Implement the flip() method to move to the next card
 */
Card Rolodex::flip(){
    //if the end of the the move is not equal to the end of the main
    if(rolodexmove != rolodex.end() && nextRoloFunc(rolodexmove) == rolodex.end()){
        rolodexmove = rolodex.begin();
    }
    else
        rolodexmove++;
    
    return *rolodexmove;
}
/*
 Removes a card from the Rolodex
 */
Card Rolodex::remove(){
    /*
     To remove a card a few items need to take place
     1. There needs to be a temp Card object need hold and inter object value
     2. All of the other objects need to be moved up/down in the list which thanks
        to the <list> STL that is one data structure we do not have to create
     */
    
    //create a temp Card object
    Card tmpCard;
    //if both the cart 
    if (rolodexmove != rolodex.end() && nextRoloFunc(rolodexmove) == rolodex.end()){
        rolodex.erase(rolodexmove);
        rolodexmove = rolodex.begin();
        tmpCard = *rolodexmove;
    }
    else{
        //create a new list to hold the the rolodexmove list interator
        std::list<Card>::iterator templist = rolodexmove;
        templist++;
        
        //Now we use a quick swap to get the list back in order
        rolodex.erase(rolodexmove);
        tmpCard = *templist;
        rolodexmove = templist;
    }
    
    return tmpCard;
}

bool Rolodex::search(const std::string lName, const std::string fName){
    
   // std::list<Card>::iterator tempinterate = rolodexmove;
    int h; //create a local vaiable for iterations outside of the loop
           // This caused me some issues inside of the loop itself
    rolodexmove = rolodex.begin();
    /*
     
     Create a while loop that interates over the rolodexmove list until it reaches the end
     */
    while(rolodexmove != rolodex.end()){
        /*
         Using a compare if the First name and the last are not found then return. Turn both comparisons to upper to eliminate case sensitivity
         */
        if ( !rolodexmove->getLast().compare(lName) && !rolodexmove->getFirst().compare(fName))
            return true;
        else
            rolodexmove++;
        
    }
    /*
     Rathan then to a toupper or tolower for string conversion the process will compare the first value of the string array
     to of the last name in the objest last name rather than comaring the entire string this is done after it verified that the
     first and the last name are infact a match
     */
    for ( rolodexmove = rolodex.begin(); rolodexmove != rolodex.end(); rolodexmove++ )
        /*
         Using a for loop we will loop over the iteration list
         */
        for ( h = 0; tolower(rolodexmove->getLast()[0]) > tolower(lName[0]); h++ )
        /*
         Break out of the loop if there are no other matches
         */
        if ( tolower(rolodexmove->getLast()[h]) < tolower(lName[h]))
            break;
        /*
         If a match is found on the first interation return true
         */
        else if (rolodexmove->getLast()[h] == lName[h]);
        
        else if (rolodexmove->getLast()[h] > lName[h] && !rolodexmove->getLast()[0] )
            return true;
    //Place is function reach no resolution
    std::cout << "Person: " << fName << " " << lName << " not found." << std::endl;
    return false;
}

//return the incrented and of the list which would be +1 to the last item
std::list<Card>::iterator Rolodex::nextRoloFunc(std::list<Card>::iterator value){
    return ++value;
}

