#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Card structure for linked list
struct Card {
    char value;
    bool matched;
    Card* next;
};

// Stack to hold flipped cards
struct Stack {
    Card* data[2];
    int top = 0;
};

// Create deck with N pairs (2N cards)
Card* createDeck(int pairCount) {
    Card* head = nullptr;
    char ch = 'A';
    for (int i = 0; i < pairCount; i++) {
        for (int j = 0; j < 2; j++) {
            Card* newCard = new Card{ch, false, head};
            head = newCard;
        }
        ch++;
    }
    return head;
}

// Shuffle deck by swapping values
void shuffleDeck(Card* head, int size) {
    srand(time(0));
    for (int i = 0; i < size; i++) {
        int r = rand() % size;
        Card* a = head;
        Card* b = head;
        for (int j = 0; j < i; j++) a = a->next;
        for (int j = 0; j < r; j++) b = b->next;
        swap(a->value, b->value);
    }
}

// Map linked list to array for indexing
void mapToArray(Card* head, Card* board[], int size) {
    Card* temp = head;
    for (int i = 0; i < size; i++) {
        board[i] = temp;
        temp = temp->next;
    }
}

// Display board with hidden/matched cards
void displayBoard(Card* board[], int size) {
    for (int i = 0; i < size; i++) {
        if (board[i]->matched)
            cout << "[" << board[i]->value << "] ";
        else
            cout << "[" << i + 1 << "] ";
    }
    cout << endl;
}

// Flip a card and push to stack
void flipCard(int index, Stack &s, Card* board[]) {
    if (s.top < 2) {
        s.data[s.top++] = board[index];
        cout << "Flipped: " << board[index]->value << endl;
    }
}

// Check if flipped cards match
bool checkMatch(Stack &s) {
    if (s.data[0]->value == s.data[1]->value) {
        s.data[0]->matched = true;
        s.data[1]->matched = true;
        return true;
    }
    return false;
}

// Reset stack after each turn
void resetStack(Stack &s) {
    s.top = 0;
}

// Check if all cards are matched
bool allMatched(Card* board[], int size) {
    for (int i = 0; i < size; i++) {
        if (!board[i]->matched) return false;
    }
    return true;
}

// Main game loop
int main() {
    cout<<"Welcome to Memory Match Game!\n";
    cout<<"Flip the cards to match the alphabets\n";
    int n;
    cout<<"Enter the number of pairs you want to play with : ";
    cin>>n;
    if(n < 3 || n > 12){
        cout<<"Invalid Input\n";
        cout<<"Please play with no less than 3 pairs and no more than 12 pairs.\n";
        return 1;
    }
    int pairCount = n;
    int size = pairCount * 2;
    Card* deck = createDeck(pairCount);
    shuffleDeck(deck, size);
    Card** board = new Card*[size];
    mapToArray(deck, board, size);

    Stack stack;
    int score = 0;

    while (!allMatched(board, size)) {
        displayBoard(board, size);
        int i1, i2;
        cout << "Enter two positions to flip (1-" << size << "): ";
        cin >> i1 >> i2;

        // Validate input
        if (i1 < 1 || i1 > size || i2 < 1 || i2 > size || i1 == i2 || board[i1 - 1]->matched || board[i2 - 1]->matched) {
            cout << "Invalid input. Try again.\n";
            continue;
        }

        flipCard(i1 - 1, stack, board);
        flipCard(i2 - 1, stack, board);

        if (checkMatch(stack)) {
            cout << "Match found!\n\n";
            score++;
        } else {
            cout << "No match. Try again.\n";
        }

        resetStack(stack);
    }

    cout << "All pairs matched! Final Score: " << score << endl;
    return 0;
}
