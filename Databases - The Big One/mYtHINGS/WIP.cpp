#include <iostream>
#include <string>

using namespace std;



int main() {
    string SUB = "SUBSTITUTE(";
    string Output = "=";
    string RangeCompare, RangeReplace, RangeTarget; // compare it what its being compared to, replace is what values to replace with, target is
    // string UserInput = "D3:D14,B3:B6,A3:A6"
    
    getline(cin, RangeTarget, ',');
    
    if(RangeTarget[0] == '=')
        RangeTarget.erase(0,1);
    
    //second bit
    getline(cin, RangeCompare, ',');
    
    string CompStart = "", CompEnd = "", TempNum = ""; //Range Start to range end strings
    bool usingCompStart = true; 
    int iCompStart, iCompEnd; //Range Start to range end integers
    
    for (int i = 0; i < RangeCompare.length(); i++) {
        if (RangeCompare[i] == ':') {
            iCompStart = stoi(TempNum);
            TempNum = "";
            continue;
        }
        else if (RangeCompare[i] >= 'A' && RangeCompare[i] <= 'Z'){
            (usingCompStart) ? CompStart += RangeCompare[i] : CompEnd += RangeCompare[i];
        } else if (RangeCompare[i] >= '0' && RangeCompare[i] <= '9'){
            TempNum += RangeCompare; 
        }
        if (RangeCompare.length() == i-1 && usingCompStart == false){
            iCompEnd = stoi(TempNum);
        }
    }
    
    //third bit
    string RepStart = "", RepEnd = ""; //Range Start to range end strings
    bool usingRepStart = true; 
    int iRepStart, iRepEnd;
    TempNum = "";
    
    getline(cin, RangeReplace);
    
    for (int i = 0; i < RangeReplace.length(); i++) {
        if (RangeReplace[i] == ':') {
            iRepStart = stoi(TempNum);
            TempNum = "";
            continue;
        }
        else if (RangeReplace[i] >= 'A' && RangeReplace[i] <= 'Z'){
            (usingRepStart) ? RepStart += RangeCompare[i] : RepEnd += RangeCompare[i];
        }
        else if (RangeReplace[i] >= '0' && RangeReplace[i] <= '9'){
            TempNum += RangeReplace; 
        }
        if (RangeReplace.length() == i-1 && usingRepStart == false){
            iRepEnd = stoi(TempNum);
        }
    }
    
    // input format
    //=D3:D14,B3:B6,A3:A6
    // output format
    //=SUBSTITUTE(SUBSTITUTE(SUBSTITUTE(SUBSTITUTE(D3:D14,B3,A3),B4,A4),B5,A5),B6,A6)
}
