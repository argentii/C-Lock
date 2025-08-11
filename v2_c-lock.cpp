#include <iostream>
#include <iomanip> //for padding with zeros (ex. "04:30" vs "4:30")
#include <thread>  //for waiting one second between updates via sleep_for
#include <chrono>  //for getting time from computer
#include <ctime>   //same^^
using namespace std;

struct ProgramFlags {
    bool menu = false;
    bool help = false;
    bool analog = false;
    bool timer = false;
    bool alarm = false;
    bool verbose = false;
    bool minimal = false;
};

ProgramFlags parseFlags(int argc, char* argv[]) {
    ProgramFlags flags;

    for (int i = 1; i < argc; i++) {
        string arg = argv[i];
        cout << arg << endl;
        
        if (arg == "-m" || arg == "--menu") {
            flags.menu = true;
            cout << "menu  =true" << endl;
        }
        else if (arg == "-h" || arg == "--help") {
            flags.help = true;
            cout << "help =true" << endl;
        }
        else if (arg == "-g" || arg == "--analog") {
            flags.analog = true;
            cout << arg << " =true" << endl;
        }
        else if (arg == "-t" || arg == "--timer") {
            flags.timer = true;
            cout << arg << " =true" << endl;
        }
        else if (arg == "-a" || arg == "--alarm") {
            flags.alarm = true;
            cout << arg << " =true" << endl;
        } 
        else {
            cout << "Unknown argument: " << arg << endl;
        }
    }
    return flags;
}


void printMenu() {
    cout << "1. Show digital clock" << endl;
    cout << "-" << endl;
    cout << "-" << endl;
    cout << "-" << endl;
    cout << "-" << endl;
    cout << "-" << endl;
}


int menu(){
    int choice;
    cout << "[c-lock menu]" << endl;
    while (true) {
        printMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                showDigital();
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            case 0:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid option. " << endl;
        }
    }
    return 0;
}


void showDigital(){
    while (true) {
        //gets current time
        auto now = chrono::system_clock::now();
        
        //converts var now into an int representing the seconds since 1-1-1970
        time_t now_c = chrono::system_clock::to_time_t(now);  

        //turns now_c into a tm struct, aka turns seconds since UNIX epoch into hours:minutes:seconds,
        //also converts time to computer's local time zone
        tm* local = localtime(&now_c);

        string timezone = "";
        int h = local->tm_hour; //hours
        int m = local->tm_min;  //minutes
        int s = local->tm_sec;  //seconds

        //Clock cout to terminal
        cout << "\r"  // return to beginning of line
            << timezone << " "
            << setfill('0') << setw(2) << h << ":"
            << setw(2) << m << ":"
            << setw(2) << s << flush; //flush prints time immediately

        this_thread::sleep_for(chrono::seconds(1));
    }
}


int handleFlags(ProgramFlags flags){
    cout << "Flags: " << endl;

    if (flags.menu) {
        cout << "menu" << endl;
        menu();
    }
    if (flags.help) {
        cout << "help" << endl;
    }
    if (flags.analog) {
        cout << "analog" << endl;
    }
    if (flags.timer) {
        cout << "timer" << endl;
    }
    if (flags.alarm) {
        cout << "alarm" << endl;
    }
    if (flags.verbose) {
        cout << "verbose" << endl;
    }
    if (flags.minimal) {
        cout << "minimal" << endl;
    }
    
    return 0;
}


int main(int argc, char* argv[]) {
    auto flags = parseFlags(argc, argv);

    cout << argc << endl;
    if (argc == 1) {
        showDigital();
    } else {
        cout << "more than 1 args" << endl;
        handleFlags(flags);
    }
}
