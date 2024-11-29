#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))
// This is a macro
// It acts similarly to a function, but it is available to the entire file / namespace
// Should be limited to one expression

void printSizeOfArray(const float *);
void printSizeOfVector(const vector<float> &);

int main()
{
    int n;

    cout << "Enter total number of elements: ";
    cin >> n;
    cout << endl; // buffer space

    if(n <= 0) return 0;

    float arr[n];

    for(int i = 0; i < n; i++)
    {
        cout << "Enter number " << i + 1 << " : ";
        cin >> arr[i];
    }

    float smallestNumber = numeric_limits<float>::max();
    float largestNumber = numeric_limits<float>::min();

    //* using max for smallest so it can compare against a number that will definitely be smaller
    for(int i = 0; i < n; i++)
    {
        smallestNumber = (arr[i] < smallestNumber) ? arr[i] : smallestNumber;
        largestNumber = (arr[i] > largestNumber) ? arr[i] : largestNumber;
    }

    cout << endl <<  "Smallest element is " << smallestNumber << endl;
    cout << endl << "Largest element is " << largestNumber << endl;

    printSizeOfArray(arr);

    cout << "Array contains " << ARRAY_SIZE(arr) << " elements." << endl;


    return 0;
}

//* declaring this const means that the value for the reference being passed in will not change
void printSizeOfArray(const float *arr, int n)
{
    //* passing a pointer to an array will not allow you to get the size of the array
    //* you have to pass in the size to work with it

    constexpr int arraySize = sizeof(arr);
    //* constexpr means that the expression will be figured out during compile time
    //* sizeof returns the size in bytes
    //* This is a pointer, so it will be 8 as we're on 64 bit machines
    cout << "Array contains " << arraySize << " elements."  << endl;


    //* =========Vectors=========
    vector<float> vector(arr, arr + n);

    //* Adds an element to the end
    vector.push_back(1.0);

    //* inserts 2 at the first position
    vector.insert(vector.begin(), 2.0);

    //* inserts 3 at the position 3rd from the start
    vector.insert(vector.begin() + 3, 3.0);

    //* removes from the end
    vector.pop_back();

    //* removes a specified value from the vector
    erase(vector, 6);
}

void printSizeOfVector(const vector<float> &vec)
{
    cout << "Vector contains " << vec.size() << " elements."  << endl;
}