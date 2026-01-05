#include <iostream>
#include <string>
using namespace std;

// Power plant node structure
struct PlantNode {
    string plantName;
    double capacityMW;
    PlantNode* next;
};

// Function for finding the maximum capacity in the linked list
double findMaxCapacity(PlantNode* head) {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return 0.0;
    }

    double maxCapacity = head->capacityMW;
    PlantNode* current = head->next;

    while (current != nullptr) {
        if (current->capacityMW > maxCapacity) {
            maxCapacity = current->capacityMW;
        }
        current = current->next;
    }

    return maxCapacity;
}

// Function for removing the first plant from the list
void removeFirstPlant(PlantNode*& head) {
    if (head == nullptr) {
        cout << "List is already empty. Nothing to remove." << endl;
        return;
    }

    PlantNode* temp = head;
    head = head->next;
    delete temp; // Clean up memory
}

int main() {
    // Manually creating nodes and linking them
    PlantNode* node3 = new PlantNode{ "Geotherm", 150.0, nullptr };
    PlantNode* node2 = new PlantNode{ "FermiNuc", 1200.0, node3 };
    PlantNode* node1 = new PlantNode{ "CoastalWind", 37250.0, node2 };

    // Head of the linked list
    PlantNode* gridHead = node1;

    // Find and display the maximum capacity
    double maxCapacity = findMaxCapacity(gridHead);
    cout << "Maximum plant capacity: " << maxCapacity << " MW" << endl;

    // Remove the first plant
    cout << "Removing first plant from the grid..." << endl;
    removeFirstPlant(gridHead);

    // Find and display the new maximum capacity
    maxCapacity = findMaxCapacity(gridHead);
    cout << "New maximum plant capacity: " << maxCapacity << " MW" << endl;

    // Clean up remaining nodes
    while (gridHead != nullptr) {
        removeFirstPlant(gridHead);
    }

    return 0;
}
