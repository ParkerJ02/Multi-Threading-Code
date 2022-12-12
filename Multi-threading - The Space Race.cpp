/*
Parker Haynie
12/11/2022
Multi-Threading - The Space Race
*/

// This is the header file that contains all of the functions like "cout" and "cin".
#include <iostream>
// This is the header file that includes built-in support for threads, atomic operations, mutual exclusions, condition variables, and futures.
#include <thread>
// This is the header file that provides basic mutual exclusion facility.
#include <mutex>
// This is the header that tells the program to use a variable that has a type std::string.
#include <string>
// This tells the program to look at the standard namespace for everything that is not declared.
using namespace std;

// This initializes the mutual exclusion varaible "Locker".
mutex Locker;
// This initializes the string variable "whichThread".
string whichThread;
// This initializes the int variable "ID".
int ID;

// This initializes the void function "displayTitle()".
void displayTitle();
// This initializes the void function "RocketLaunch(string threadName)".
void RocketLaunch(string threadName);
// This initializes the void function "waitThreeSeconds()".
void waitThreeSeconds();
// This initializes the void function "displayExitMessage()".
void displayExitMessage();

// This is the "main()" function. This is the first function that the program looks at.
int main()
{
    // This displays whatever is in the "displayTitle()" function to the command terminal.
    displayTitle();
    // This line creates the "MainThread" and tells it to use the "RocketLaunch" function with the string "Main Thread".
    thread MainThread{ RocketLaunch, "Main Thread" };
    // This line means that the "MainThread" will execute after the thread completion prcoess.
    MainThread.join();
    // This line creates the "AdditionalThread" and tells it to use the "RocketLaunch" function with the string "Additional Thread".
    thread AdditionalThread{ RocketLaunch, "Additional Thread" };
    // This line means that the "MainThread" will execute after the thread completion prcoess.
    AdditionalThread.join();
    // This displays whatever is in the "displayExitMessage()" function to the command terminal.
    displayExitMessage();
}

// This is a void function that displays the title of the program.
void displayTitle() 
{
    cout << "                                  Space Race Program" << endl;
    cout << "-------------------------------------------------------------------------------------" << endl;
}

// This is a void function that determines what is displayed depending on the thread that is being used..
void RocketLaunch(string threadName) 
{
    // This line locks the code so that only one thread can use it at one time until it hits unlock.
    Locker.lock();
    // This line sets the string variable "whichThread" equal to the string varaible "threadName".
    whichThread = threadName;
    // This if/else statements determines what will be displayed to the console depending on the current thread in use.
    // This if statement only occurs if the string variable "whichThread" is equal to the string "Main Thread".
    if (whichThread == "Main Thread")
    {
        // This line displays the current thread that is in use.
        cout << "Current Thread In Use: " << whichThread << endl;
        // This line sets the ID of the thread to 67825.
        ID = 67825;
        // This line displays the ID of the thread that is in use.
        cout << "Main Thread ID: " << ID << endl;
        cout << "\nPress enter to start launching the rockets from Space Base using Main Thread!" << endl;
        // This line pauses the program until the user hits enter.
        system("Pause>null");
        // This line displays a message to the console that says that the Space Base has started the rocket launching process using the Main Thread.
        cout << "\n   *** Space Base has started the rocket launching process using the Main Thread ***" << endl;
        cout << "       (Please wait three seconds for this process to finish)" << endl;
        // This function is what my program uses to wait 3 seconds before continuing.
        waitThreeSeconds();
        // This line displays a message to the console that says that the Space Base successfully launched Rocket #1 using the Main Thread.
        cout << "\n   !!! Space Base has launched Rocket #1 using the Main Thread !!!" << endl;
        cout << "\nPress enter to transfer control to the Space Cadet at the Space Pad to start" << endl;
        cout << "launching the rest of the rockets from the Additional Thread!" << endl;
        // This line pauses the program until the user hits enter.
        system("Pause>null");
        cout << "\n-------------------------------------------------------------------------------------" << endl;
    }
    // This else if statement only occurs if the string variable "whichThread" is equal to the string "Additional Thread".
    else if (whichThread == "Additional Thread")
    {
        // This line displays the current thread that is in use.
        cout << "Current Thread In Use: " << whichThread << endl;
        // This line sets the ID of the thread to 51947.
        ID = 51947;
        // This line displays the ID of the thread that is in use.
        cout << "Additional Thread ID: " << ID << endl;
        cout << "\nPress enter to allow the Space Cadet to continue launching rockets from the" << endl;
        cout << "Additional Thread!" << endl;
        // This line pauses the program until the user hits enter.
        system("Pause>null");
        // This for statement is what allows the same process to loop nine more times.
        for (int i = 2; i < 11; i++)
        {
            // This line displays a message to the console that says that the Space Cadet has started the rocket launching process using the Additional Thread.
            cout << "\n   *** Space Cadet has started the rocket launching process using the Additional Thread ***" << endl;
            cout << "       (Please wait three seconds for this process to finish)" << endl;
            // This function is what my program uses to wait 3 seconds before continuing.
            waitThreeSeconds();
            // This line displays a message to the console that says that the Space Cadet successfully launched the next rocket using the Additional Thread.
            cout << "\n   !!! Space Cadet has launched Rocket #" << i << " using the Additional Thread !!!" << endl;
            // This if statment only occurs when "i" is less than 10.
            if (i < 10)
            {
                cout << "\nPress enter to allow the space cadet to launch the next rocket" << endl;
                // This line pauses the program until the user hits enter.
                system("Pause>null");
                cout << "-------------------------------------------------------------------------------------" << endl;
            }
            // This if statment only occurs when "i" is more than 10.
            else
            {
                cout << " " << endl;
            }
        }
    }
    // This line unlocks the code above so that another thread can use it.
    Locker.unlock();
}

// This is a void function that makes the thread in use wait for a total of three seconds.
void waitThreeSeconds()
{
    cout << "\n   ";
    // This line makes the current thread in use stop for one second.
    this_thread::sleep_for(chrono::seconds(1));
    cout << ".";
    // This line makes the current thread in use stop for one second.
    this_thread::sleep_for(chrono::seconds(1));
    cout << ".";
    // This line makes the current thread in use stop for one second.
    this_thread::sleep_for(chrono::seconds(1));
    cout << "." << endl;
}

// This is a void function that displays the exit message if the user is done using the program.
void displayExitMessage()
{
    cout << "-------------------------------------------------------------------------------------" << endl;
    cout << "The program has finished. Press enter to exit the program." << endl;
    // This line pauses the program until the user hits enter.
    system("pause>null");
    exit(EXIT_SUCCESS);
}