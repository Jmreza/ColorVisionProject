**version 1.0**

# Simple CVD (Color Vision Deficiency) Diagnosis

## Through this program when the user inputs their the colors they struggle viewing, the severity, and colors they struggle viewing the most in order to give the user a diganosis of their CVD.

**version 2.0**

# RGB Color Palatte Analyzer 

## The pervious version had errors with improperely formatted inputs, and would get stuck in loops. This version fixes all those logical errors and focuses on RGB values instead of CVD diagnosis.
## Through this new program you can gain a simple understanding of the RGB value formats, differentiate between color palletes using RGB values, and store the users results.
## Given a file thats formatted correctly, it can be extract the RGB values and add the results into a compiled list of all your results since the program started.
## When the program is done it displays your results. In addition, it writes all the compiled results into a file called 'color_analysis_report'.

Replace with a description of *what* your program does (not *how* it works)


## Joshua Reza

Replace with your name

## 1: Josh
## 2: Y
## 3: continue
## 4: 140
## 5: 150
## 6: 170
## 7: results
## 8: file
## 9: colors.txt
## 10: quit


To run the program, give the following commands:

```
g++ --std=c++11 *.cpp -o cvp
./cvp
```

Here is an example of the program running:

```
Please enter your name: Josh
Hello Josh! Let's analyze some color combinations using RGB values!
Do you understand the format of an RGB(R/G/B) value(Y/N)?
Y
Great! Let's get started.
Please proceed and choose by typing 'continue',  'results', 'file', or 'quit'.
continue
Enter Red value (0-255): 
170
Enter Green value (0-255): 
140
Enter Blue value (0-255): 
150
Here are your results! Palette: Mixed/Complex Tone - Standard contrast check recommended.
Please proceed and choose by typing 'continue',  'results', 'file', or 'quit'.
results
Here are your current results! 
1. Palette: Mixed/Complex Tone - Standard contrast check recommended.
Please proceed and choose by typing 'continue',  'results', 'file', or 'quit'.
file
Enter the file name: 
colors.txt
Successfully processed '12' color combination(s) from the file!
Please proceed and choose by typing 'continue',  'results', 'file', or 'quit'.
quit
You have quit the program, thank you for your time!
Here are your final results! 
1. Palette: Mixed/Complex Tone - Standard contrast check recommended.
2. Palette: Grayscale (Black/Dark Gray) - High contrast text safe.
3. Palette: Grayscale (White/Light Gray) - High visibility.
4. Palette: Warm - Red dominant (Risk for Protanopia/Deuteranopia).
5. Palette: Nature - Green dominant (High confusion risk for Deuteranopia).
6. Palette: Cool - Blue dominant (Safe for most color blindness types).
7. Palette: Warm - Yellow/Orange (Generally distinguishable).
8. Palette: Cool - Blue dominant (Safe for most color blindness types).
9. Palette: Magenta/Purple - Vibrant high-contrast tone.
10. Palette: Warm Tones - General mix.
11. Palette: Warm Tones - General mix.
12. Palette: Cool Tones - Cyan/Blue-Green blend.
13. Palette: Cool Tones - Cyan/Blue-Green blend.
Your final results successfully saved to 'color_analysis_report.txt'!

```