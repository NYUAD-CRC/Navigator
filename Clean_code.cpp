#include <iostream>
#include <fstream>
#include <vector>
#include <map>

using namespace std;

vector<int> ReadFun(string filename);
map<int, int> FilterValues(vector<int>);

int main()
{

    // Reading the input file into a a vector of integers
    vector<int> result = ReadFun("bcidInTrain_ttbar_e8453_e8455_s3873_s3874_r14239.txt");

    map<int, int> sample_map = FilterValues(result);
    
    cout << sample_map.size() << endl;

    for (auto const &pair : sample_map)
    {
        std::cout << pair.first << ": " << pair.second << endl;
    }
}

vector<int> ReadFun(string filename)
{
    // Create a text string, which is used to output the text file
    string myText;

    // Read from the text file
    ifstream MyReadFile(filename);

    // A vector of integers to read the results
    vector<int> arr;

    // Use a while loop together with the getline() function to read the file line by line
    while (getline(MyReadFile, myText))
    {

        // Seperate the numbers by a space per ecah line
        char separator = ' ';
        int i = 0;

        // Temporary string used to split the string.
        string s;

        // Read ecah line and split it
        while (myText[i] != '\0')
        {
            if (myText[i] != separator)
            {
                // Append the char to the temp string.
                s += myText[i];
            }
            else
            {
                // The First number
                arr.push_back(stoi(s));
                s.clear();
            }
            i++;
        }

        // Output the second number
        arr.push_back(stoi(s));
    }
    // Close the file
    MyReadFile.close();
    return arr;
}

map<int, int> FilterValues(vector<int> input)
{
    // Craeting a map to store the output
    map<int, int> sample_map;

    // Passing through all elements of the file
    for (int i = 0; i < input.size() - 1; i = i + 2)
    {
        //Checking if the value is > 21
        if (input.at(i + 1) > 21)
        {
            // create a map of the BCID and the distance
            sample_map[input.at(i)] = input.at(i + 1);
        }
        else
        {
            // do nothing
        }
    }
    return sample_map;
}