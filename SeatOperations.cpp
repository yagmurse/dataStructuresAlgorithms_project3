/*
Student Name:
Student Number:
Project Number: 3
Compile Status: [SUCCESS/FAIL]
Running Status: [SUCCESS/FAIL]
Notes: Anything you want to say about your code that will be helpful in the grading process.
*/
#include "SeatOperations.h"

using namespace std;

SeatOperations::SeatOperations(int N, int M){

    // IMPLEMENT ME!
    this->N = N;
    this->M = M;

   lines[0].resize(N);
   lines[1].resize(M);


}

void SeatOperations::addNewPerson(int personType, const string& ticketInfo){
    // IMPLEMENT ME!

    cout << " girdim" << endl;
    int l=line(ticketInfo);
    int s=seat(ticketInfo);
    int sizeOfLine = 0;
    (l == 0) ? (sizeOfLine=N) :(sizeOfLine=M);
    Person newPerson;
    Person removedPerson;
    newPerson.seatNumber=s;
    newPerson.type=personType;
    newPerson.line=l;

    int seatModulo=(s-1)%sizeOfLine;

        removedPerson=lines[l][seatModulo];
        lines[l][seatModulo]=newPerson;
        replaceDecide(l,seatModulo,removedPerson);

    cout << " ciktim" << endl;
}

void SeatOperations::person1replace(int line,Person newPerson) {
    int newLine= !(line);
    int size=lines[newLine].size();
    int newSeat=(newPerson.seatNumber-1)%size;
    Person removedPerson;
    removedPerson=lines[newLine][newSeat]; //aşağıda değiştirince removedpers da değiişecek mi
    lines[newLine][newSeat]=newPerson;
    replaceDecide(newLine,newSeat,removedPerson);

}
void SeatOperations::person2replace(int line, int seat,Person newPerson) {
    int size;
    (line == 0) ? (size=N) :(size=M);
    int newSeat=((seat+1)%size);
    Person removedPerson;
    if(newSeat==0) {
        line = !line;
    }

    removedPerson=lines[line][newSeat];
    lines[line][newSeat]=newPerson;
    replaceDecide(line,newSeat,removedPerson);
}

void SeatOperations ::person3replace(int line, int seat, Person person) {
    Person removedPerson;
    int back=2*person.type3LastOperation+1;
    person.type3LastOperation+=1;
    int size;
    (line == 0) ? (size=N) :(size=M);
    int newSeat=(seat+back)%(M+N);

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

   for(int i=0;i<N;i++) {
        outFile << lines[0][i].type;
        if(lines[0][i].type != 0)
            outFile << " " << (lines[0][i].line==0 ? 'A':'B') << lines[0][i].seatNumber ;
        outFile << endl;
    }
    for(int i=0;i<M;i++) {
        outFile << lines[1][i].type ;
        if(lines[1][i].type != 0)
            outFile << " " << (lines[1][i].line==0 ? 'A':'B' ) << lines[1][i].seatNumber;
        outFile << endl;
    }



}
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