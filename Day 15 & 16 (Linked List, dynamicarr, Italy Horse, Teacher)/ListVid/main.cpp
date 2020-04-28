#include "List.h"

using namespace std;

int main(int argc, char** argv)
{
    List Kan;
    Kan.AddNode(3);
    Kan.AddNode(5);
    Kan.AddNode(7);
    Kan.PrintList();

    Kan.DeleteNode(3);
    Kan.PrintList();
    return 0;
}
