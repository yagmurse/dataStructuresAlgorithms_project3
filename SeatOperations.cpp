/*
Student Name:Yağmur Selek
Student Number: 2017400273
Project Number: 3
Compile Status: [SUCCESS/FAIL]
Running Status: [SUCCESS/FAIL]
Notes: Anything you want to say about your code that will be helpful in the grading process.
*/
#include "SeatOperations.h"

using namespace std;

SeatOperations::SeatOperations(int N, int M){

    // IMPLEMENT ME!
    //assigns the given integers to M and N
    this->N = N;
    this->M = M;
    //decides the size of the arrays regarding given integers
   lines[0].resize(N);
   lines[1].resize(M);


}
//changes the given string ticketInfo to desired line and seat
//creates given person type and places it as intended
void SeatOperations::addNewPerson(int personType, const string& ticketInfo){
    // IMPLEMENT ME!
    //line&seat methods from header file takes the string and gives the integer value
         int l=line(ticketInfo);
         int s=seat(ticketInfo);
         int sizeOfLine = (l == 0) ? (N) :(M);
     Person newPerson;
     Person removedPerson;
    newPerson.seatNumber=s;
    newPerson.type=personType;
    newPerson.line=l;
    int seatModulo=(s-1)%sizeOfLine;
    removedPerson=lines[l][seatModulo];
    lines[l][seatModulo]=newPerson;
    replaceDecide(l,seatModulo,removedPerson);

}
//includes the actions desired for person type 1
void SeatOperations::person1replace(int line,Person newPerson) {
    int newLine= !(line);
    int size=lines[newLine].size();
    int newSeat=(newPerson.seatNumber-1)%size;
    Person removedPerson = lines[newLine][newSeat];
    lines[newLine][newSeat]=newPerson;
    replaceDecide(newLine,newSeat,removedPerson);

}
//includes the actions desired for person type 2
void SeatOperations::person2replace(int line, int seat,Person newPerson) {
    int size=(line == 0) ? (N) :(M);
    int newSeat=((seat+1)%size);
    Person removedPerson;
    if(newSeat==0) {
        line = !line;
    }
    removedPerson=lines[line][newSeat];
    lines[line][newSeat]=newPerson;
    replaceDecide(line,newSeat,removedPerson);
}
//includes the actions desired for person type 3
void SeatOperations ::person3replace(int line, int seat, Person person) {
    Person removedPerson;
    int back=2*person.type3LastOperation+1;
    person.type3LastOperation+=1;
    //following mod operations assures us to take a positive result
    int newSeat=((seat+back)%(M+N))%(M+N);
     if(newSeat>=N) {
        newSeat-=N;
        line=!(line);
    }
        removedPerson=lines[line][newSeat];
        lines[line][newSeat]=person;
        replaceDecide(line,newSeat,removedPerson);


}

void SeatOperations::printAllSeats(ofstream& outFile){
    // IMPLEMENT ME!

   for(int i=0;i<N+M;i++) {
       int place=(i<N) ? (i) : (i-N);
       int line=(i<N) ? (0) : (1);

        outFile << lines[line][place].type;
        if(lines[line][place].type != 0)
            outFile << " " << (lines[line][place].line==0 ? 'A':'B') << lines[line][place].seatNumber ;
        outFile << endl;
    }

}
//decides which operation is going to be performed and operates it
void SeatOperations::replaceDecide(int line, int seat, Person person) {
    if(person.type==0) {
        return;
    }
    else if (person.type==1) {
        person1replace(line,person);
    }
    else if(person.type==2) {
        person2replace(line,seat,person);
    } else {
        person3replace(line,seat,person);
    }
}

// YOU CAN ADD YOUR HELPER FUNCTIONS