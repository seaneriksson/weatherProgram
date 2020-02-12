/*CSE 110 - 500 - Sean Eriksson - Lab 5
Weather program (call by reference and void functions)
*/

#include <iostream>
#include <cmath>


using namespace std;

void take_input (double& temperature, double& windSpeed, double& dewPoint);  // input function, takes user input

double compute_windchill (double& temperature, double& windSpeed, bool& error);  // compute windchill function

double compute_cloudbase (double& temperature, double& dewPoint);  // compute cloudbase function

void show_output (double& temperature, double& windSpeed, double& dewPoint, double& computedWindchill, double& computedCloudbase, bool& error);  // prints final output


int main()
{
    double temperature, windSpeed, dewPoint, computedWindchill, computedCloudbase;  // set initial double variables

    bool error;  //set intial boolean variable, will track error for temperature


    cout << " --------------------------------------------------------" << endl;
    cout << "|                                                        |" << endl;
    cout << "|  This program determines wind chill using temperature  |" << endl;
    cout << "|  in Fahrenheit and wind speed in mph. and computes     |" << endl;
    cout << "|  the cloud base using the dew point in Fahrenheit.     |" << endl;
    cout << "|                                                        |" << endl;
    cout << " --------------------------------------------------------" << endl;


    cout.setf(ios::fixed);  //use fixed point

    cout.setf(ios::showpoint);  //display the decimal

    cout.precision(1);  //dispal one decimal place


    take_input (temperature, windSpeed, dewPoint);  // perform the take input function and ask the user for temperature, wind speed, and dew point

    computedWindchill = compute_windchill(temperature, windSpeed, error);  // perform the wind chill function using the temperature and wind speed variables

    computedCloudbase = compute_cloudbase(temperature, dewPoint);  // perform the cloud base function and ask the user for temperature and wind speed

    show_output(temperature, windSpeed, dewPoint, computedWindchill, computedCloudbase, error);  // perform the show output function to print the results

    return 0;
}


void take_input (double& temperature, double& windSpeed, double& dewPoint)  // input function, takes input from the user

{

    cout << "Enter the temperature in degress Fahrenheit: ";

    cin >> temperature;  // assign  the user input to the temperature variable

    cout << "Enter the wind speed in mph: ";

    cin >> windSpeed;  // assign the user input to the wind speed variable

    cout << "Enter the dew point in degrees Fahrenheit: ";

    cin >> dewPoint;  // assign the user input to the dew point variable

}

double compute_windchill (double& temperature, double& windSpeed, bool& error)  // copmutes wind chill

{

    double computedWindchill;


    if (temperature <= 50 && windSpeed >= 3.0)
    {
        computedWindchill = 35.74 + ((0.6215 * temperature) - (35.75 * (pow(windSpeed, 0.16)))) + (0.4275 * temperature * (pow(windSpeed, 0.16)));

        error = false;

        return computedWindchill;
    }

    else
    {
        error = true;

        return error;
    }

}



double compute_cloudbase (double& temperature, double& dewPoint)  // computes cloud base

{

    double computedCloudbase;

    computedCloudbase = ((temperature - dewPoint) / 4.4) * 1000;

    return computedCloudbase;

}


void show_output (double& temperature, double& windSpeed, double& dewPoint, double& computedWindchill, double& computedCloudbase, bool& error)  // prints final output

{
    cout <<" Temperature     Wind Speed     Dew Point     Wind Chill     Cloud Base" <<endl;

    cout <<"---------------------------------------------------------------------------" <<endl;

    cout <<"   " << temperature;

    cout <<" dF         " << windSpeed;

    cout <<" mph       " << dewPoint;

    if (error == false)    //search for error, if error is false print the following

    {

    cout <<" dF         " << computedWindchill;

    cout <<" dF    ";

    cout <<"   " << computedCloudbase;

    cout <<" ft";

    }

    else  // if error is true, print the following

    {

    cout <<" dF          ***";

    cout <<"          " << computedCloudbase;

    cout <<" ft";

    cout <<"" <<endl;

    cout <<"" <<endl;

    cout <<"   *** Temperature must be 50 degrees or less, and windspeed" <<endl;

    cout <<"       must be 3 mph or more to compute wind chill." <<endl;


    }

}
