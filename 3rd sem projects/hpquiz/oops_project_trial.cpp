#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
 // for setw
using namespace std;

// -------------------------
// CLASS: Question
// -------------------------
class Question {
private:
    string text;
    string options[4];
    int charMap[4]; // maps option index -> character index (0..9)

public:
    void setQuestion(const string& t,
                     const string& o1, const string& o2, const string& o3, const string& o4,
                     int c1, int c2, int c3, int c4)
    {
        text = t;
        options[0] = o1; options[1] = o2; options[2] = o3; options[3] = o4;
        charMap[0] = c1; charMap[1] = c2; charMap[2] = c3; charMap[3] = c4;
    }

    void display(int qNo) const {
        cout << "\n" << qNo << ". " << text << "\n";
        for (int i = 0; i < 4; ++i) {
            cout << "  " << (char)('A' + i) << ". " << options[i] << "\n";
        }
    }

    // Return character index (0..9) for a valid choice 1..4
    int getCharacterIndex(int choice) const {
        if (choice >= 1 && choice <= 4) return charMap[choice - 1];
        return -1;
    }
};

// -------------------------
// CLASS: Quiz
// -------------------------
class Quiz {
private:
    Question questions[20];
    int totalQuestions;
    int counters[10]; // counts for each character

    string characterNames[10];

public:
    Quiz() {
        totalQuestions = 20;
        for (int i = 0; i < 10; ++i) counters[i] = 0;

        characterNames[0] = "Harry Potter";
        characterNames[1] = "Hermione Granger";
        characterNames[2] = "Ron Weasley";
        characterNames[3] = "Draco Malfoy";
        characterNames[4] = "Neville Longbottom";
        characterNames[5] = "Dobby";
        characterNames[6] = "Severus Snape";
        characterNames[7] = "Rubeus Hagrid";
        characterNames[8] = "Luna Lovegood";
        characterNames[9] = "Albus Dumbledore";
    }

    void loadQuestions() {
        // Questions 1..20 (kept wording & tone as provided, with light grammar fixes)
        questions[0].setQuestion(
            "You find a secret door in Hogwarts that no one else knows about. What do you do?",
            "Enter immediately, adventure awaits!", "Study it carefully for clues first.",
            "Ask your friends if they want to explore together.", "Warn others, it could be dangerous.",
            0, 1, 2, 4 // Harry, Hermione, Ron, Neville
        );

        questions[1].setQuestion(
            "It's a Hogsmeade weekend! What's your plan?",
            "Butterbeer with friends at Three Broomsticks.", "Bookshop visit! so many magical texts!",
            "Exploring hidden paths around the village.", "Buying treats for your pet creatures.",
            2, 1, 8, 7 // Ron, Hermione, Luna, Hagrid
        );

        questions[2].setQuestion(
            "If you could own one magical object, what would it be?",
            "Invisibility Cloak.", "Time Turner.", "Marauder's Map.", "Elder Wand.",
            0, 1, 2, 9 // Harry, Hermione, Ron, Dumbledore
        );

        questions[3].setQuestion(
            "A boggart appears before you, what form does it take?",
            "Failing an exam.", "Losing your best friend.", "Public embarrassment.",
            "Someone disrespecting your freedom.",
            1, 0, 2, 5 // Hermione, Harry, Ron, Dobby
        );

        questions[4].setQuestion(
            "You're asked to teach a first-year class. What do you teach?",
            "Magical Creatures 101.", "Theories of Time and Magic.",
            "Defensive Spells for Beginners.", "The Importance of Free Elves.",
            7, 9, 0, 5 // Hagrid, Dumbledore, Harry, Dobby
        );

        questions[5].setQuestion(
            "You're invited to the Yule Ball. Who do you go with?",
            "Someone brave who makes you laugh.", "Someone who shares your values.",
            "Someone mysterious and charming.", "Someone unique, who truly gets you.",
            0, 1, 3, 8 // Harry, Hermione, Draco, Luna
        );

        questions[6].setQuestion(
            "If you had to choose a Patronus, what would it be?",
            "A Stag - loyal protector.", "An Otter - smart and graceful.",
            "A Terrier - playful and brave.", "A Doe - calm yet powerful.",
            0, 1, 2, 6 // Harry, Hermione, Ron, Snape
        );

        questions[7].setQuestion(
            "Someone asks your opinion about Muggles. How do you respond?",
            "\"They're fascinating, we can learn from them.\"", "\"They're okay, as long as they're kind.\"",
            "\"They're not on our level.\"", "\"Everyone deserves respect and socks!\"",
            1, 7, 3, 5 // Hermione, Hagrid, Draco, Dobby
        );

        questions[8].setQuestion(
            "You're brewing Amortentia, the love potion. What scent do you smell?",
            "Fresh parchment and new books.", "The smell of the Quidditch field.",
            "Campfire smoke and treacle tart.", "Old potions and lilies.",
            1, 0, 2, 6 // Hermione, Harry, Ron, Snape
        );

        questions[9].setQuestion(
            "Snape gives you detention, what did you do?",
            "Talked back during class.", "Blew up a potion by accident.",
            "Defended your friend from an insult.", "Tried to prank someone and got caught.",
            0, 4, 2, 3 // Harry, Neville, Ron, Draco
        );

        questions[10].setQuestion(
            "Which gift would you treasure most?",
            "A homemade sweater from Mrs. Weasley.", "A beautifully bound spellbook.",
            "A rare magical plant.", "A pair of free elf socks!",
            2, 1, 4, 5 // Ron, Hermione, Neville, Dobby
        );

        questions[11].setQuestion(
            "You find out someone is secretly trying to protect you. What is your reaction?",
            "Feel deeply touched but say nothing.", "Become emotional and grateful.",
            "Act annoyed, but appreciate it inside.", "Feel inspired and want to protect them too.",
            6, 5, 3, 4 // Snape, Dobby, Draco, Neville
        );

        questions[12].setQuestion(
            "Where would you spend most of your free time at Hogwarts?",
            "The dungeons, in quiet isolation.", "The Forbidden Forest, with magical beasts.",
            "The astronomy tower, staring at the sky.", "The Slytherin common room, planning your future.",
            6, 7, 8, 3 // Snape, Hagrid, Luna, Draco
        );

        questions[13].setQuestion(
            "Your friend is feeling left out. What do you do?",
            "Give them a gift you made yourself.", "Sit with them and say something uplifting.",
            "Try to make them feel brave and included.", "Awkwardly pat them on the shoulder and offer a creature story.",
            5, 8, 4, 7 // Dobby, Luna, Neville, Hagrid
        );

        questions[14].setQuestion(
            "You find a strange creature hiding in the Forbidden Forest. What is your first instinct?",
            "Try to understand its nature.", "Protect it immediately.", "Run away nervously.",
            "Capture it to show superiority.",
            8, 7, 4, 3 // Luna, Hagrid, Neville, Draco
        );

        // New questions that you approved earlier (kept mapping)
        questions[15].setQuestion(
            "You discover a hidden classroom that teaches a forgotten branch of magic. What do you do?",
            "Jump in excitedly and try the first spell you see.", "Read all the notes carefully before touching anything.",
            "Call your friends so you can explore it together.", "Inform a professor, this could be dangerous.",
            0, 1, 2, 4 // Harry, Hermione, Ron, Neville
        );

        questions[16].setQuestion(
            "You win a mysterious enchanted quill. What ability would you want it to have?",
            "Writing homework on its own.", "Revealing hidden magical knowledge.",
            "Drawing detailed maps of secret Hogwarts passages.", "Sending comforting notes to lonely students.",
            2, 9, 0, 8 // Ron, Dumbledore, Harry, Luna
        );

        questions[17].setQuestion(
            "A young first-year asks you for guidance. What advice do you give?",
            "\"Be brave - even when you're scared.\"", "\"Knowledge is your greatest spell.\"",
            "\"Stay true to your friends.\"", "\"Kindness makes magic stronger.\"",
            4, 1, 2, 5 // Neville, Hermione, Ron, Dobby
        );

        questions[18].setQuestion(
            "You receive a special invite to a private spell-casting session. Who do you hope the mentor is?",
            "The greatest duelist you admire.", "A wise scholar with ancient knowledge.",
            "A fun, adventurous witch or wizard.", "Someone quirky and open-minded.",
            6, 9, 7, 8 // Snape, Dumbledore, Hagrid, Luna
        );

        questions[19].setQuestion(
            "Your House assigns you a special mission. What do you want it to involve?",
            "A daring adventure outside the castle.", "Solving a complex magical puzzle.",
            "Helping a friend overcome a challenge.", "Investigating a mysterious enchanted object.",
            0, 1, 2, 9 // Harry, Hermione, Ron, Dumbledore
        );
    }

    void start() {
        cout << "=== Hogwarts Personality Quiz ===\n";
        cout << "Answer the questions by typing the option number (1-4).\n";

        for (int i = 0; i < totalQuestions; ++i) {
            questions[i].display(i + 1);

            int choice = 0;
            while (true) {
                cout << "Enter choice (1-4): ";
                if (!(cin >> choice)) {
                    cin.clear();
                    string tmp;
                    getline(cin, tmp); // flush
                    cout << "Invalid input. Please enter a number between 1 and 4.\n";
                    continue;
                }
                if (choice < 1 || choice > 4) {
                    cout << "Please enter a number between 1 and 4.\n";
                    continue;
                }
                break;
            }

            int charIdx = questions[i].getCharacterIndex(choice);
            if (charIdx >= 0 && charIdx < 10) counters[charIdx]++;
        }
    }

    int findWinnerIndex() const {
        int maxVal = counters[0];
        for (int i = 1; i < 10; ++i) if (counters[i] > maxVal) maxVal = counters[i];

        int winners = 0;
        int lastWinner = -1;
        for (int i = 0; i < 10; ++i) {
            if (counters[i] == maxVal) {
                winners++;
                lastWinner = i;
            }
        }

        if (winners == 1) return lastWinner;
        return -1; 
    }

    void showResult() const {
        cout << "\n=== Results ===\n";
        // Print counts (optional, helpful for debugging / transparency)
        cout << "Character scores:\n";
        for (int i = 0; i < 10; ++i) {
            cout << setw(18) << left << characterNames[i] << " : " << counters[i] << "\n";
        }

        int winner = findWinnerIndex();
        if (winner != -1) {
            cout << "\nYour best match: " << characterNames[winner] << "!\n";
            displayDescription(winner);
        } else {
            // Tie handling: collect all with max value
            int maxVal = counters[0];
            for (int i = 1; i < 10; ++i) if (counters[i] > maxVal) maxVal = counters[i];

            cout << "\nIt's a tie! You show traits of multiple characters:\n";
            for (int i = 0; i < 10; ++i) {
                if (counters[i] == maxVal) {
                    cout << " - " << characterNames[i] << "\n";
                }
            }
            cout << "\nYou might be a mix of those personalities - unique and interesting!\n";
        }
    }

    void displayDescription(int idx) const {
        // Short flavor descriptions (you can adjust)
        cout << "\nPersonality snapshot:\n";
        switch (idx) {
            case 0:
                cout << "Harry: Brave, loyal, and quick to act when needed.\n"; break;
            case 1:
                cout << "Hermione: Intelligent, diligent, and always prepared.\n"; break;
            case 2:
                cout << "Ron: Warm, loyal, and great at cheering others up.\n"; break;
            case 3:
                cout << "Draco: Ambitious, proud, and strategic.\n"; break;
            case 4:
                cout << "Neville: Quietly brave, caring, and steadily growing.\n"; break;
            case 5:
                cout << "Dobby: Kind-hearted, selfless, and fiercely loyal.\n"; break;
            case 6:
                cout << "Snape: Serious, intense, and deeply principled.\n"; break;
            case 7:
                cout << "Hagrid: Gentle, hearty, and wholeheartedly caring for creatures.\n"; break;
            case 8:
                cout << "Luna: Eccentric, open-minded, and wonderfully insightful.\n"; break;
            case 9:
                cout << "Dumbledore: Wise, enigmatic, and ever-guiding.\n"; break;
            default:
                cout << "Unknown.\n"; break;
        }
    }
};

int main() {
    // Optional: clear any leading newline issues
    cin.sync();

    Quiz quiz;
    quiz.loadQuestions();
    quiz.start();

    quiz.showResult();

    cout << "\nThanks for playing! Press Enter to exit...";
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cin.get();
    return 0;
}

