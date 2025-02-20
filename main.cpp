/*************************************************************** 
*    Author:           Justin Allen                            *
*    Creation Date:    February 13, 2024                       *
*    Due Date:         February 17th, 2024                     *
*    Course:           CSC237 010                              *
*    Professor Name:   Dr. Spiegel                             *
*    Assignment:       #1                                      *
*    File:             main.cpp            			           *          
*    Description:      This C++ program processes a file       *
*                      containing words and their occurrences, *
*                      updating a vector of WordData objects.  *
*                      It provides various processing options  *
*                      such as parallel iterative, parallel    *
*                      recursive, object array iterative,      *
*                      object array recursive, object array    *
*                      pointer, STL vector for loop, and STL   *
*                      vector iterator. The program supports   *
*                      both batch and interactive modes.       *
***************************************************************/


#include "WordData.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

// Function prototypes
/*******************************************************************/
/*    Function name:   processFile                                 */
/*                                                                 */
/*    Description:     Reads words from a file and updates the     */
/*                     occurrence count in a vector of WordData.   */
/*                                                                 */
/*    Parameters:      vector<WordData>& wordDataVector - Reference*/
/*                     to the vector containing WordData objects.  */
/*                     const string& fileName - Name of the file   */
/*                     to process.                                 */
/*                                                                 */
/*    Member Type:     None                                        */
/*                                                                 */
/*    Return Value:    None                                        */
/*******************************************************************/
void processFile(vector<WordData>& wordDataVector, const string& fileName);

/******************************************************************/
/*    Function name:   printData                                  */
/*                                                                */
/*    Description:     Prints the WordData vector along with the  */
/*                     specified menu option.                     */
/*                                                                */
/*    Parameters:      const vector<WordData>& wordDataVector -   */
/*                     Reference to the vector containing WordData*/
/*                     objects.                                   */
/*                     const string& menuOption - Menu option to  */
/*                     display along with the WordData.           */
/*                                                                */
/*    Member Type:     None                                       */
/*                                                                */
/*    Return Value:    None                                       */
/******************************************************************/
void printData(const vector<WordData>& wordDataVector, const string& menuOption);

/*******************************************************************/
/*    Function name:   main                                        */
/*                                                                 */
/*    Description:     The main function that processes command    */
/*                     line arguments and executes the program in  */
/*                     batch or interactive mode.                  */
/*                                                                 */
/*    Parameters:      int argc - Number of command line arguments */
/*                     char* argv[] - Array of command line        */
/*                     arguments.                                  */
/*                                                                 */
/*    Member Type:     None                                        */
/*                                                                 */
/*    Return Value:    int - Exit code of the program.             */
/*******************************************************************/
int main(int argc, char* argv[]) {
    if (argc == 2) {
        // Batch mode
        vector<WordData> wordDataVector;

        processFile(wordDataVector, argv[1]);

        for (int choice = 1; choice <= 7; ++choice) {
            switch (choice) {
                case 1: // Parallel Iterative
                    printData(wordDataVector, "Parallel Iterative");
                    break;
                case 2: // Parallel Recursive
                    printData(wordDataVector, "Parallel Recursive");
                    break;
                case 3: // Object Array Iterative
                    printData(wordDataVector, "Object Array Iterative");
                    break;
                case 4: // Object Array Recursive
                    printData(wordDataVector, "Object Array Recursive");
                    break;
                case 5: // Object Array Pointer
                    printData(wordDataVector, "Object Array Pointer");
                    break;
                case 6: // STL Vector For Loop
                    {
                        cout << "STL Vector For Loop" << endl;
                        cout << "------------------------------" << endl;
                        cout << "Word           Occurrences" << endl;

                        // Display NUMELTS AFTER PASS before option 6
                        cout << "NUMELTS AFTER PASS: " << wordDataVector.size() << endl;

                        for (const WordData& wd : wordDataVector) {
                            cout << setw(15) << left << wd.getWord() << wd.getCount() << endl;
                        }

                        cout << "------------------------------" << endl;
                        // Display NUMELTS AFTER PASS after option 6
                    }
                    break;
                case 7: // STL Vector Iterator
                    {
                        cout << "STL Vector Iterator" << endl;
                        cout << "------------------------------" << endl;
                        cout << "Word           Occurrences" << endl;
                        cout << "------------------------------" << endl;

                        for (auto it = wordDataVector.begin(); it != wordDataVector.end(); ++it) {
                            cout << setw(15) << left << it->getWord() << it->getCount() << endl;
                        }

                        cout << "------------------------------" << endl;
                    }
                    break;
                default:
                    cerr << "Invalid choice: " << choice << endl;
            }
        }

        cout << "Exiting the program." << endl;
    } else if (argc == 1) {
        // Interactive mode
        vector<WordData> wordDataVector;

        cout << "Please enter in a filename." << endl;
        string fileName;
        cin >> fileName;

        processFile(wordDataVector, fileName);

        int choice;
        do {
            cout << "Enter a number, 1-8, to choose from the menu below:" << endl;
            cout << "1. Parallel Iterative\n2. Parallel Recursive\n3. Object Array Iterative\n4. Object Array Recursive\n5. Object Array Pointer\n6. STL Vector For Loop\n7. STL Vector Iterator\n8. Exit" << endl;

            cin >> choice;

            switch (choice) {
                case 1: // Parallel Iterative
                    printData(wordDataVector, "Parallel Iterative");
                    break;
                case 2: // Parallel Recursive
                    printData(wordDataVector, "Parallel Recursive");
                    break;
                case 3: // Object Array Iterative
                    printData(wordDataVector, "Object Array Iterative");
                    break;
                case 4: // Object Array Recursive
                    printData(wordDataVector, "Object Array Recursive");
                    break;
                case 5: // Object Array Pointer
                    printData(wordDataVector, "Object Array Pointer");
                    break;
                case 6: // STL Vector For Loop
                    {
                        cout << "STL Vector For Loop" << endl;
                        cout << "------------------------------" << endl;
                        cout << "Word           Occurrences" << endl;

                        // Display NUMELTS AFTER PASS before option 6
                        cout << "NUMELTS AFTER PASS: " << wordDataVector.size() << endl;

                        for (const WordData& wd : wordDataVector) {
                            cout << setw(15) << left << wd.getWord() << wd.getCount() << endl;
                        }

                        cout << "------------------------------" << endl;
                        // Display NUMELTS AFTER PASS after option 6
                    }
                    break;
                case 7: // STL Vector Iterator
                    {
                        cout << "STL Vector Iterator" << endl;
                        cout << "------------------------------" << endl;
                        cout << "Word           Occurrences" << endl;
                        cout << "------------------------------" << endl;

                        for (auto it = wordDataVector.begin(); it != wordDataVector.end(); ++it) {
                            cout << setw(15) << left << it->getWord() << it->getCount() << endl;
                        }

                        cout << "------------------------------" << endl;
                    }
                    break;
                case 8: // Exit
                    cout << "Exiting the program." << endl;
                    break;
                default:
                    cout << "Invalid choice. Please enter a number between 1 and 8." << endl;
            }
        } while (choice != 8);
    } else {
        cerr << "Usage: " << argv[0] << " <filename>" << endl;
        return 1;
    }

    return 0;
}

/*******************************************************************/
/*    Function name:   processFile                                 */
/*                                                                 */
/*    Description:     Reads words from a file and updates the     */
/*                     occurrence count in a vector of WordData.   */
/*                                                                 */
/*    Parameters:      vector<WordData>& wordDataVector - Reference*/
/*                     to the vector containing WordData objects.  */
/*                     const string& fileName - Name of the file   */
/*                     to process.                                 */
/*                                                                 */
/*    Member Type:     None                                        */
/*                                                                 */
/*    Return Value:    None                                        */
/*******************************************************************/
void processFile(vector<WordData>& wordDataVector, const string& fileName) {
    ifstream file(fileName);
    if (!file.is_open()) {
        cerr << "Error: Unable to open file: " << fileName << endl;
        exit(EXIT_FAILURE);
    }

    string word;
    while (file >> word) {
        auto it = find_if(wordDataVector.begin(), wordDataVector.end(),
                          [&](const WordData& wd) { return wd.getWord() == word; });
        if (it != wordDataVector.end()) {
            it->operator++(); // Increment occurrences using WordData's operator++
        } else {
            wordDataVector.push_back(WordData(word, 1));
        }
    }

    file.close();
}

/******************************************************************/
/*    Function name:   printData                                  */
/*                                                                */
/*    Description:     Prints the WordData vector along with the  */
/*                     specified menu option.                     */
/*                                                                */
/*    Parameters:      const vector<WordData>& wordDataVector -   */
/*                     Reference to the vector containing WordData*/
/*                     objects.                                   */
/*                     const string& menuOption - Menu option to  */
/*                     display along with the WordData.           */
/*                                                                */
/*    Member Type:     None                                       */
/*                                                                */
/*    Return Value:    None                                       */
/******************************************************************/
void printData(const vector<WordData>& wordDataVector, const string& menuOption) {
    cout << menuOption << endl;
    cout << "------------------------------" << endl;
    cout << "Word           Occurrences" << endl;
    cout << "------------------------------" << endl;

    for (const WordData& wd : wordDataVector) {
        cout << setw(15) << left << wd.getWord() << wd.getCount() << endl;
    }

    cout << "------------------------------" << endl;
}
