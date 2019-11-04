//
//  Program: main.cpp
//  Project: David_Lewellyn_Rolodex_Proj
//
//  Created by DAVID LEWELLYN on 10/15/19.
//  Copyright © 2019 DAVID LEWELLYN. All rights reserved.
//
/*
 Summary: The purpose of the main.cpp drive is to provide both a means of automated data entry for hardcoded values as well as an intercative menu for users to query, update, and delete entries in the rolodex project.
 
 Test results for the full application can be found in Test_Results.txt
 
 
 */
#include <iostream>
#include "Rolodex.h"
#include "Card.h"

void list(Rolodex &temp) {
    /*
     Place holder for funciton testing
     */
    //std::cout << "Nothing here sorry\n";
    temp.show(std::cout);
}

void view(Rolodex &temp) {
    /*
     Place holder for unit testing
     */
    //std::cout << "View function works\n";
    temp.getCurrentCard().showCard(std::cout);
}

void search(Rolodex &temp) {
    std::string lname;
    std::string fname;
    std::cout << "\nEnter Last Name: ";
    std::cin >> lname;
    std::cout << "\nEnter First Name: ";
    std::cin >> fname;
    
    if (temp.search(lname, fname))
        temp.getCurrentCard().showCard(std::cout);
    else
        return;
}

void add(Rolodex &temp) {
    Card myCard;
    std::string userData;
    
    /*
     I attempted to go cheap and use a std::cin rather than a get line, but that was proven to be problematic
     with respect to data entry. So to make it have a standard layout with a predictable apperance I adopted the getling function
     */
    std::cout << "First Name: " << std::endl;
    std::cin >> userData;
    myCard.setFirst(userData);
    /*
     Found a bug that you have to clear out the buffer after any standard cin entry when you use getline() next in conjunction with cin
     */
    std::cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
    
    std::cout << "Last Name: " << std::endl;
    getline(std::cin,userData);
    myCard.setLast(userData);
    
    std::cout << "Occupation: " << std::endl;
    getline(std::cin,userData);
    myCard.setOccupation(userData);

    std::cout << "Address (Street, City/State Zip): " << std::endl;
    getline(std::cin, userData);
    myCard.setAddress(userData);

    std::cout << "Phone Number: " << std::endl;
    getline(std::cin,userData);
    myCard.setPhone(userData);

    temp.add(myCard);
    
}

void deleteCard(Rolodex &tmp) {
    
    std::string response;
    int tmpValue=0;
    bool task=true;
    /*
     Display the current card
     */
    view(tmp);
    
    while(task){
    std::cout<<"Are you sure you want to delete this entry(Y/N):\n";
    std::cin>>response;
    /*
     To eliminate ambiguity and responce provided will be converted to to all lowercase for an easier comparison
     That comparison with then determine the int value assigned to be used in the case statement
     */
    std::for_each(response.begin(), response.end(), [](char & c) {
        c = ::tolower(c);
    });
    

        if( response == "y" || response == "yes"){
            tmpValue=1;
            break;
        }
        if( response == "n" || response == "no"){
            tmpValue=2;
            break;
        }
    else
        std::cout << "Not a valid choice.\n";
    }
    /*
     Use a switch statment for the a more defined process
     */
    switch (tmpValue) {
        case 1:
            tmp.remove();
            break;
        case 2:
            std::cout<<"Canceling Action\n";
            break;
        default:
            std::cout<<"This should not happen.\nGoodbye\n";
            exit(0);
            break;
    }
    
    
    //tmp.remove();
}

void flip(Rolodex &tmp) {
    tmp.flip();
    std::cout << "Rolodex flipped!" << std::endl;
}

int main(void)
{
    
    
    Rolodex myRolodex;
    int i;
    
    /*
     I had attempted to add the entries by invoking the object and adding it individually but while it successed it was created memory allocation errors and stack dumps. So to keep in simple each entry will just go into an array of Cards and then the array will be looped over and put into myRolodex
     */
    /*
     Initialize the array of cards for only 5 object
     */
    Card card[10];
    /*
     Tony Hansen
     Writer
     12 E Street
     New York, NY 33333
     555-9999
     */
    card[0].setFirst("Tony");
    card[0].setLast("Hansen");
    card[0].setOccupation("Writer");
    card[0].setAddress("12 E Street\nNew York, NY 33333");
    card[0].setPhone("555-9999");
    
    /*
     Jon Smyth
     Computer Hardware
     Computer Services
     Pittsburg,PA
     555-1234
     */
    card[1].setFirst("Jon");
    card[1].setLast("Smyth");
    card[1].setOccupation("Computer Hardware");
    card[1].setAddress("CMU Computer Services\nPittsburg, PA");
    card[1].setPhone("555-1324");
    
    /*
     Alonza Heard
     Mechanic
     123 Anyplace Ave.
     Malden, MA
     555-5678
     */
    card[2].setFirst("Alonza");
    card[2].setLast("Heard");
    card[2].setOccupation("Mechanic");
    card[2].setAddress("123 Anyplace Ave.\nMalden, MA");
    card[2].setPhone("555-5678");
    
    /*
     Jen Reyes
     Graphic Artist
     325 Oak Rd.
     Wilminton, MA
     555-4950
     */
    card[3].setFirst("Jen");
    card[3].setLast("Reyes");
    card[3].setOccupation("Graphic Artist");
    card[3].setAddress("325 Oak Rd.\nWilmington, MA");
    card[3].setPhone("555-4950");
    
    /*
     Alan Lupine
     Vet
     1 Bigelo Ave.
     Lawrence, MA
     555-7654
     */
    card[4].setFirst("Alan");
    card[4].setLast("Lupine");
    card[4].setOccupation("Vet");
    card[4].setAddress("1 Bigelow Ave.\nLawrence, MA");
    card[4].setPhone("555-7654");
    
    /*
     Jewel Proverb
     Landscaper
     34 Washington St
     Waltham,MA
     555-3333
     */
    card[5].setFirst("Jewel");
    card[5].setLast("Proverb");
    card[5].setOccupation("Landscaper");
    card[5].setAddress("34 Washington St.\nWaltham, MA");
    card[5].setPhone("555-3333");
    
    /*
     Paul Revere
     Radical Revolutionary
     45 Commonwealth Ave.
     Boston, MA
     */
     card[6].setFirst("Paul");
     card[6].setLast("Revere");
     card[6].setOccupation("Radical Revolutionary");
     card[6].setAddress("45 Commonwealth Ave.\nBoston, MA");
     card[6].setPhone("555-1776");
     
    /*
     Ok I am modifying this because in the spirit of New England I am a Sam Adams fan
     Samual Adams
     Beer Manufacturer
     Boston, MA
     555-2337
     */
     card[7].setFirst("Samual");
     card[7].setLast("Adams");
     card[7].setOccupation("Beer Manufacturer");
     card[7].setAddress("Boston, MA");
     card[7].setPhone("555-2337");
    
    /*
     Seymour Papert
     Lego Professor
     MIT
     555-1111
     */
    card[8].setFirst("Seymour");
    card[8].setLast("Papert");
    card[8].setOccupation("Lego Professor");
    card[8].setAddress("MIT");
    card[8].setPhone("555-1111");
    
    /*
     Fred Milton
     Sales
     12 Freedom Way
     Nashua, NH
     555-9981
     */
    card[9].setFirst("Fred");
    card[9].setLast("Milton");
    card[9].setOccupation("Sales");
    card[9].setAddress("12 Freedom Way\nNashua, NH");
    card[9].setPhone("555-9981");
    
    
     
    
    /*
     Loop overthe contents of the array to place eagc card object into the rolodex object container
     */
    for ( i = 0; i < 10; i++ )
        myRolodex.add(card[i]);

    /*
     For the interactive section I chose to implement a switch statement enclosed in a while loop that while the case remains true it will prompt the user with a menu. The only way to exit this menu is by choosing to break out of the loop
     */
    int option;
    bool choice = true;
  
    while(choice) {
    std::cout << "(1) Add Entry" << std::endl;
    std::cout << "(2) View Current" << std::endl;
    std::cout << "(3) Next Card" << std::endl;
    std::cout << "(4) Search" << std::endl;
    std::cout << "(5) Remove Card" << std::endl;
    std::cout << "(6) Print Rolodex" << std::endl;
    std::cout << "(7) Exit" << std::endl << std::endl;
    std::cout << "Enter your selection: " << std::endl;
    std::cin >> option;
    
        switch (option) {
            case 1:
                add(myRolodex);
                break;
            case 2:
                view(myRolodex);
                break;
            case 3:
                flip(myRolodex);
                break;
            case 4:
                search(myRolodex);
                break;
            case 5:
                deleteCard(myRolodex);
                break;
            case 6:
                list(myRolodex);
                break;
            case 7:
                std::cout << "Goodbye" << std::endl;
                exit(0);
            default:
                std::cout << "Choose a Valid selection or exit" << std::endl;
                break;
                
        }
    }
    return 0;
}
