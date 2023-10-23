#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

const int NUM_STD = 10;

void readNames(const string& inputFile, string names[]);
void displayNames(const string names[], int numNames);
int searchNames(const string names[], int numNames, const string& name);
void bubbleSort(string names[], int numNames);
void bubbleSortDescending(string names[], int numNames);
int binarySearchNames(const string names[], int numNames, const string&name);
void selectionSort(string names[], int numNames);
void selectionSortDescending(string names[], int numNames);

//****************************************************************************************************

int main ()
{
    string names[NUM_STD],
           searchName,
           binaryName;

    int index;
    int binarySearch;

    readNames("StudentNames.txt", names);
    displayNames(names, NUM_STD);

    cout << endl;

    cout << "Enter the name to search for: ";
    getline(cin, searchName);

    index = searchNames(names, NUM_STD, searchName);
    cout << searchName << " array index can be located at: " << index << endl;

    cout << endl << endl << "Here is the sorted names in ascending order: " << endl;
    bubbleSort(names, NUM_STD);
    for (int i = 0; i < NUM_STD; i++)
    {
        cout << names[i] << endl;
    }

    cout << endl << "Here is the sorted names in descending order:" << endl;
    bubbleSortDescending(names, NUM_STD);
    for (int i = 0; i < NUM_STD; i++)
    {
        cout << names[i] << endl;
    }

    cout << "\nEnter the name to search for: ";
    getline(cin, binaryName);
    binarySearch = binarySearchNames(names, NUM_STD, binaryName);
    cout << binaryName << " array index can be located at: " << binarySearch << endl;
    

    selectionSort(names, NUM_STD);
    cout << "\nSorted names in ascending order: " << endl;
    for (int i = 0; i < NUM_STD; i++)
    {
        cout << names[i] << endl;
    }

    selectionSortDescending(names, NUM_STD);
    cout << "\nSorted names in descending order: " << endl;
    for (int i = 0; i < NUM_STD; i++)
    {
        cout << names[i] << endl;
    }
    return 0;
}

//****************************************************************************************************

void readNames(const string& inputFile, string names[])
{
    ifstream file(inputFile);
    
    for (int i = 0; i < NUM_STD; i++)
    {   
        getline(file, names[i]);
    }

    file.close();
}

void displayNames(const string names[], int numNames)
{
    for (int i = 0; i < numNames; i++)
    {
        cout << names[i] << endl;
    }
}

int searchNames(const string names[], int numNames, const string& name)
{
    int index = -1;

    for (int i = 0; i < numNames; i++)
    {
        if (names[i] == name)
        {
            index = i;
        }
    }

    return index;
}

void bubbleSort(string names[], int numNames)
{
    bool swap;
    string temp;

    do 
    {
        swap = false;

        for (int i = 0; i < (numNames - 1); i++)
        {
            if (names[i] > names[i + 1])
            {
                temp = names[i];
                names[i] = names[i + 1];
                names[i + 1] = temp;
                swap = true;
            }
        }

        numNames--;

    } while (swap);
}

void bubbleSortDescending(string names[], int numNames)
{
    bool swap;
    string temp;
    int total = numNames;
    do
    {
        swap = false;

        for (int i = 0; i < (total - 1); i++)
        {
            if (names[i] < names[i + 1])
            {
                temp = names[i];
                names[i] = names [i + 1];
                names [i + 1] = temp;
                swap = true;
            }
        }
    
        total--;

    } while (swap);
}

int binarySearchNames(const string names[], int numNames, const string& name)
{
    int first = 0,
        last = numNames - 1,        
        middle,
        position = -1; 

    bool found = false;

    while ((first <= last) && (!found))
    {
        middle = (first + last) / 2;

        if (names[middle] == name)
        {
            found = true;
            position = middle;
        }
        else 
        {
            if (names[middle] < name)
            {
                last = middle - 1;
            }
            else
            {
                first = middle + 1;
            }
        }
    }

    return position;
}

void selectionSort(string names[], int numNames)
{
    int minIndex;
    string min;

    for (int startScan = 0; startScan < (numNames - 1); startScan++)
    {
        minIndex = startScan;
        min = names[minIndex];

        for (int index = (startScan + 1); index < numNames; index++)
        {
            if (names[index] < min)
            {
                min = names[index];
                minIndex = index;
            }
        }

        names[minIndex] = names[startScan];
        names[startScan] = min;
    }
}

void selectionSortDescending(string names[], int numNames)
{
    int maxIndex;
    string max;

    for (int startScan = 0; startScan < (numNames - 1); startScan++)
    {
        maxIndex = startScan;
        max = names[maxIndex];

        for (int index = (startScan + 1); index < numNames; index++)
        {
            if (names[index] > max)
            {
                max = names[index];
                maxIndex = index;
            }
        }

        names[maxIndex] = names[startScan];
        names[startScan] = max;
    }
}


/*

Smith, John
Song, Mona
Jones, Trevor
Li, Na
Zhang, Xiu Ying
Saleem, Mohammad
Lloyd, Arthur
Jones, Rhys
Evans, Olivia
Davies, Emily

Enter the name to search for: Lloyd, Arthur
Lloyd, Arthur is located at array index: 6

Here is the sorted names in ascedning order:
Davies, Emily
Evans, Olivia
Jones, Rhys
Jones, Trevor
Li, Na
Lloyd, Arthur
Saleem, Mohammad
Smith, John
Song, Mona
Zhang, Xiu Ying

Here is the sorted names in descending order:
Zhang, Xiu Ying
Song, Mona
Smith, John
Saleem, Mohammad
Lloyd, Arthur
Li, Na
Jones, Trevor
Jones, Rhys
Evans, Olivia
Davies, Emily

Enter the name to search for: Li, Na
Li, Na array index can be located at: 5

Sorted names in ascending order:
Davies, Emily
Evans, Olivia
Jones, Rhys
Jones, Trevor
Li, Na
Lloyd, Arthur
Saleem, Mohammad
Smith, John
Song, Mona
Zhang, Xiu Ying

Sorted names in descending order:
Zhang, Xiu Ying
Song, Mona
Smith, John
Saleem, Mohammad
Lloyd, Arthur
Li, Na
Jones, Trevor
Jones, Rhys
Evans, Olivia
Davies, Emily

*/