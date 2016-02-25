#ifndef DFA_NODE
#define DFA_NODE

#include <map>
#include <string>
#include <sstream>

class DFA_Node {
private:
    std::map<std::string, int> Edges;
    bool isFinalState = false;

public:

    DFA_Node(){

    }

    void addEdge(char letter, int target_node){
        //add key/value pair to hash table
        std::stringstream ss;
        ss << letter;
        std::string key;
        ss >> key;

        int value = target_node;
        Edges[key] = value;
    }

    int travelEdge(char letter){
        std::stringstream ss;
        ss << letter;
        std::string key;

        ss >> key;

        std::map<std::string, int >::const_iterator it = Edges.begin();
        for(it; it != Edges.end(); ++it)
        {
            if (it->first == key)
            {
                return it->second;
            }
        }

        //otherwise the edge doesn't exist

        return -1;
    }

    void makeFinalState(){
        isFinalState = true;
    }

    bool checkFinal(){
        return isFinalState;
    }

    void printMap(){

        for(std::map<std::string, int >::const_iterator it = Edges.begin();
            it != Edges.end(); ++it)
        {
            std::cout << it->first << " " << it->second << "\n";
        }

        std::cout << "Map is final state = " << isFinalState << std::endl << std::endl;
    }

    void listAlphabet(){
        std::cout << "Please type 'quit' to exit string entry" << std::endl;
        std::cout << "Otherwise, please test strings using the following Alphabet:" << std::endl;
        for(std::map<std::string, int >::const_iterator it = Edges.begin();
            it != Edges.end(); ++it)
        {
            std::cout << it->first << " ";
        }
        std::cout << std::endl << std::endl;
    }

    //hash table for char/int pair
};

#endif // DFA_NODE
