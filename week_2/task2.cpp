#include <iostream>
#include <fstream>

struct Player{
    char name[20];
    char team[20];
    char sport[20];
    int numWins;
    int numLosses;
    double winLossRatio;

    void create(){
        std::cout << "Enter name: ";
        std::cin.getline(name, 20);
        std::cout << "Enter team: ";
        std::cin.getline(team, 20);
        std::cout << "Enter sport: ";
        std::cin.getline(sport, 20);
        std::cout << "Enter number of wins: ";
        std::cin >> numWins;
        std::cout << "Enter number of losses: ";
        std::cin >> numLosses;
        std::cout << "Enter win-loss ratio: ";
        std::cin >> winLossRatio;
        std::cin.ignore();
    }

     void write(std::ofstream& output){
        output << name << '\n';
        output << "Team: " << team << '\n';
        output << "Sport: " << sport << '\n';
        output << "Number of wins: " << numWins << '\n';
        output << "Number of losses: " << numLosses << '\n';
        output << "Win-loss ratio: " << winLossRatio << "\n\n";
    }

    void read(std::ifstream& input){
        char c;
        while(input.get(c))
            std::cout << c;
    }
};

void writePlayer(Player players[], int numOfPlayers, std::ofstream& out){
    for(int i = 0; i < numOfPlayers; i++){
        out << players[i].name << '\n';
        out << "Team: " << players[i].team << '\n';
        out << "Sport: " << players[i].sport << '\n';
        out << "Number of wins: " << players[i].numWins << '\n';
        out << "Number of losses: " << players[i].numLosses << '\n';
        out << "Win-loss ratio: " << players[i].winLossRatio << "\n\n";   
    }
}

void readPlayer(Player players[], int numOfPlayers, std::ifstream& in){
    for(int i = 0; i < numOfPlayers; i++){
        char c;
        while(in.get(c))
            std::cout << c;
    }
}


int main(){
    // std::cout << sizeof(Player);

    Player players[3]; 
    
    for(int i = 0; i < 3; i++)
        players[i].create();
    
    // std::ofstream out;
    // out.open("players.txt");
    
    // for(int i = 0; i < 3; i++)
    //     players[i].write(out);
    
    // out.close();

    // std::ifstream in;
    // in.open("players.txt");

    // std::cout << '\n';
    // for(int i = 0; i < 3; i++)
    //     players[i].read(in);

    // in.close();

    std::ofstream out1;
    out1.open("players.txt");
    writePlayer(players, 3, out1);
    out1.close();

    std::ifstream in1;
    in1.open("players.txt");
    readPlayer(players, 3, in1);
    in1.close();

    return 0;
};
