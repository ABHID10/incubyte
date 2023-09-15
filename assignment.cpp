#include<iostream>
#include<vector>
#include<string>

using namespace std;

class position {
public:
    int x, y, z;
position(int x, int y, int z) : x(x), y(y), z(z) {}
};


class direction {
public:
    int dx, dy, dz;
    direction(int dx, int dy, int dz) : dx(dx), dy(dy), dz(dz) {}

    bool operator==(const direction& other) const {
        return dx == other.dx && dy == other.dy && dz == other.dz;
    }
};

int main()
{
    position spacecraftposition(0,0,0);
    direction spacecraftdirection(0,1,0);

    vector<pair<char,direction>> cmdmapp=
    {
        {'l',direction(1,0,0)},
        {'r',direction(-1,0,0)},
        {'f',direction(0,1,0)},
        {'b',direction(0,-1,0)},
        {'d',direction(0,0,-1)},
        {'u',direction(0,0,1)}
    };

    cout<<"Enter the starting point -x,y,z"<<endl;
    cin>>spacecraftposition.x>>spacecraftposition.y>>spacecraftposition.z>>;
    string initialdirection;
    cout<<"Enter the initial direction (N,S,E,W, Up, Down) : "<<endl;
    cin>>initialdirection;

    if (initialdirection == "N") spacecraftdirection = direction(0, 1, 0);
    else if (initialdirection == "S") spacecraftdirection = direction(0, -1, 0);
    else if (initialdirection == "E") spacecraftdirection = direction(1, 0, 0);
    else if (initialdirection == "W") spacecraftdirection = direction(-1, 0, 0);
    else if (initialdirection == "Up") spacecraftdirection = direction(0, 0, 1);
    else if (initialdirection == "Down") spacecraftdirection = direction(0, 0, -1);
    else {
        cout << "Invalid initial direction input." << endl;
        return 1;
    }

    // Input commands
    string commandInput;
    cout << "Enter commands (e.g., 'f', 'r', 'u', 'b', 'l'): ";
    cin >> commandInput;

    vector<char> commands;
    for (char c : commandInput) {
        if (c == 'f' || c == 'b' || c == 'l' || c == 'r' || c == 'u' || c == 'd') {
            commands.push_back(c);
        }
    }

    // Process each command
    for (char command : commands) {
        // Find the corresponding direction change for the command
        direction change(0, 0, 0);
        for (auto mapping : cmdmapp) {
            if (mapping.first == command) {
                change = mapping.second;
                break;
            }
        }

        // Update the spacecraft's position and direction
        spacecraftposition.x += change.dx;
        spacecraftposition.y += change.dy;
        spacecraftposition.z += change.dz;

        // Print the current position and direction
        cout << "Command: " << command << endl;
        cout << "Position: (" << spacecraftposition.x << ", " << spacecraftposition.y << ", " << spacecraftposition.z << ")" << endl;

        // Update the spacecraft's direction based on the command
        spacecraftdirection = change;
    }

    // Print the final position and direction
    cout << "Final Position: (" << spacecraftposition.x << ", " << spacecraftposition.y << ", " << spacecraftposition.z << ")" << endl;
    cout << "Final Direction: ";
    if (spacecraftdirection == direction(0, 1, 0)) cout << "N";
    else if (spacecraftdirection == direction(0, -1, 0)) cout << "S";
    else if (spacecraftdirection == direction(1, 0, 0)) cout << "E";
    else if (spacecraftdirection == direction(-1, 0, 0)) cout << "W";
    else if (spacecraftdirection == direction(0, 0, 1)) cout << "Up";
    else if (spacecraftdirection == direction(0, 0, -1)) cout << "Down";
    cout << endl;

    return 0;
}

