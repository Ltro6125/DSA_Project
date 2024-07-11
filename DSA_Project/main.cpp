#include "Sort.h"   
#include "DataGenerator.h"
#include "File.h"		
#include "Check.h"
#include "Command.h"
#include <chrono>
#include <vector>

#pragma comment(linker, "/STACK:600000000")
#pragma comment(linker, "/HEAP:500000000")

int main(int argc, char* argv[]) {

    if (argc < 5) {
        cout << "Error: Not enough command-line arguments." << endl;
        cout << "Command 1: [Execution file] -a [Algorithm] [Given input] [Output parameter(s)]" << endl;
        cout << "Command 2: [Execution file] -a [Algorithm] [Input size] [Input order] [Output parameter(s)]" << endl;
        cout << "Command 3: [Execution file] -a [Algorithm] [Input size] [Output parameter(s)]" << endl;
        cout << "Command 4: [Execution file] -c [Algorithm 1] [Algorithm 2] [Given input]" << endl;
        cout << "Command 5: [Execution file] -c [Algorithm 1] [Algorithm 2] [Input size] [Input order]" << endl;
        return 1;
    }

    if (string(argv[1]) == "-a" && checkAlgorithm(string(argv[2]))) {
        if (argc == 6) {
            if (isInteger(string(argv[3])) && checkDataOrder(string(argv[4])) && checkOutputParameters(string(argv[5]))) {
                if (checkValidInputSize(stoi(argv[3]))) {
                    //Command 2
                    Command2(string(argv[2]), stoi(argv[3]), string(argv[4]), string(argv[5]));
                    return 0;
                }
                else {
                    cout << "Exceeds input size" << endl;
                    return 1;
                }
                
            }
            else {
                cout << "Incorrect format" << endl;
                return 1;
            }
        }
        else if (argc == 5) {
            if (checkOutputParameters(string(argv[4]))) {
                if (isInteger(string(argv[3]))) {
                    if (checkValidInputSize(stoi(argv[3]))) {
                        //Command 3
                        Command3(string(argv[2]), stoi(argv[3]), string(argv[4]));
                        return 0;
                    }
                    else {
                        cout << "Exceeds input size" << endl;
                        return 1;
                    }
                   
                }
                if (isFormatFile(string(argv[3]))) {
                    //Command 1
                    Command1(string(argv[2]), string(argv[3]), string(argv[4]));
                    return 0;
                }
            }
            cout << "Incorrect format" << endl;
            return 1;
        }
        else {
            return 1;
        }
    }
    else if (string(argv[1]) == "-c" && checkAlgorithm(string(argv[2])) && checkAlgorithm(string(argv[3]))) {
        if (argc == 5) {
            if (isFormatFile(string(argv[4]))) {
                //Command 4
                Command4(string(argv[2]), string(argv[3]), string(argv[4]));
                return 0;
            }
            cout << "Incorrect format" << endl;
            return 1;
        }
        else if (argc == 6) {
            if (isInteger(string(argv[4])) && checkDataOrder(string(argv[5]))) {
                //Command 5
                if (checkValidInputSize(stoi(argv[4]))) {
                    Command5(string(argv[2]), string(argv[3]), stoi(argv[4]), string(argv[5]));
                    return 0;
                }
                else {
                    cout << "Exceeds input size" << endl;
                    return 1;
                }
            }
            cout << "Incorrect format" << endl;
            return 1;
        }
        
    }
    else {
        cout << "Incorrect format" << endl;
    }

    return 0;
}




