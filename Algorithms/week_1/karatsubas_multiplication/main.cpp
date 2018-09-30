#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

vector<int> add_num(const vector<int> &x, const vector<int> &y){

    // Create dummy vectors for x and y with same size
    vector<int> copy_x ((x.size() >= y.size()? x.size(): y.size()), 0);
    vector<int> copy_y ((x.size() >= y.size()? x.size(): y.size()), 0);

    // Initialize the values with the vector values
    int i = 0;
    for(i = 0; i < x.size(); i++)
        copy_x[i] = x[i];

    for(i = 0; i < y.size(); i++)
        copy_y[i] = y[i];

    // Reverse the numbers to have efficient looping
    std::reverse(copy_x.begin(), copy_x.end());
    std::reverse(copy_y.begin(), copy_y.end());

    // Declare output vector which can be maximum 1 element bigger than the max of input vectors
    vector<int> out ((x.size() >= y.size()? x.size(): y.size()) + 1, 0);

    // Declare the carry
    int carry = 0;

    // Start from the end of the vector
    for(i = 0; i < copy_x.size(); i++){
        // Add the elements and carry and set the carry to suitable value
        out[i] = x[i] + y[i] + carry;
        carry = out[i]/10;
        out[i] = out[i]%10;
    }
    // Take care of the last element 
    out[++i] += carry;

    // Reverse the out vector
    std::reverse(out.begin(), out.end());

    return out;
}

int main(){

    // Inputs to the program
    string x = "3141592653589793238462643383279502884197169399375105820974944592";
    string y = "2718281828459045235360287471352662497757247093699959574966967627";

    int len_x = x.size();
    int len_y = y.size();

    // Create two int vectors to hold the numbers
    vector<int> vec_x (len_x, 0);
    vector<int> vec_y (len_y, 0);

    // Fill the vector values with the number values
    for(int i = 0; i < len_x; i++){
        vec_x[i] = int(x[i] - '0');
        vec_y[i] = int(y[i] - '0');
        cout << vec_x[i] << " " << vec_y[i] << endl;
    }
    
    
    return 1;
}