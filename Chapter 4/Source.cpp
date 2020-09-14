#include <iostream>
#include <cmath>

using namespace std;

//Declare global variables to be used in all functions()
double fTemp, windSpeed, windChillTemp;

//Init. fuctions()
void displayInstructions();
void displayTempandWind();
double CalculateWindChill(double temp, double speed);
void displayResults();


int main() {
	
	//Set ans to y to start while loop
	char ans = 'y';

	while (toupper(ans) == 'Y') {
		//Call fuction to display instuctions
		displayInstructions();

		//Call fuction to read off user inputted Temps/Wind
		displayTempandWind();

		//Call math fuction
		windChillTemp = CalculateWindChill(fTemp, windSpeed);

		//Call fuction to display results
		displayResults();

		//Ask user if wanna do again
		cout << "\nWould you like to calculate another wind chill? (y/n) \n";
		cin >> ans;

	}
}

void displayInstructions() {

	//Display our instructions to user
	cout << "\nWelcome to the Minnesota Wind chill Index Calculator\n"
		 << "Enter a tempurature (F) inbetween 50 degrees F and -459.67 degrees F\nand a windspeed (mph) inbetween 100 and -100 MPH below!\n";

}

void displayTempandWind() {

	//Ask for Temperature input
	cout << "Temperature (F) : ";
	cin >> fTemp;

	//Make sure user inputs temperature accourding to instructions
	while (fTemp > 50 || fTemp < -459.67) {
		cout << "Enter a vaild Temperature (F) between 50 and -459.67 : ";
		cin >> fTemp;
		}

	//Ask for Wind Speed input
	cout << "Wind Speed (MPH) : ";
	cin >> windSpeed;

	//Make sure user inputs wind speed accourding to instructions
	while (windSpeed > 99 || windSpeed < -99) {
		cout << "Enter a vaild Wind Speed (MPH) between 100 and -100 : ";
		cin >> windSpeed;
	}

	//Display what they have entered
	cout << "You entered a temperature of " << fTemp << " degrees F\nYou entered a wind speed of " << windSpeed << " mph\n";
	return;
}

double CalculateWindChill(double temp, double speed) {

	//Declare windTemp to store our calculated wind chill
	double windTemp;
	
	//Wind chill equation
	windTemp = 35.74 + 0.6215 * temp - 35.75 * pow(speed, 0.16) + 0.4275 * temp * pow(speed,0.16);
	return (windTemp);
}

void displayResults() {

	//Set wind chill temp to 2 decimal places
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	// Display the results
	cout << "The wind chill is " << windChillTemp << " degrees \n";
}
