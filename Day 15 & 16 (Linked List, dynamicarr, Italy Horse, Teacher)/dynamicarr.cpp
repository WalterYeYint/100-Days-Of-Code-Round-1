#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::getline;
using std::string;

struct GameObject{
    string Name;
};

int main(){
    GameObject* objects = NULL;
    unsigned int counts = 0;

    cout << "Press Enter to print Game Objects.\n\n";

    while(true){
        cout << "Enter name for Game Object: ";
        GameObject gameObject;
        getline(cin,gameObject.Name);

        if(gameObject.Name == "")
            break;

        if(objects == NULL){
            objects = new GameObject[1];
            objects[0] = gameObject;
            counts++;
        }
        else{
            GameObject* temp = objects;
            objects = new GameObject[counts + 1];

            for(unsigned int i=0; i<counts; ++i){
                objects[i] = temp[i];
            }

            objects[counts] = gameObject;
            counts++;
            delete [] temp;
        }
    }

    cout << '\n';

    for(auto i=0; i<counts; ++i){
        cout << "[" << i << "]." << objects[i].Name << "\n";
    }

    if(objects != NULL)
        delete [] objects;

    cin.get();
    return 0;
}
