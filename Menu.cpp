#include <iostream>
#include <limits>
#include <cstdlib> // system()
using namespace std;

//==================== MENU VISUALS & STRUCTURE ====================//

void printValhallaHeader() {
    cout << "\n========================================\n";
    cout << "   🛡️ VIKINGS OF THE VOID: BATTLE FOR VALHALLA ⚔️\n";
    cout << "========================================\n";
}

void pauseForEnter() {
    cout << "\nPress Enter to return to the main console...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

void displayLore() {
    system("CLS");
    printValhallaHeader();
    cout << "📜 LEGEND OF VALHALLA\n";
    cout << "In a galaxy ruled by steel and starfire, the ancient spirit of the Norse has risen again.\n"
         << "You are a commander in the Vikings of the Void fleet—tasked to conquer, protect, and ascend.\n"
         << "Ships like Karvi, Skeid, and Drakkar await your command. Battle rages across the stars...\n"
         << "Do you have the might to lead your warriors to glory and uncover the secrets of Valhalla?\n";
    pauseForEnter();
}

void displayHowToPlay() {
    system("CLS");
    printValhallaHeader();
    cout << "🎮 HOW TO COMMAND:\n"
         << "- View the opponent’s fleet for 3 seconds.\n"
         << "- Select (X,Y) coordinates to fire your star cannons.\n"
         << "- Earn Valhallan gold by making hits and sinking enemy ships.\n"
         << "- Spend it on deadly upgrades: orbital strikes, perfect shots, and more!\n";
    pauseForEnter();
}

void displayCredits() {
    system("CLS");
    printValhallaHeader();
    cout << "🧠 CODE BY ODIN'S WILL\n"
         << "- Developer: YourName\n"
         << "- Concept: Viking Sci-Fi Lore\n"
         << "- Framework: C++ + Imagination + Norse Steel\n";
    pauseForEnter();
}

bool confirmValhallaExit() {
    char answer;
    cout << "\nAre you sure you want to return to Midgard? (Y/N): ";
    cin >> answer;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clean buffer
    return (toupper(answer) == 'Y');
}

int valhallaMenu() {
    int choice = 0;
    int attempts = 0;

    do {
        system("CLS");
        printValhallaHeader();
        cout << "1. 🚀 Begin the Battle for Valhalla\n";
        cout << "2. 🏅 Hall of Fallen Warlords (Top 10 Scores)\n";
        cout << "3. 📖 Viking Codex (How to Play / Lore)\n";
        cout << "4. 👋 Return to Midgard (Exit)\n";
        cout << "----------------------------------------\n";
        cout << "Enter your command (1-4): ";
        cin >> choice;

        if (cin.fail() || choice < 1 || choice > 4) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "⚠️ Invalid input. That command is not recognized by the gods.\n";
            attempts++;
            system("pause");
            if (attempts >= 3) return 4;
        } else if (choice == 3) {
            int codexChoice;
            do {
                system("CLS");
                printValhallaHeader();
                cout << "📖 Viking Codex Menu\n";
                cout << "1. Read the Legend (Lore)\n";
                cout << "2. Learn to Command (Controls)\n";
                cout << "3. Return to War Console\n";
                cout << "------------------------------\n";
                cout << "Select an entry: ";
                cin >> codexChoice;
                switch (codexChoice) {
                    case 1: displayLore(); break;
                    case 2: displayHowToPlay(); break;
                }
            } while (codexChoice != 3);
        } else if (choice == 4 && !confirmValhallaExit()) {
            choice = 0;
        }

    } while (choice < 1 || choice > 4);

    return choice;
}

//==================== MAIN GAME SIMULATION ====================//

void startBattle() {
    system("CLS");
    printValhallaHeader();
    cout << "\n⚔️  Initializing Fleet... Prepare for interstellar war!\n";
    // Simulate gameplay logic here
    pauseForEnter();
}

void topTen() {
    system("CLS");
    printValhallaHeader();
    cout << "\n🏅 Hall of Fallen Warlords (Top Scores):\n";
    cout << "1. Ragnar  - 4500 VP\n2. Freya   - 4200 VP\n3. Odin    - 3900 VP\n";
    pauseForEnter();
}

void EXIT() {
    system("CLS");
    printValhallaHeader();
    cout << "\n👋 The stars dim as you return to Midgard. Farewell, warrior.\n";
    exit(0);
}

//==================== PROGRAM ENTRY POINT ====================//

int main() {
    int menuSelection;

    do {
        menuSelection = valhallaMenu();

        switch (menuSelection) {
            case 1:
                startBattle();
                break;
            case 2:
                topTen();
                break;
            case 3:
                // Already handled inside menu
                break;
            case 4:
                EXIT(); // exits program
                break;
        }

    } while (menuSelection != 4);

    return 0;
}
