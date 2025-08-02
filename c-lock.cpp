#include <iostream>
#include <iomanip> //for padding with zeros (ex. "04:30" vs "4:30")
#include <thread>  //for waiting one second between updates via sleep_for
#include <chrono>  //for getting time from computer
#include <ctime>   //same^^
using namespace std;

int main() {
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
