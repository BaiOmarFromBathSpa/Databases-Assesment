#include <iostream>
#include <string>

using namespace std;



int main() {
    while (true) {
    string SUB = "SUBSTITUTE(";
    string Output = "=";
    string RangeCompare, RangeReplace, RangeTarget; // compare is the range of values its being compared to, replace is what values to replace with, target is the range of values to replace
    
    cout << "Input Data in format [ =(Target Range), (Compare Range), (Replace Range) ] where:\nTarget Range - The range of values that need to be Replaced\nCompare Range - The range of values \'Target Range\' is being Compared to\nReplace Range - The range of values that are being Substituted In if found (Range needs to be the same length as compare)\n\nInput Data: ";
    getline(cin, RangeTarget, ',');
    
    if(RangeTarget[0] == '=')
        RangeTarget.erase(0,1);
    
    //second bit
    getline(cin, RangeCompare, ',');
    
    string CompStr = "", TempNum = ""; //Range string - letter coordinate
    bool usingCompStart = true; 
    int RCStart, RCEnd; //Start and End integers - replace compare start
    
    for (int i = 0; i < RangeCompare.length(); i++) {
        if (RangeCompare[i] == ':') {
            RCStart = stoi(TempNum);
            TempNum = "";
            usingCompStart = false;
            continue;
        }
        else if (usingCompStart && RangeCompare[i] >= 'A' && RangeCompare[i] <= 'Z'){
            CompStr += RangeCompare[i];
        } else if (RangeCompare[i] >= '0' && RangeCompare[i] <= '9'){
            TempNum += RangeCompare[i];
        }
        if (RangeCompare.length() == i+1 && usingCompStart == false){
            RCEnd = stoi(TempNum);
        }
    }
    
    //third bit
    string RepStr = ""; //Range Start to range end strings
    bool usingRepStart = true;
    
    getline(cin, RangeReplace);
    
    for (int i = 0; i < RangeReplace.length(); i++) {
        if (RangeReplace[i] >= 'A' && RangeReplace[i] <= 'Z'){
            RepStr += RangeReplace[i];
        }
        else if (RangeReplace[i] >= '0' && RangeReplace[i] <= '9'){
            break;
        }
    }
    
    for (int i = RCStart; i <= RCEnd; i++) Output += SUB;
    Output += (RangeTarget + ',');
    for (int i = RCEnd; i >= RCStart; i--) {
        string CurrIt = to_string(i);
        
        Output += (CompStr + CurrIt + ',');
        Output += (RepStr + CurrIt + "),");
    }
    Output.erase(Output.length()-1,1);
    
    // input format
    //=D3:D14,B3:B6,A3:A6
    // output format
    //=SUBSTITUTE(SUBSTITUTE(SUBSTITUTE(SUBSTITUTE(D3:D14,B3,A3),B4,A4),B5,A5),B6,A6)
    cout << "reached end :D" << endl;
    cout << Output << "\n\n\n" << endl;
    }
}