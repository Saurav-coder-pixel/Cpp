#include<iostream>
#include<math.h>
using namespace std;

// Define the function to integrate
#define f(x) (1.0/(1.0 + pow(x, 2)))

int main(){
    float lower, upper, integration = 0.0, stepSize, k;
    int i, subInterval;
    
    cout << "Enter lower limit of integration: ";
    cin >> lower;
    cout << "Enter upper limit of integration: ";
    cin >> upper;
    cout << "Enter number of sub intervals: ";
    cin >> subInterval;
    
    // Calculate step size
    stepSize = (upper - lower) / subInterval;
    
    // First and last terms
    integration = f(lower) + f(upper);
    
    // Summation of middle terms
    for(i = 1; i <= subInterval - 1; i++) {
        k = lower + i * stepSize;
        integration = integration + 2 * f(k);
    }
    
    // Final integration value
    integration = integration * stepSize / 2;
    
    cout << endl << "Required value of integration is: " << integration;
    return 0;
}