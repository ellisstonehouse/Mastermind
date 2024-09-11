#include <iostream>
#include <cstdlib>

using namespace std;


class pegBoard {

    private:
        static const char colours[]; // static means all the INSTANCES share this one variables
        char pegs[4];

    public:

        pegBoard() {
            pegs[0] = colours[rand() % 8];
            pegs[1] = colours[rand() % 8];
            pegs[2] = colours[rand() % 8];
            pegs[3] = colours[rand() % 8];
        }

        bool guess(string g) {

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
            cout << "pegs: " << pegs << endl;
        }

};

const char pegBoard::colours[] = {'R', 'G', 'B', 'C', 'M', 'Y', 'B', 'W'};



int main() {

    srand(time(NULL));

    pegBoard* board = new pegBoard();

    string pegGuess;

    int round=1;

    do {
        cout << "Round " << round++ << ": " << endl;
        cin >> pegGuess;
    }
    while (!board->guess(pegGuess));


    board->printPegs();

    delete board;

    return 0;
}