#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <cmath>
using namespace std;

int GenRadom() {
    // Create a random device and a generator
    std::random_device rd;
    std::mt19937 gen(rd());

    // Define the range
    std::uniform_int_distribution<> distr(0, 15);

    // Generate a random number in the range [0, 100]
    int randomNum = distr(gen);

    std::cout << "Random number: " << randomNum << std::endl;

    return 0;
}

/*
function equation1(a, b, c, x) {
return (a + b * x - c) % 100;
}

function equation2(a, b, c, x) {
    return (a * Math.pow(x, 2) + b * x + c) % 100;
}

function equation3(a, b, c, x) {
    return (a / (b + x + 1) + c) % 100;
}

function equation4(a, b, c, x) {
    return (Math.sin(a) + Math.cos(b * x) - Math.tan(c)) % 100;
}

function equation5(a, b, c, x) {
    return (a * Math.exp(-b * x) + c) % 100;
}

function equation6(a, b, c, x) {
    return (Math.log(Math.abs(a + 1)) + b * Math.sqrt(Math.abs(x)) + c) % 100;
}

function equation7(a, b, c, x) {h
    return (a * Math.sin(x) + b * Math.cos(x) + c) % 100;
}

function equation8(a, b, c, x) {
    return (Math.pow(a, 2) - Math.pow(b, 3) + c * x) % 100;
}

function equation9(a, b, c, x) {
    return (a + b * Math.log(Math.abs(x + 1)) + c) % 100;
}

function equation10(a, b, c, x) {
    return (Math.abs(a * x - b) + Math.sqrt(Math.abs(c))) % 100;
}

function equation11(a, b, c, x) {
    return (a * Math.tan(x) + b / (x + 1) + c) % 100;
}

function equation12(a, b, c, x) {
    return (Math.pow(a, x % 10) + b * Math.sin(c)) % 100;
}

function equation13(a, b, c, x) {
    return (Math.pow(a + b, x % 10) - c * x) % 100;
}

function equation14(a, b, c, x) {
    return (Math.sin(a * x) + Math.cos(b * x) - c) % 100;
}

function equation15(a, b, c, x) {
    return (Math.atan(a) + Math.atan2(b, x) + c) % 100;
}

function equation16(a, b, c, x) {
    return (a * Math.abs(Math.sin(x)) + b * Math.exp(-c)) % 100;
}

    */

string genJs(std::string TokenWhichIsfileName, int Equation[4], string BinaryContext[4]) {

    string EquationReturns[16] = { "   return (a + b * x - c) % 100;", "    return (a * Math.pow(x, 2) + b * x + c) % 100;","    return (a / (b + x + 1) + c) % 100;" ,"    return (Math.sin(a) + Math.cos(b * x) - Math.tan(c)) % 100;","    return (a * Math.exp(-b * x) + c) % 100;","    return (Math.log(Math.abs(a + 1)) + b * Math.sqrt(Math.abs(x)) + c) % 100;", "    return (a * Math.sin(x) + b * Math.cos(x) + c) % 100;","    return (Math.pow(a, 2) - Math.pow(b, 3) + c * x) % 100","    return (a + b * Math.log(Math.abs(x + 1)) + c) % 100;", "    return (Math.abs(a * x - b) + Math.sqrt(Math.abs(c))) % 100;", "    return (a * Math.tan(x) + b / (x + 1) + c) % 100;", "    return (Math.pow(a, x % 10) + b * Math.sin(c)) % 100;", "    return (Math.pow(a + b, x % 10) - c * x) % 100;", "    return (Math.sin(a * x) + Math.cos(b * x) - c) % 100;", "    return (Math.atan(a) + Math.atan2(b, x) + c) % 100;" ,"    return (a * Math.abs(Math.sin(x)) + b * Math.exp(-c)) % 100;"};

    // Define the range
    std::uniform_int_distribution<> distr(0, 15);

    // Generate a random number in the range [0, 100]
    int randomNum; 

    std::ofstream jsFile(TokenWhichIsfileName + ".js", std::ios_base::app);

    std::string Equations = "";

    if (jsFile.is_open()) {
        for (int i = 0; i < 4; i++) {
            jsFile << "export function equation" + to_string(i) + "(a, b, c, x) {" << endl;
            jsFile << EquationReturns[Equation[i]] << endl;
            Equations += EquationReturns[Equation[i]];
            if (i != 0 || i != 4) {

            }
            jsFile << "}" << endl;
            jsFile.close();
            std::cout << "JavaScript file generated successfully!" << std::endl;
        }
    }
    else {
        std::cerr << "Unable to open file!" << std::endl;
    }

    std::ofstream jsTrigger(TokenWhichIsfileName + "Trigger" + ".js", std::ios_base::app);

    if (jsFile.is_open()) {

        for (int i = 0; i < 4; i++) {

        }
    }

    return "ok";
}


int Padovian_R(int n) {
    return n * n * n + n * n - 1;
}

int main() {

    std:string test = genJs("output", 6, 5, "01");
    int option;
    int Terms;

  /*  cout << "1. Lets learn sequences" << endl;
    cout << "2. Exit" << endl;
    cout << "Enter '1' or '2' :";
    cin >> option;
    if (option == 1) {
        cout << "1. Padovian sequences" << endl;
        cout << "2. Fibonachcie sequence" << endl;
        cout << "3. Quadratic sequence" << endl;
        cout << "Enter '1', '2' or '3 :";
        cin >> option;
        // cout << endl << option;
        if (option == 1) {
            cout << "How many terms?" << endl;
            cout << "Enter: ";
            cin >> Terms;
            cout << endl;

            for (int i = 0; i <= Terms; i++) {
                if (i == 1) {
                    cout << 1 << endl;
                }
                else if (i < 2 && i >= 1) {
                    cout << 2 << endl;
                }
                else {
                    int num1 = i;
                    int num2 = i;
                    //   num1 = num1 - 1;
                      // num2 = num2 - 1;
                    cout << (num1 - 2) + (num2 - 3) << endl;

                }
            }
            if (option == 2) {

            }

        } 
    }
    */
}

