#include <iostream>
#include <string>
using namespace std;

void hauntedHouseGame() {
    int choice;
    bool hasKey = false;
    
    cout << "Welcome to the Haunted House!" << endl;
    cout << "Your night of a stay is at a haunted house, you walk up the haunted house path & find yourself at the entrance of the dark house. Do you: " << endl;
    cout << "1. Enter through the front door\n2. Enter through the right window\n3. Look around outside\n";
    cin >> choice;
    
    if (choice == 1) {
        cout << "You step inside. The door slams shut behind you!" << endl;
        cout << "You see a staircase leading up and a hallway leading left. Where do you go?" << endl;
        cout << "1. Go upstairs\n2. Go left into the hallway\n";
        cin >> choice;
        
        if (choice == 1) {
            cout << "You walk upstairs and find a locked door. Do you: " << endl;
            cout << "1. Try to break the door\n2. Go back downstairs\n";
            cin >> choice;
            
            switch (choice) {
                case 1:
                    cout << "A ghost appears and drags you into the abyss! You have met a gruesome demise." << endl;
                    return;
                case 2:
                    cout << "You go back downstairs." << endl;
                    break;
                default:
                    cout << "Invalid choice! The house swallows you whole!" << endl;
                    return;
            }
        }
        
        cout << "In the hallway, you find a key on the floor. Take it? (1 for Yes, 2 for No)" << endl;
        cin >> choice;
        if (choice == 1) {
            hasKey = true;
            cout << "You picked up the key!" << endl;
        }
        
        cout << "You see a door at the end of the hallway. Try to open it? (1 for Yes, 2 for No)" << endl;
        cin >> choice;
        
        if (choice == 1) {
            if (hasKey) {
                cout << "You use the key to open the door and escape! You win!" << endl;
            } else {
                cout << "The door is locked. A shadow looms over you... The ghost gets you!" << endl;
            }
        } else {
            cout << "You hesitate too long. The walls close in, and darkness consumes you!" << endl;
        }
    } else if (choice == 2) {
        cout << "You enter the right path of the hallway, you see a far room open door. You walk towards the room. Do you: " << endl;
        cout << "1. Enter the room\n2. Walk backwards\n";
        cin >> choice;
            
            switch (choice) {
                case 1:
                    cout << "You see a bed & you try to sleep the night. You have nightmares. A ghost appears in the midst of the night and haunts you to death! You meet a gruesome demise." << endl;
                    return;
                case 2:
                    cout << "As you move back you see a window to your right. Someone calls you out. You escape through the window and the person takes you to safety. You win!." << endl;
                    return;
                default:
                    cout << "Invalid choice! The house swallows you whole!" << endl;
                    return;
            }

    } else if (choice == 3) {
        cout << "As you walk around the house, the ground collapses beneath you. You fall into darkness..." << endl;
        cout << "You have met a gruesome demise." << endl;
    } else {
        cout << "Invalid choice! The spirits don't like indecisiveness. You are lost forever!" << endl;
    }
}

int main() {
    hauntedHouseGame();
    return 0;
}
