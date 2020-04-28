
/* File Handling with C++ using ifstream & ofstream class object*/
/* To write the Content in File*/
/* Then to read the content of file*/
#include <iostream> 
  
/* fstream header file for ifstream, ofstream,  
  fstream classes */
#include <fstream> 
  
using namespace std; 
  
// Driver Code 
int main() 
{ 
    string line; 
    string fname;
    string buffer;
    // Creation of ifstream class object to read the file 
    
    cout << "Enter filename:" << endl;
    cin >> fname;
    
    std::ifstream in(fname);
    if (in.fail()) {
        std::cout << "File not found!\n";
        return false;
    }
  
    // Execute a loop until EOF (End of File) 
    while (!in.eof()) {
        getline(in, buffer, '\n');
        cout << buffer << endl; 
    }
  
  
    return 0; 
} 
