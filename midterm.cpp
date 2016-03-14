// Code Body - Vineet Pande
// Comments and Troubleshooting - Anat Berday-Sacks and Alison Duck

#include <iostream> //defines objects for input and output
#include <string>// include the library that defines the file type of string
#include <stdlib.h> //include the standard library
#include <stdio.h> //include the stdio.h file, which includes function related to input and output
#include <time.h>//includes the time library and functions
using namespace std; //tells the computer to recognize certain terms

//Next we will use the function “randomDouble” to generate a random integer within the limits of floor to ceiling. It will output a variable/double. We will use the time to seed the function.
 
double randomDouble(int floor, int ceiling) // The function will return a double and takes the parameters floor (an integer) and ceiling (another integer).
{
  double r  = (double) rand() / (double) RAND_MAX; //generates a random number and casts it to double
  double output = ((double)floor + (r*(ceiling-floor))); //makes sure the generated number fits our defined range of ceiling to floor and is casted to double
  return output; //outputs the random double
  srand(time(NULL)) ; //seeds random number generator so every time the function runs it will use a different random number
}

//The following line runs simulate collision, and the void function means it will not output anything.

void simulateCollision(int n, int maxAngle, int maxVelocity) 

// This returns nothing, takes the parameters int n (the number of collisions we will run) int maxAngle (the greatest angle we can assign to a particle), and int maxVelocity (the greatest velocity we can assign to a particle).

{

  //The for loop calls randomDouble to generate the random velocity and angles for the two particles in the collision and runs a specified n number of collisions.

  for(int i = 0; i < n; i++)
    {
      double ang1 = randomDouble(0, maxAngle); //The minimum and maximum value for the angle1 is 0 and 360, respectively. 
      double v1 = randomDouble(0, maxVelocity); //The minimum and maximum value for the velocity is 0 and 1000, respectively. 
      double ang2 = randomDouble(0, maxAngle); //The minimum and maximum value for the angle2 is 0 and 360, respectively. 
      double v2 = randomDouble(0, maxVelocity); //The minimum and maximum value for the velocity is 0 and 1000, respectively. 

      //Each of the following lines outputs the velocity and angle of particle 1 and 2 before the collision using the values computed above.

      cout << "The velocity of particle 1 before the collision " << i << " is " << v1<<endl;
      cout << "The angle of particle 1 before the collision " << i << " is " << ang1<<endl;
      cout << "The velocity of particle 2 before the collision " << i << " is " << v2<<endl;
      cout << "The angle of particle 2 before the collision " << i << " is " << ang2<<endl << endl;

      //The following temporarily stores the values of particle 2’s initial velocity in Temp1 so that particle 1 and 2 can exchange velocities as a result of the collision.
      double Temp1 =0, Temp2 =0; //Initially Temp1 and Temp2 have the value of 0.
      Temp1 = v2; //Store particle 2’s initial velocity in Temp1.
      v2  = v1; //Set particle 2’s final velocity equal to particle 1’s initial velocity. 
      v1  = //Temp1; //Set particle 1’s final velocity equal to particle 2’s initial velocity.

	//The following temporarily stores the values of particle 2’s initial angle in Temp2 so that particle 1 and 2 can exchange angles as a result of the collision.
	Temp2 = ang2; //Store particle 2’s initial angle in Temp2.
      ang2  = ang1; //Set particle 2’s final angle equal to particle 1’s initial angle.
      ang1  = Temp2; //Set particle 1’s final angle equal to particle 2’s initial angle.

      //Each of the following lines outputs the velocity and angle of particle 1 and 2 after the collision using the values computed above.

      cout << "Velocity of particle 1 after collision " << i << " is " << v1<<endl;
      cout << "Angle of particle 1 after collision " << i << " is " << ang1<<endl;
      cout << "Velocity of particle 2 after collision " << i << " is " << v2<<endl;
      cout << "Angle of particle 2 after collision " << i << " is " << ang2<<endl<<endl;
    }
}

//Simulates a collision 20 times using the maximum angle of 360 and maximum velocity of 1000.

int main()
{
  simulateCollision (20, 360, 1000); /*runs the simulateCollision function with 20 collisions, a maximum angle of 360 degrees and a maximum of velocity*/
}
