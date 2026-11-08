#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>
#include <fstream>

using namespace std;

bool valid_Analyze(int r, int g, int b, string& result); // Checks if the RGB values are correct and returns a result as a bool
void resultList(const vector <string>& pastInfo); // Updates all the users past results and displays in a nubered list

int main(){
    string username;
    string result = " ";
    string input; // Used to track user input with its main function
    vector <string> pastInfo; // Stores all results from the users interaction
    char understand;
    int r = 0, g = 0, b = 0; // RGB values

    cout << "Please enter your name: "; // Prompts user for their name
    getline(cin, username);

    cout << "Hello " << username << "! Let's analyze some color combinations using RGB values!\n";
    
    do{
        cout << "Do you understand the format of an RGB(R/G/B) value(Y/N)?\n"; // Checks the users understanding of an RGB value
        cin >> understand;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clears past input until a new line '\n'

        switch (understand){ // Will provide a description of an RGB value if user answers 'N'/'n'
            case 'Y':
            case 'y':   
                cout << "Great! Let's get started.\n"; 
                break;
            case 'N':
            case 'n':
                cout << " - An RGB value consists of 3 different numbers that are between 0 and 255.\n";
                cout << " - Each number correlates to a letter of the word RGB that make up the 3 primary colors.\n";
                cout << " - The first number of and RGB value correlates to Red(R), then the second is Green(G), and lastly is Blue(B).\n";
                cout << " - For each letter that contains a high value, it means that your color contains a lot of that primary color.\n";
                cout << " - Likewise, each letter that contains a low value, it means that your color contains few amounts of that primary color.\n";
                break;
            default: // Checks for invalid input
                cout << "Invalid input. Please enter either yes(Y) or no(N).\n";
        }
    }while(understand != 'Y' && understand != 'y' && understand != 'N' && understand != 'n'); // End the loop when user inputs a valid input

    while(true){
        
        cout << "Please proceed and choose by typing 'continue', 'results', 'file', or 'quit'.\n"; // Promts user for main interaction of program
        cin >> input;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clears past input until a new line '\n'

        if(input == "Quit" || input == "quit"){ // Checks user input
            cout << "You have quit the program, thank you for your time!\n";
            cout << "Here are your final results! \n";
            resultList(pastInfo); // Calls 'resultList' function using 'pastInfo' vector
            
            if (!pastInfo.empty()) { // Checks if user has any past/current data
                ofstream writer("color_analysis_report.txt"); // Opens file in order to write into it
                if (writer.is_open()) { // Checks if file is open and begins writing into the file
                    writer << "========================================\n";
                    writer << "Color Analysis Report for User: " << username << "\n";
                    writer << "========================================\n";
                    for (size_t i = 0; i < pastInfo.size(); i++) { // Writes into opened file with data from 'pastInfo' vector 
                        writer << i + 1 << ". " << pastInfo.at(i) << "\n";
                    }
                    writer.close(); // Closes file
                    cout << "Your final results successfully saved to 'color_analysis_report.txt'!\n";
                }
            }
            return 0; // Ends program after writing results into file and user entered 'Quit'/'quit'
        }
        else if(input == "File" || input == "file"){ // Checks user input
            string fileName;

            cout << "Enter the file name: \n"; // Prompts user for file name
            cin >> fileName; 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clears past input until a new line '\n'
            
            ifstream reader(fileName); // Opens given file name

            if(!reader.is_open()){ // Error message if file cannot open
                cout << "Could not open file '" << fileName << "'. Please check the name and try again!\n"; 
            } 
            else{ 
                int fileR = 0, fileG = 0, fileB = 0; // Reads file RGB values
                int successfulReads = 0; // Counts how many lines have given back a result
                int lineCount = 0; // Counts how many lines have been read

                while (reader >> fileR >> fileG >> fileB){ // Reads into file for RGB values
                    
                    lineCount++; 

                    if (valid_Analyze(fileR, fileG, fileB, result)){ // Checks if function can true
                        pastInfo.push_back(result); // Pushes a result of the file data into 'pastInfo' vector
                        successfulReads++; 
                    } 
                    else{ 
                        cout << "Line '" << lineCount << "' was skipped. Values out of range (0-255)!\n"; // Helps user find RGB value errors in their file
                    }
                } 
               
                if(!reader.eof() && reader.fail()) { 
                    lineCount++;
                    cout << "Line '" << lineCount << "' was skipped due to a formatting error (letters/symbols found).\n"; // Helps user find formatting errors within their file
                    reader.clear(); 
                    reader.ignore(numeric_limits<streamsize>::max(), '\n'); // Clears past input until a new line '\n'
                }
                
                cout << "Successfully processed '" << successfulReads << "' color combination(s) from the file!\n"; // Signifies end file
                reader.close(); // Closes file
            }
        }  
       
        else if(input == "Continue" || input == "continue"){ // Checks user input

            cout << "Enter Red value (0-255): \n"; // Prompts user for red RGB value
            cin >> r;
            cout << "Enter Green value (0-255): \n"; // Promts user for green RGB vaue
            cin >> g;
            cout << "Enter Blue value (0-255): \n"; // Promts user for blue RGB value
            cin >> b;

            if (cin.fail()) { // Checks for cin error
                cout << "Please enter numbers only, not letters or symbols.\n\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clears past input until a new line '\n'
                continue;
            }

            if (valid_Analyze(r, g, b, result)){ // Checks if function can return true
                cout << "Here are your results! " << result << endl; 
                pastInfo.push_back(result); // Pushes a result of the users data into 'pastInfo' vector
            }
            else{
                cout << "Invalid RGB values, please try again.\n"; // Helps user correct their improper input
            }
        }
        else if(input == "Results" || input == "results"){ // Checks user input
            if(!pastInfo.empty()){ // Checks if vector is empty
                cout << "Here are your current results! \n";
                resultList(pastInfo); // Calls 'resultList' function using 'pastInfo' vector
            }
            else{
                cout << "You have no information stored. Please try again and type 'continue'!\n"; // Helps direct user to input 'continue' 
            }
        }
        else{
            cout << "Unexpected output. Please enter a correct input.\n"; // Error mesage if incorrect input
        }
    }
}

    bool valid_Analyze(int r, int g, int b, string& result){ // Returns true if RGB values are within 0 - 255
        if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255) { // Checks if RGB values are within range of 0 - 255
        return false; 
        }

        float maxVal = max({r, g, b}); // Finds the largest RGB value
        float minVal = min({r, g, b}); // Finds the smallest RGB value
        float delta = maxVal - minVal; // Difference between the largest and smallest RGB value
        float brightness = (r + b + g) / 3.0f; // Brightness is the average value of the 3 RBG values

        if (delta < 25){ // Checks if delta is less than 25
            if (maxVal > 200){ // Checks if the largest RGB is less larger than 200
                result = "Palette: Grayscale (White/Light Gray) - High visibility.";
            } 
            else if (maxVal < 50){ // Checks if smallest RGB value is less than 50
                result = "Palette: Grayscale (Black/Dark Gray) - High contrast text safe.";
            } 
            else{
                result = "Palette: Grayscale (Mid-tone Gray) - Moderate contrast.";
            }
        }
        else if (r > 150 && b > 150 && g < 120 && abs(r - b) < 50){ // Checks if red & blue are greater than 150, green is less than 120, and the difference of red and blue is less than 50
            result = "Palette: Magenta/Purple - Vibrant high-contrast tone.";
        }
        else if (brightness > 170 && delta < 100){ // Checks is brightness is greater than 170 and delta is less than 100
            result = "Palette: Pastel - Soft tone with high brightness.";
        }
        else if (r >= g && g >= b){ // Checks if red is the largest number and green is the second largest
            if (g < 100 && r > 150){ // Checks if green is less than 100 and red is greater then 150
                result = "Palette: Warm - Red dominant (Risk for Protanopia/Deuteranopia).";
            } 
            else if (r > 200 && g > 150 && b < 100){ // Checks if red is greater than 200, green is greater than 150, and blue is less than 100
                result = "Palette: Warm - Yellow/Orange (Generally distinguishable).";
            } 
            else{
                result = "Palette: Warm Tones - General mix.";
            }
        }
        else if (b >= g && b >= r){ // Checks if blue is the largest value
            if (b > 180 && r < 100){ // Checks if blue is greater than 180 and red is less than 100
                result = "Palette: Cool - Blue dominant (Safe for most color blindness types).";
            } 
            else{
                result = "Palette: Cool Tones - Cyan/Blue-Green blend.";
            }
        }
        else { 
            if (g >= r && g >= b && r > 150){ // Checks if green is the largest value and red is greater than 150
                result = "Palette: Yellow-Green (Moderate confusion risk)."; 
            }
            else if (g >= r && g >= b){  // Checks if green is the largest value
                result = "Palette: Nature - Green dominant (High confusion risk for Deuteranopia)."; 
            } 
            else{
                result = "Palette: Mixed/Complex Tone - Standard contrast check recommended."; 
            }
        } 

        return true;
    }

    void resultList(const vector <string>& pastInfo){ // Uses a vector and pass by refernces to change the vector 
        
        for(size_t i = 0; i < pastInfo.size(); i++){ // Returns a numbered list of all stored info in the vector
            cout << i + 1 << ". " << pastInfo.at(i) << endl;
        }

    }
