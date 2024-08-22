// Name: David Gaona
// Program Description: Files, Functions and Arrays
// Date: Aug 22, 2024

#include <iostream>
#include <string>
#include <fstream>
using  namespace std;

void fileCheck(ifstream& iFile) // Function checks to see if the input file exists
{
    if (!iFile.is_open()) // If iFile is not open then cout "input file not found"
    {
        cout << "input file not found" << endl;
        cin.get();
        exit(1);
    }
}

int getNames(ifstream &iFile, string cName[]) // Function gets the names of the file being passed by refrence
{
    int counter = 0; // Counter used to read through the file, starts at 0 because thats how arrays work example: 10 = 0,1,2,3,4,5,6,7,8,9
    while (!iFile.eof()) // While iFile is not at the end of file, it gets the data in the file
    {
        getline(iFile, cName[counter]);  // Getline used to get strings with spaces, and stores in cName
        counter++;  // Increments the counter
    }
    return counter;  // This is the value returned to counter
}

void output( ofstream &oFile, int counter, string cName[]) // Outputs the strings read in the order written
{
    for  (int a = 0; a < counter; a++) // loops through the value of the counter
    {
        cout << "Class Name:" << cName[a] << endl << endl; // Outputs to the console screen
        oFile << "Class Name:" << cName[a] << endl << endl; // Outputs to the output file
    }
}

void output2(ofstream &oFile, int counter, string cName[]) // Outputs the strings read in reverse order
{
    for (int a = counter - 1; a >= 0; a--) // Starts at the max value of counter and decreases for every loop
    {
        cout << "Class Name:" << cName[a] << endl << endl;
        oFile << "Class Name:" << cName[a] << endl << endl;
    }
}

int main()
{
    ifstream iFile; 
    ofstream oFile;
    iFile.open("input.txt"); // Opens the input file
    oFile.open("output.txt"); // Opens the output file
    fileCheck(iFile);


    const int x = 50; // Static value for the array, and can't be changed
    
    string cName[x]; // Declaring the array with the constant integer

    int counter = 0; // Counter neccesary for the unkown value of the array

    counter = getNames(iFile, cName);

    output(oFile, counter, cName);  // When calling a function you need to add parameters
    output2(oFile, counter, cName);
    

    iFile.close(); // Closes input file
    oFile.close(); // Closes output file
    cout << "Press any key to continue" << endl;
    cin.get();
    return 0;
}
