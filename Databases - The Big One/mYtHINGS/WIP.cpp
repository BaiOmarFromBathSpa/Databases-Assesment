#include <iostream>

using namespace std;

int main() {

    //=SUBSTITUTE(SUBSTITUTE(SUBSTITUTE(SUBSTITUTE(D3:D14,B3,A3),B4,A4),B5,A5),B6,A6)

    string SUB = "SUBSTITUTE(";
    string output = "=";
    int lines, replacements,cellStart, repStart;
    string cellStartStr, repStartStr;

    cout << "How many lines are you replacing?";
    cin >> lines;
    cout << "How many replacements are you there?";
    cin >> replacements;
    cout << "Which cell are you replacing?\n";
    cout << "Cell Letter: ";
    cin >> cellStartStr;
    cout << "Cell Number: ";
    cin >> cellStart;
    cout << "Where is the topmost replacement example\n";
    cout << "Replacement Cell Letter: ";
    cin >> repStartStr;
    cout << "Replacement Cell Number: ";
    cin >> repStart;

    for (int i = 0; i < replacements; i++)
        output = output + SUB;
    output = output + cellStartStr;
    output = output + to_string(cellStart);
    output = output + ":";
    output = output + cellStartStr;
    output = output + to_string(cellStart+lines-1);
    output = output + ",";

    for (int i = 0; i < replacements; i++){
        string leftside = repStartStr;
        leftside [leftside.length()-1] = leftside[leftside.length()-1] - 1;
        output = output + repStartStr;
        output = output + to_string(repStart);
        output = output + ",";
        output = output + leftside;
        output = output + to_string(repStart);
        output = output + ")";

        if (replacements == i-1) {
            output = output + ",";
            repStart++;
        }
    }

    cout << output << endl;;
    return 0;
}
