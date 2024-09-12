#include <iostream>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include <iomanip>

using namespace std;


class pegBoard {

    private:
        char pegs[4];

    public:
        static const char colours[8]; // static means all the INSTANCES share this one variables

        pegBoard() {
            pegs[0] = colours[rand() % 8];
            pegs[1] = colours[rand() % 8];
            pegs[2] = colours[rand() % 8];
            pegs[3] = colours[rand() % 8];
        }

        bool guess(string g) {

            int count=0;

            for (char ele : colours) {
                if (g[0] == ele) {
                    count++;
                }
                if (g[1] == ele) {
                    count++;
                }
                if (g[2] == ele) {
                    count++;
                }
                if (g[3] == ele) {
                    count++;
                }
            }

            if (count != 4) {
                cout << "Error! Invalid guess\n";
                return false;
            }

            int X=0, O=0;

            if (pegs[0] == g[0]) {
                X++;
            } else if (pegs[0] == g[1] || pegs[0] == g[2] || pegs[0] == g[3]) {
                O++;
            }
            if (pegs[1] == g[1]) {
                X++;
            } else if (pegs[1] == g[2] || pegs[1] == g[3] || pegs[1] == g[0]) {
                O++;
            }
            if (pegs[2] == g[2]) {
                X++;
            } else if (pegs[2] == g[3] || pegs[2] == g[0] || pegs[2] == g[1]) {
                O++;
            }
            if (pegs[3] == g[3]) {
                X++;
            } else if (pegs[3] == g[0] || pegs[3] == g[1] || pegs[3] == g[2]) {
                O++;
            }

            for (int i=0; i<X; i++) {
                cout << 'X';
            }
            for (int i=0; i<O; i++) {
                cout << 'O';
            }
            for (int i=0; i<4-X-O; i++) {
                cout << '-';
            }
            cout << endl;

            if (X==4) {
                return true;
            }
            else {
                return false;
            }
        }

        void printPegs() {
            cout << "Answer: " << pegs << endl;
        }

};

const char pegBoard::colours[8] = {'R', 'G', 'B', 'C', 'M', 'Y', 'K', 'W'};



int main() {

    cout << "Enter Player Name: ";
    string name;
    getline(cin, name);

    srand(time(NULL));

    pegBoard* board = new pegBoard();

    string pegGuess;

    cout << "\nPeg colours availible:  ";
    for (char colour : board->colours) {
        cout << colour << ", ";
    }
    cout << endl;

    board->printPegs();

    int round=0;
    do {
        cout << "Round " << ++round << ": " << endl;
        cin >> pegGuess;
    }
    while (!board->guess(pegGuess));

    board->printPegs();

    delete board;

    time_t currentTime = time(NULL);

    ofstream file("leaderboard.txt", ios::app);

    file << left << setw(20) << name.substr(0, 20) << " | ";
    file << right << setw(5) << round << " | ";
    file << ctime(&currentTime);

    file.close();

    return 0;
}