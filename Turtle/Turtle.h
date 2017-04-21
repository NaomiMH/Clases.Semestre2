#ifndef TURTLE_H
#define TURTLE_H

//Turtle commands:
//1 Pen up
//2 Pen down
//3 Turn right
//4 Turn left
//9 Finish
// dir : up=1, right=2, down = 3, left=4

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#define MAX 40

class Turtle {
    private:
        int xPos; //Horizontal position
        int yPos; //Vertical position
        int pen;  //Is the pen up=1 or down=2
        int dir;  //Direction the turtle is facing
        int area[MAX][MAX]={{0}};
        ifstream inFile;
        ofstream archivoS;

    public:
        Turtle(string fileName){ //Start at position (MAX-1,0)
            xPos = 0;
            yPos = MAX-1; //The bottom left position in the drawing area
            pen = 1; //Penup and
            dir = 1; //facing upwards
            inFile.open( fileName.c_str() );
            fileName= "2"+fileName;
            archivoS.open(fileName.c_str());
        }

        void clearArea(){ //Put a zero in every element of the drawing area
            int contX, contY=0;
            while(contY<MAX){
                contX=0;
                while(contX<MAX){
                    area[contY][contX]=0;
                    contX++;
                }
                contY++;
            }
        }

        void printArea(){ //Shows the contents of the drawing area
            int contX, contY=0;
            while(contY<MAX){
                contX=0;
                while(contX<MAX){
                    if(area[contY][contX]==1)
                        cout << "#";
                    else
                        cout << " ";
                    contX++;
                }
                contY++;
                cout << endl;
            }
        }

        int move(){ //Takes a line from the input file and executes the command in it
            int command, steps;
            string comment;
            inFile >> command;
            switch (command) {
                case 1: //PenUp
                    pen = 1;break;
                case 2: //PenDown
                    pen = 2;break;
                case 3: // Turn right (up=1; right=2; down = 3; left=4)
                    dir = dir % 4 + 1;break;
                case 4: //Turn left (up=1; right=2; down = 3; left=4)
                    dir = ( dir == 1 ?  4 : dir-1);break;
                case 9: //END
                    inFile.close(); //Finished
                    break;
                case 5: //Advance forward X steps
                    inFile >> steps;
                    switch(dir) { //Move and take care of the area limits
                        case 1: //up
                            for(int i =0; i<steps; i++ ) {
                                yPos = ( yPos == 0 ?  (MAX-1) : yPos-1); //If at the top, appear in the bottom
                                if (pen == 2)
                                    area[yPos][xPos] = 1;
                            }
                            break;
                        case 2: //right
                            for(int i =0; i<steps; i++ ) {
                                xPos = (++xPos) % MAX;  //If at the right most position, appear at the left
                                if (pen == 2) // If pen in down
                                    area[yPos][xPos] = 1;
                            }
                            break;
                        case 3: //down
                            for(int i =0; i<steps; i++ ) {
                                yPos = (++yPos) % MAX; //If at the bottom position, appear at the top
                                if (pen == 2)
                                    area[yPos][xPos] = 1;
                            }
                            break;
                        case 4: //left
                            for(int i =0; i<steps; i++ ) {
                                xPos = ( xPos == 0 ?  (MAX-1) : xPos-1); //If at the left most position, appear at the right
                                if (pen == 2)
                                    area[yPos][xPos] = 1;
                            }
                            break;
                    }
            }
            inFile >> comment;	// Discard the comment
            archivoS << comment;
            if (command==5)
                archivoS << "\t" << steps;
            if (command!=9)
                archivoS << endl;
            if (command==9)
                archivoS<< "end";
            return command;
        }
};

#endif // TURTLE_H
