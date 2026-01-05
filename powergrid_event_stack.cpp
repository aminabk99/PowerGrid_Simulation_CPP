#include <iostream>
#include <string>
using namespace std;

// Structure for stack node
struct LogNode {
    string event;
    LogNode* next;
};

// Global pointer to the top of the stack
LogNode* top = nullptr;

// Pushes a new log entry onto the stack
void pushLog(string event) {
    LogNode* newNode = new LogNode;
    newNode->event = event;
    newNode->next = top;
    top = newNode;
}

// Returns the most recent event without removing it
string peekLog() {
    if (top == nullptr) {
        return "The log is empty";
    }
    return top->event;
}

// Removes the most recent event from the stack and displays it
void popLog() {
    if (top == nullptr) {
        cout << "The log is empty" << endl;
        return;
    }

    LogNode* temp = top;
    cout << "Popped event: " << top->event << endl;
    top = top->next;
    delete temp;
}

int main() {
    // Push events onto the log stack
    pushLog("2025-04-17 10:00, TexasSun plant started operation");
    pushLog("2025-04-17 11:30, FermiNuc detected minor fault");
    pushLog("2025-04-17 12:15 CoastalWind scheduled for maintenance");
    pushLog("2025-04-17 13:45 HydroDam output reduced due to maintenance");

    // Examine and process log entries
    cout << peekLog() << endl;  // HydroDam
    popLog();                   // HydroDam
    popLog();                   // CoastalWind
    popLog();                   // FermiNuc

    cout << peekLog() << endl;  // TexasSun
    cout << peekLog() << endl;  // TexasSun

    popLog();                   // TexasSun
    cout << peekLog() << endl;  // Empty

    return 0;
}
