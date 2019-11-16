#ifndef CMPE250_ASSIGNMENT3_SEATOPERATIONS_H
#define CMPE250_ASSIGNMENT3_SEATOPERATIONS_H
#include <iostream>
#include <vector>
#include <fstream>


using namespace std;

struct Person{
    int type=0;
    int line=0, seatNumber=0;
    int type3LastOperation=0;
};

class SeatOperations{


private:
    vector<Person> lines[2];
    int N, M;

public:
    SeatOperations(int N, int M);
    void addNewPerson(int personType, const string& ticketInfo);
    void printAllSeats(ofstream& outFile);

    // YOU CAN ADD YOUR HELPER FUNCTIONS

    void person1replace(int line,Person person);
    void person2replace(int line,int seat,Person person);
    void person3replace(int line,int seat,Person person);
    void replaceDecide(int line,int seat,Person person);
   int line(const string &ticket) {
       char s=ticket[0];
       int i= (s=='A') ? (0) : (1);
       return i;
   }
   int seat(const string &ticket) {
       return atoi(&ticket[1]);
   }

};

#endif //CMPE250_ASSIGNMENT3_SEATOPERATIONS_H
