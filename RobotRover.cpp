#include<iostream>
#include<string>
using namespace std;


class Rover {
private:
    int x,y;
    char direction;
public:
    Rover() {
        x = y  = 0;
        this->direction = 'N';
    }

    void setDirection(char LR) {
        if (LR == 'L') {
            if (this->direction == 'N') {
                this->direction = 'W';
            }
            else if (this->direction == 'W') {
                this->direction = 'S';
            }
            else if (this->direction == 'S') {
                this->direction = 'E';
            }
            else if (this->direction == 'E') {
                this->direction = 'N';
            }

        }
        else if (LR == 'R') {
            if (this->direction == 'N') {
                this->direction = 'E';
            }
            else if (direction == 'E') {
                this->direction = 'S';
            }
            else if (this->direction == 'S') {
                this->direction = 'W';
            }
            else if (this->direction == 'W') {
                this->direction = 'N';
            }
        }
    }
    void moveAhead() {
        if (direction == 'N') {
            y++;
        }
        else if (direction == 'E') {
            x++;
        }
        else if (direction == 'S') {
            y--;
        }
        else {
            x--;
        }
    }

    int getX() {
        return x;
    }
    int getY() {
        return y;
    }
    char getDir() {
        return direction;
    }

    void getDescription() {

      if (direction == 'N') {
        cout << "Robot at (" <<x << "," <<y << ") facing North" << endl;
      }
      if (direction == 'E') {
        cout << "Robot at (" <<x << "," <<y << ") facing East" << endl;
      }
      if (direction == 'W') {
        cout << "Robot at (" <<x << "," <<y << ") facing West" << endl;
      }
      if (direction == 'S') {
        cout << "Robot at (" <<x << "," <<y << ") facing South" << endl;
      }

    }
};


int main()
{
    Rover robot;

    char ch = 0;

    string message  = "Hello! Robot coming online. \n" \

                        "Command the robot with: \n" \

                        " L - turn left \n" \

                         " R - turn right \n" \

                        " M - move forward \n" \

                        " ? - print this message \n" \

                        " Q - quit" ;
    char dir;
    int x,y;
    do {
            if (ch == 0)
                cout << message << endl;

            cin >> ch;

            switch(ch) {
                case 'L': robot.setDirection('L');
                           robot.getDescription();
                          cout << "> "; 
                            break;
                case 'R' : robot.setDirection('R');
                           robot.getDescription();
                          cout << "> " ;
                            break;
                case 'M' : robot.moveAhead();
                           robot.getDescription();
                          cout << "> " ;
                            break;
                case '?' : cout << message << endl ;
                          cout << "> ";
                           break;
                case 'Q' :   cout << " Robot shutting down " <<endl; break;

            }

    }while(ch != 'Q');

}
