#include <iostream>
#include "CTurtle.hpp"
using namespace std;
using namespace cturtle;

const int MIN_BRANCH_LENGTH = 1;

void construct_tree( Turtle* turtle, int current_branch_length, int shortening_factor, int angle_from_parent){

    //Base Case
    if (MIN_BRANCH_LENGTH < current_branch_length) {
        //Recursive Work
        turtle->forward(current_branch_length);
        int new_length = current_branch_length - shortening_factor;

        //Left Recurse
        turtle->left(angle_from_parent);
        construct_tree(turtle, new_length, shortening_factor, angle_from_parent);

        //Right Recurse
        turtle->right(2 * angle_from_parent);
        construct_tree(turtle, new_length, shortening_factor, angle_from_parent);

        //Backwards Recurse
        turtle->left(angle_from_parent);
        turtle->backward(current_branch_length); 
    };

}


int main() {

    //Create & initalize a Turtle Graphics screen object and turtle.
    TurtleScreen screenObj;
    Turtle* turtle1 = new Turtle(screenObj);
    turtle1->speed(0);
    turtle1->fillcolor({ "orange" });
    turtle1->pencolor({ "orange" });
    
    //Turtle* turtle2 = new Turtle(screenObj);
    //turtle2->speed(0);
    //turtle2->fillcolor({ "orange" });

    //Turtle* turtle3 = new Turtle(screenObj);
    //turtle3->speed(0);
    //turtle3->fillcolor({ "black" });
    //turtle3->pencolor({ "orange" });
   
    
    turtle1->begin_fill(); 
    //turtle2->begin_fill();
    //turtle3->begin_fill();


    turtle1->setheading(90);
    //turtle2->setheading(0);
    //turtle3->setheading(180);
    
    //Turtle is engaged
    {
        
        construct_tree(turtle1, 50, 5, 30);
        //construct_tree(turtle2, 40, 2, 30);
        //construct_tree(turtle3, 100, 5, 90);
        
    }

    //Stop drawing and deconstruct the screen object after user input.
    turtle1->end_fill();
    //turtle2->end_fill();
    //turtle3->end_fill();

    cout << "Press Enter To End The Program";
    getchar();
    screenObj.bye();
    //-----------------------------------------------------------------

}
