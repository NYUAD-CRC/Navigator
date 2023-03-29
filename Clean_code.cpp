#include <iostream>
#include <fstream>
#include <vector>
#include <map>

using namespace std;

vector< int > ReadFun(string filename );
map<int, int> FilterValues(vector< int >);
int main() {

// Reading the input file into a a vector of integers 
vector< int > result=ReadFun("bcidInTrain_ttbar_e8453_e8455_s3873_s3874_r14239.txt");

map<int, int> sample_map;
for(int i=0; i < result.size()-2; i=i+2)
{
    //cout<<"I = "<<i<<endl;
    int x=result.at(i+1);
    //std::cout << "x is" <<x<<endl;;
    
    if ( x> 21)
    {
        //cout<<" iam here"<<endl;
        sample_map[result.at(i)]=result.at(i+1);
    }
    else
    {
        //cout<<"no"<<endl;
    }

}
 cout <<sample_map.size()<<endl;

        for (auto const &pair: sample_map) {
        std::cout << "{" << pair.first << ": " << pair.second << "}\n";
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
