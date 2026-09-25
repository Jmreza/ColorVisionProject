#include <iostream>
#include <string>
using namespace std;

int main() {

    string name;
    int colorvalue;
    char colordecision;
    char colordecision2;
    char colorstrength;
    char moreInfo;
    bool valuechoice = false;
    bool colorchoice = false;
    bool colorchoice2 = false;
    bool strengthchoice = false;
    bool infochoice = false;


    cout << "What is your name? " << endl;
    getline(cin, name);

do {
        cout << "Please enter the first color you struggle viewing: \n";            
        cout << "(A)ll Colors\n";
        cout << "(R)ed\n";
        cout << "(G)reen\n";
        cout << "(B)lue\n";
        cout << "Enter here: ";
        cin >> colordecision;
            
            if (colordecision == 'A') {
                cout << "Your deficiency is called Monochromacy.\n";
                cout << "You strugge viewing: All color\n";
                cout << "Blind: Complete loss of color\n";
                return 0;
            }

        cout << "Please enter the second color you struggle viewing: \n";
        cout << "(R)ed\n";
        cout << "(G)reen\n";
        cout << "(B)lue\n";
        cout << "Enter here: ";
        cin >> colordecision2;
            
    switch (colordecision) {
        case 'A':
        case 'R':
        case 'G':
        case 'B':
            colorchoice = false;
            break;
        default:
            cout << endl << "Invalid Choice\n";
            colorchoice = true;
            break;
        }
    switch (colordecision2) {
        case 'R':
        case 'G':
        case 'B':
            colorchoice2 = false;
            break;
        default:
            cout << endl << "Invalid Choice\n";
            colorchoice2 = true;
            break;
    }
    if ((colordecision == 'B' && colordecision2 == 'R') || (colordecision == 'R' && colordecision2 == 'B')){
        colorchoice = true;
        cout << "Invalid choice\n";
        cout << "Please enter a valid combination of colors.\n";
    }
    if (colordecision == colordecision2) {
        colorchoice = true;
        cout << "Invalid Choice\n";
        cout << "Please enter 2 different colors\n";
    }
 } while (colorchoice && colorchoice2);

 do {
    cout << "How severe is your color deficiancy: \n";
    cout << "Mild loss(1)\n";
    cout << "Moderate/Severe loss(2)\n";
    cout << "Enter here: ";
    cin >> colorvalue;

    switch (colorvalue){
        case 1:
        case 2:
            valuechoice = false;
            break;
        default:
            cout << "Invalid choice\n";
            colorvalue = 0;
            valuechoice = true;
            break;
    }
} while(valuechoice);

do {
    cout << "Which color are you the weakest to?\n";
    cout << colordecision << " or " << colordecision2 << endl;
    //cout << "(R)ed\n";
    //cout << "(G)reen\n";
    //cout << "(B)lue\n";
    cout << "Enter here: ";
    cin >> colorstrength;
    
    switch (colorstrength) {
        case 'R':
        case 'B':
        case 'G':
            strengthchoice = false;
            break;
        default:
            cout << endl << "Invalid Choice\n";
            strengthchoice = true;
            break;
        }
} while (strengthchoice);

    cout << name << " here are your results: \n";

    if ((colordecision == 'R' || colordecision == 'G') && (colordecision2 == 'R' || colordecision2 == 'G') && colorstrength == 'R' && colorvalue == 1){
        cout << "Your deficiencey is called Protanomaly.\n"; 
        cout << "You struggle viewing: Red, Green, Brown, and Orange.\n";
        cout << "Blind: None";
    }
    if ((colordecision == 'R' || colordecision == 'G') && (colordecision2 == 'R' || colordecision2 == 'G') && colorstrength == 'G' && colorvalue == 1){
        cout << "Your deficency is called Deuteranomaly.\n";
        cout << "You struggle viewing: Red, Green, Brown, and Orange.\n";
        cout << "Blind: None";
    }   
    if ((colordecision == 'R' || colordecision == 'G') && (colordecision2 == 'R' || colordecision2 == 'G') && colorstrength == 'R' && colorvalue == 2){
        cout << "Your deficency is called Protanopia.\n";
        cout << "You struggle viewing: Red, Green, Brown, and Dark Orange.\n";
        cout << "Blind: Red";
    }
    if ((colordecision == 'R' || colordecision == 'G') && (colordecision2 == 'R' || colordecision2 == 'G') && colorstrength == 'G' && colorvalue == 2){
        cout << "Your deficency is called Deuteranopia.\n";
        cout << "You struggle viewing: Red, Green, Brown, and Dark Orange.\n";
        cout << "Blind: Red";
    }
    if ((colordecision == 'B' || colordecision == 'G') && (colordecision2 == 'B' || colordecision2 == 'G') && colorstrength == 'B' && colorvalue == 1){
        cout << "Your deficency is called Tritanomaly.\n";
        cout << "You struggle viewing: Blue, Green, Yellow, and Purple.\n";
        cout << "Blind: None";
    }
    if ((colordecision == 'B' || colordecision == 'G') && (colordecision2 == 'B' || colordecision2 == 'G') && colorstrength == 'B' && colorvalue == 2){
        cout << "Your deficency is called Tritanopia.\n";
        cout << "You struggle viewing: Blue, Green, Yellow, and Purple.\n";
        cout << "Blind: Blue-yellow";
    }
    /*
 do {   
    cout << "Would you like to know more?\n";
    cout << "(Y)es\n";
    cout << "(N)o\n";
    cout << "Enter here: ";
    cin >> moreInfo;

    switch (moreInfo) {
        case 'Y':
        case 'N':
            infochoice = false;
            break;
        default:
            cout << "Invalid choice\n";
            moreInfo = ' ';
            infochoice = true;
            break;
    } 
} while (infochoice);
    */
  return 0;
}
