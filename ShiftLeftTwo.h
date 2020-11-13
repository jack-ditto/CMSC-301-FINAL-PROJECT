#include<string>

using namespace std;

class ShiftLeftTwo {

    public:

        // Constructor
        ShiftLeftTwo();

        // Perform shift left on input
        string get();
        void set(string input);

    private:
        string output;
        string input;
        void shiftLeftTwo();
};