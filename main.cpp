#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "DFA_Node.h"

using namespace std;

int main()
{
    std::string first_line, file_name;

    //vector for nodes here
    std::vector<DFA_Node*> node;
    DFA_Node* tempNode = NULL;

    std::cout << "enter the file name : ";
    std::cin >> file_name;

    //file_name = "test.txt";


    std::ifstream ifStream(file_name.c_str());

    if(ifStream.good()){
        getline(ifStream, first_line);

        std::istringstream iString(first_line);



        while(!ifStream.eof()){
            int current_node, target_node;
            char letter;

            //grabs DFA pathways
            ifStream >> current_node >> letter >> target_node;

            if (current_node == node.size()){
                tempNode = new DFA_Node();
                node.push_back(tempNode);
            }

            node[current_node]->addEdge(letter, target_node);

        }

        while(!iString.eof()){
            int temp;
            //grabs final states for the DFA
            iString >> temp;
            //mark final states
            node[temp]->makeFinalState();

            node[temp]->printMap();
        }

        ifStream.close();

        std::string userInput = "";

        while(userInput != "quit"){
            node[0]->listAlphabet();
            std::cout << "Please enter a string : ";
            std::cin >> userInput;
            std::cout << std::endl << std::endl;

            //starts at the initial state
            int myState = 0;
            bool validString = true;
            for(int i = 0; i < userInput.size();i++){
                    //change a to string letters
                char temp = userInput[i];

                std::cout << "Transition :  " << myState << " " << temp << " ";

                myState = node[myState]->travelEdge(temp);

                std::cout << myState << std::endl;

                if(myState == -1){
                    validString = false;
                    break;
                }

                if(i == userInput.size() - 1){
                    //check for final state
                    validString = node[myState]->checkFinal();
                }
            }

            if(validString == true){
                std::cout << "This is a valid string." << std::endl << std::endl;
            }else{
                std::cout << "This is not a valid string." << std::endl << std::endl;
            }



        }

    }else{
        std::cout << "bad file name" << std::endl;
    }




    return 0;
}
