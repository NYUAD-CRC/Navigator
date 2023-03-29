#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

vector< int > ReadFun(string filename );

int main() {

// Reading the input file into a a vector of integers 
vector< int > result=ReadFun("bcidInTrain_ttbar_e8453_e8455_s3873_s3874_r14239.txt");

for(int i=0; i < result.size(); i++)
{
    std::cout << result.at(i);
    std::cout << std::endl;
}
   

}

vector< int > ReadFun(string filename )
{
// Create a text string, which is used to output the text file
string myText;

// Read from the text file
ifstream MyReadFile(filename);

// A vector of integers to read the results
vector< int > arr;

// Use a while loop together with the getline() function to read the file line by line
while (getline (MyReadFile, myText)) {


// Seperate the numbers by a space per ecah line
  char separator = ' ';
    int i = 0;
    
    // Temporary string used to split the string.
    string s; 

    // Read ecah line and split it
    while (myText[i] != '\0') {
        if (myText[i] != separator) {
            // Append the char to the temp string.
            s += myText[i]; 
        } else {
            // The First number
            arr.push_back(stoi(s));
            s.clear();
        }
        i++;

    }
    
    // Output the last stored word.
    arr.push_back(stoi(s));
}
// Close the file
MyReadFile.close();
return arr;
}
