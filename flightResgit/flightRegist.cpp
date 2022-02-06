/* Work 3.2: Flight Regist
    Subject: Data Structure
    Authors: Alejandro Salazar - Stive Salazar
    Fecha: 20-10-21
    Compilador: g++.exe (Rev10, Built by MSYS2 project) 10.2.0
*/

#include <iostream>
#include <string.h> // getline(istream& is, string& str, char delim )
#include <string> // stoi
#include <stdlib.h>
#include <sstream>
#include <fstream> // ifstream ofstream data types

using namespace std;

#define Pause cin.get()

// Flight structure
struct Flight {
    char From [30],
        To [30],
        AirplaneRegist[9],
        PilotRegist[9],
        IdFlight[5];

    int Status; //(0: scheduled, 1: performed)
    
    struct Timer *FlightTime; 
    struct Date *FlightDate;  
    
    struct Flight *Next;
    struct Passenger *SubPassenger;
};


// Date structures 
struct Timer { // Time
    int Hour,
        Min;
};

struct Date { // Date
    int dd,
        mm,
        yyyy;
};

// Passenger structure
struct Passenger {
	char IdFlight[6], 
         Name[30],
         Phone[11], 
         Id[11];
    
	int Status; // (1: reserve, 2: on board).

	struct Passenger *Next;
};

// For presentation, redirection and general information listing, 
void MainMenu();

void Redirection(Flight *&FlightNode, Passenger *&PassengerNode, int Option);

void ListGeneralInformation(Flight *&File);

// For the pasenger 
void ReadPassengers(Passenger *&File);

void WritePassenger(Passenger *&File);

void PushPassenger(Passenger *&File, Passenger *&NewNode);

void ShowPassenger(Passenger *&File);

void AddPassenger(Passenger *&File);

void GetPassengerRegist(Passenger *&File);

void ChangePassengerStatus(Passenger *&File);

// For the flight
void ReadFlights(Flight *&File);

void WriteFlight(Flight *&File);

void PushFlight(Flight *&File, Flight *&NewNode);

void PushFlightSubList(Passenger *&SubNode, Passenger *&File);

void ShowFlight(Flight *&File);

void AddFlight(Flight *&File);

void ChangeFlightStatus(Flight *&File);

// Time 
void GetDate(Date *&File, char Date[11]);

void GetTime(Timer *&File, char Time[6]);



//--------------------------------------------------Presenation and redirection 
void MainMenu() {
    cout<< "Exe-Airline Regist"<< endl;
    cout<< "1. Add flight"<< endl;
    cout<< "2. Add paggenger"<< endl;
    cout<< "3. List flight regists"<< endl;
    cout<< "4. Get passenger regist"<< endl;
    cout<< "5. Change flight status"<< endl;
    cout<< "6. Change passenger status"<< endl;
    cout<< "7. Exit"<< endl;
    cout<< "--> ";
}

void Redirection(Flight *&FlightNode, Passenger *&PassengerNode, int Option) {
    Passenger *NewPassenger = PassengerNode;

    Flight *NewFlight = FlightNode;
    
    switch(Option) {
        case 1:
            // Here try to add the flight and after it check if does there are sublists to be added
            AddFlight(FlightNode);
            
            // Here we try to check if the id regist is inside the Passenger list
            // then point it form the added flight regist Passenger sub list 
            while(NewFlight->Next != NULL) {
                NewFlight = NewFlight->Next;
            }

            while(NewPassenger != NULL) {
                if(strcmp(NewPassenger->IdFlight, NewFlight->IdFlight) == 0) {
                    PushFlightSubList(NewFlight->SubPassenger, NewPassenger);
                }

                NewPassenger = NewPassenger->Next;
            }

            WriteFlight(FlightNode);
        break;

        case 2:
            AddPassenger(PassengerNode);

            while(NewPassenger->Next != NULL) {
                NewPassenger = NewPassenger->Next;
            }

            while(NewFlight != NULL) {
                if(strcmp(NewPassenger->IdFlight, NewFlight->IdFlight) == 0) {
                    PushFlightSubList(NewFlight->SubPassenger, NewPassenger);
                    
                    break;
                }

                NewFlight = NewFlight->Next;
            }

            WritePassenger(PassengerNode);
        break;

        case 3:
            ListGeneralInformation(FlightNode);
        break;

        case 4:
            GetPassengerRegist(PassengerNode);
        break;

        case 5: 
            ChangeFlightStatus(FlightNode);
        break;

        case 6: 
            ChangePassengerStatus(PassengerNode);
        break;

        case 7: 
            cout<< "Leaving...";
        break;

        default:
            cout<< "The choosed option is not avaliable, please choose again.";
        break;
    }

    Pause;
    Pause;

    system("cls");
}

void ListGeneralInformation(Flight *&File) {
    Flight *NewFlight = File;

    while(NewFlight != NULL) {
        cout<< "-----------------------------------------"<< endl<< endl;
        ShowFlight(NewFlight);

        Passenger *NewPassenger = NewFlight->SubPassenger;

        while(NewPassenger != NULL) {
            ShowPassenger(NewPassenger);

            NewPassenger = NewPassenger->Next;
        }
        cout<< "-----------------------------------------"<< endl;

        NewFlight = NewFlight->Next;
    }
}

//--------------------------------------------------Passenger
void ReadPassengers(Passenger *&File) {
    ifstream FILE;

    FILE.open("passenger.txt");

    while(!FILE.eof()) {
        Passenger *NewNode = new Passenger();

        FILE >> NewNode->IdFlight;

        FILE >> NewNode->Id;

        FILE >> NewNode->Phone;

        FILE >> NewNode->Status;

        FILE >> NewNode->Name;

        PushPassenger(File, NewNode);
    }

    FILE.close();
}

void WritePassenger(Passenger *&File) {
    ofstream FILE;

    Passenger *NewNode = File;

    FILE.open("passenger.txt");

    while(NewNode != NULL) {
        FILE << NewNode->IdFlight;
        FILE << " ";

        FILE << NewNode->Id;
        FILE << " ";

        FILE << NewNode->Phone;
        FILE << " ";

        FILE << NewNode->Status;
        FILE << " ";

        FILE << NewNode->Name;

        NewNode = NewNode->Next;

        if(NewNode != NULL) {
            FILE << "\n";
        }
    }

    FILE.close();
}

void PushPassenger(Passenger *&File, Passenger *&NewNode) {
    Passenger *Aux1 = File;

    Passenger *Aux2;

    while(Aux1 != NULL) {
        Aux2 = Aux1;

        Aux1 = Aux1->Next;
    }

    if(File == Aux1) {
        File = NewNode;
    } else {
        Aux2->Next = NewNode;
    }

    NewNode->Next = Aux1;
}

void ShowPassenger(Passenger *&File) {
    cout<< "Flight ID: "<< File->IdFlight<< endl;
    cout<< "ID: "<< File->Id<< endl;
    cout<< "Full name: "<< File->Name<< endl;
    cout<< "Phone number: "<< File->Phone<< endl;
    if(File->Status == 1) {
        cout<< "Status: Reserved"<< endl<< endl;
    } else {
        cout<< "Status: On board"<< endl<< endl;
    }
}

void AddPassenger(Passenger *&File) {
    Passenger *NewNode = new Passenger();

    cout<< "Please enter words without tildes";
    cout<< "\nFlight ID: "; cin>> NewNode->IdFlight;
    cout<< "\nID: "; cin>> NewNode->Id;
    cout<< "\nFull name (Use - to separe words please): "; cin>> NewNode->Name;
    cout<< "\nPhone number: "; cin>> NewNode->Phone;
    cout<< "\nStatus (1: reserve, 2: on board): "; cin>> NewNode->Status;

    PushPassenger(File, NewNode);
}

void GetPassengerRegist(Passenger *&File) {
    Passenger *NewPassenger = File;

    char Id[11];

    cout<< "\nEnter the passenger id: "; cin>> Id;

    cout<< endl;

    while(NewPassenger != NULL) {
        if(strcmp(NewPassenger->Id, Id) == 0) {
            ShowPassenger(NewPassenger);
        }

        NewPassenger = NewPassenger->Next;
    }
}

void ChangePassengerStatus(Passenger *&File) {
    Passenger *NewPassenger = File;

    char Id[11];

    cout<< "\nEnter the passenger id: "; cin>> Id;

    cout<< endl;

    while(NewPassenger != NULL) {
        if(strcmp(NewPassenger->Id, Id) == 0) {
            NewPassenger->Status  == 1 ? NewPassenger->Status = 2: NewPassenger->Status = 1;
        }

        NewPassenger = NewPassenger->Next;
    }

    WritePassenger(File);
}

//--------------------------------------------------Flight
void ReadFlights(Flight *&File) {
     ifstream FILE;

    FILE.open("flight.txt");

    while(!FILE.eof()) {
        Flight *NewNode = new Flight();

        FILE >> NewNode->IdFlight;

        FILE >> NewNode->Status;

        FILE >> NewNode->AirplaneRegist;

        FILE >> NewNode->PilotRegist;

        // char FlightDate[9];

        // FILE >> FlightDate;

        // SetDate(File, FlightDate);

        char FlightTime[6];

        FILE >> FlightTime;

        NewNode->FlightTime = new Timer();

        GetTime(NewNode->FlightTime, FlightTime);

        char FlightDate[11];

        FILE >> FlightDate;

        NewNode->FlightDate = new Date();

        GetDate(NewNode->FlightDate, FlightDate);
        
        FILE >> NewNode->From;

        FILE >> NewNode->To;

        PushFlight(File, NewNode);
    }

    FILE.close();
}

void WriteFlight(Flight *&File) {
    ofstream FILE;

    Flight *NewNode = File;

    FILE.open("flight.txt");

    while(NewNode != NULL) {
        FILE << NewNode->IdFlight;
        FILE << " ";

        FILE << NewNode->Status;
        FILE << " ";

        FILE << NewNode->AirplaneRegist;
        FILE << " ";

        FILE << NewNode->PilotRegist;
        FILE << " ";

        stringstream timer;
        char tm[7];
        timer << NewNode->FlightTime->Hour;
        timer << ":";
        timer << NewNode->FlightTime->Min;
        timer >> tm;

        FILE << tm;
        FILE << " ";

        stringstream date;
        char dt[11];
        date << NewNode->FlightDate->dd;
        date << "/";
        date << NewNode->FlightDate->mm;
        date << "/";
        date << NewNode->FlightDate->yyyy;
        date >> dt;

        FILE << dt;
        FILE << " ";

        FILE << NewNode->From;
        FILE << " ";

        FILE << NewNode->To;

        NewNode = NewNode->Next;

        if(NewNode != NULL) {
            FILE << "\n";
        }
    }

    FILE.close();
}

void PushFlight(Flight *&File, Flight *&NewNode) {
    Flight *Aux1 = File;

    Flight *Aux2;

    while(Aux1 != NULL) {
        Aux2 = Aux1;

        Aux1 = Aux1->Next;
    }

    if(File == Aux1) {
        File = NewNode;
    } else {
        Aux2->Next = NewNode;
    }

    NewNode->Next = Aux1;
}

void PushFlightSubList(Passenger *&SubNode, Passenger *&File) {
    Passenger *NewNode = new Passenger();

    strcpy(NewNode->IdFlight, File->IdFlight);

    strcpy(NewNode->Name, File->Name);
    
    strcpy(NewNode->Phone, File->Phone);
    
    strcpy(NewNode->Id, File->Id);
    
    NewNode->Status = File->Status;

    PushPassenger(SubNode, NewNode);
}

void ShowFlight(Flight *&File) {
    cout<< "Flight ID: "<< File->IdFlight<< endl;
    cout<< "Airplane regist: "<< File->AirplaneRegist<< endl;   
    cout<< "Pilot regist: "<< File->PilotRegist<< endl;
    cout<< "Flight date: ";
    
    if(File->FlightDate->dd < 10) {
        cout<< "0";
    }
    cout<< File->FlightDate->dd<< "/";
    
    if(File->FlightDate->mm < 10) {
        cout<< "0";
    } 
    cout<< File->FlightDate->mm<< "/"<< File->FlightDate->yyyy<< endl;
    cout<< "Flight time: "<< File->FlightTime->Hour<< ":"<< File->FlightTime->Min<< endl;
    cout<< "From: "<< File->From<< endl;
    cout<< "To: "<< File->To<< endl;

    if(File->Status == 0) {
        cout<< "Status: Schedule"<< endl<< endl;
    }else {
        cout<< "Status: Performed"<< endl<< endl;
    }
}

void AddFlight(Flight *&File) {
    Flight *NewNode = new Flight();
    Timer *NewTimer = new Timer();
    Date *NewDate = new Date();

    cout<< "Please enter words without tildes";
    cout<< "\nFlight ID: "; cin>> NewNode->IdFlight;
    cout<< "\nAirplane regist: "; cin>> NewNode->AirplaneRegist;
    cout<< "\nPilot regist: "; cin>> NewNode->PilotRegist;
    cout<< "\nFlight time (hour minute): "; cin>> NewTimer->Hour>> NewTimer->Min;
    NewNode->FlightTime = NewTimer;

    cout<< "\nFlight date (dd mm yyyy): "; cin>> NewDate->dd>> NewDate->mm>> NewDate->yyyy;
    NewNode->FlightDate = NewDate;

    cout<< "\nFrom (City/Country): "; cin>> NewNode->From;
    cout<< "\nTo: (City/Country): "; cin>> NewNode->To;
    cout<< "\nStatus (0: scheduled, 1: performed): "; cin>> NewNode->Status;

    PushFlight(File, NewNode);
}

void ChangeFlightStatus(Flight *&File) {
    Flight *NewFlight = File;

    char Id[8];

    cout<< "\nEnter the flight status id: "; cin>> Id;

    cout<< endl;

    while(NewFlight != NULL) {
        if(strcmp(NewFlight->AirplaneRegist, Id) == 0) {
            NewFlight->Status  == 0 ? NewFlight->Status = 1: NewFlight->Status = 0;
        }

        NewFlight = NewFlight->Next;
    }

    WriteFlight(File);
}

//--------------------------------------------------Time/Date
void GetDate(Date *&File, char Date[9]) {
    char *Token,
          DD[3],
          MM[3],
          YYYY[5];

    /* Get day */
    Token = strtok(Date, "/");
    strcpy(DD, Token);
   
    /* Get month */
    Token = strtok(NULL, "/");
    strcpy(MM, Token);

    /* Get year */
    Token = strtok(NULL, "/");
    strcpy(YYYY, Token);

    File->dd = stoi(DD);
    File->mm = stoi(MM);
    File->yyyy = stoi(YYYY);
}

void GetTime(Timer *&File, char Time[6]) {
    char *Token,
         Hour[3],
         Min[3];

    int x,
        y;

    /* Get minutes */
    Token = strtok(Time, ":");
    strcpy(Hour, Token);
   
    /* Get hour */
    Token = strtok(NULL, ":");
    strcpy(Min, Token);

    // Save the parsed data
    File->Hour = stoi(Hour);

    File->Min = stoi(Min);
}

/* TODO: 1) The user enter a char or string at the main menu choose
         2) The user enter a char or string a the status reading of AddPassenger
         3) The user enter a char or string a the status reading of AddFlight
         4) The user enter a char or string a the time and date reading of AddPassenger
         5) Check that the entered flight doens't exist with the same date  or date and time
*/

int main() {
    // MainMenu();
    Passenger *passenger = NULL;

    Flight *flight = NULL;

    int Option;

    ReadPassengers(passenger);

    ReadFlights(flight);

    // From here we try to create the subLists of passengers
    Flight *FlighNode = flight; 

    while(FlighNode != NULL) {
        char IdFlight[6]; // Save the fligh FlighId to can compare with the passenger FlighId

        Passenger *PassengerNode = passenger; // Always from the begining 

        strcpy(IdFlight, FlighNode->IdFlight);

        while(PassengerNode != NULL) {
            if(strcmp(IdFlight, PassengerNode->IdFlight) == 0) {
                PushFlightSubList(FlighNode->SubPassenger, PassengerNode); // Push the curren passenger information into the subList
            }

            PassengerNode = PassengerNode->Next;
        }

        FlighNode = FlighNode->Next;
    } // Main SubList creation finish here

    system("cls");

    do {
        MainMenu();

        cin>> Option;

        Redirection(flight, passenger, Option);
    }while(Option != 7);

    return 0;
}