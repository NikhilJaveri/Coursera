#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

// Add x to y, x + y
vector<int> add_numbers(vector<int> &x, vector<int> &y){

    // Reverse the numbers to have efficient looping
    std::reverse(x.begin(), x.end());
    std::reverse(y.begin(), y.end());

    // Create dummy vectors for x and y with same size
    vector<int> copy_x ((x.size() >= y.size()? x.size(): y.size()), 0);
    vector<int> copy_y ((x.size() >= y.size()? x.size(): y.size()), 0);

    // Initialize the values with the vector values
    int i = 0;
    for(i = 0; i < x.size(); i++)
        copy_x[i] = x[i];

    for(i = 0; i < y.size(); i++)
        copy_y[i] = y[i];

    // Declare output vector which can be maximum 1 element bigger than the max of input vectors
    vector<int> out ((x.size() >= y.size()? x.size(): y.size()) + 1, 0);

    // Declare the carry
    int carry = 0;

    // Start from the end of the vector
    for(i = 0; i < copy_x.size(); i++){
        // Add the elements and carry and set the carry to suitable value
        out[i] = copy_x[i] + copy_y[i] + carry;
        carry = out[i]/10;
        out[i] = out[i]%10;
    }
    // Take care of the last element 
    out[i] += carry;

    // If carry is not set, pop the extra zero from out
    if(!carry)
        out.pop_back();

    // Reverse the out vector and input vectors
    std::reverse(out.begin(), out.end());
    std::reverse(x.begin(), x.end());
    std::reverse(y.begin(), y.end());

    return out;
}

// Subtract y from x, x - y
vector<int> subtract_numbers(vector<int> &x, vector<int> &y){

    // Reverse the numbers to have efficient looping
    std::reverse(x.begin(), x.end());
    std::reverse(y.begin(), y.end());

    // Create dummy vectors for x and y with same size
    vector<int> copy_x ((x.size() >= y.size()? x.size(): y.size()), 0);
    vector<int> copy_y ((x.size() >= y.size()? x.size(): y.size()), 0);

    // Initialize the values with the vector values
    int i = 0;
    for(i = 0; i < x.size(); i++)
        copy_x[i] = x[i];

    for(i = 0; i < y.size(); i++)
        copy_y[i] = y[i];

    // Declare output vector which can be maximum as big as the max of input vectors
    vector<int> out ((x.size() >= y.size()? x.size(): y.size()), 0);

    // Declare the carry
    int borrow = 0;

    // Start from the end of the vector
    for(i = 0; i < copy_x.size(); i++){
        // Add the elements and carry and set the carry to suitable value
        out[i] = copy_x[i] - copy_y[i] - borrow;
        
        if(out[i] < 0){
            borrow = 1;
            out[i] = out[i] + 10;
        }
        else
            borrow = 0;
    }

    // Reverse the out vector and input vectors
    std::reverse(out.begin(), out.end());
    std::reverse(x.begin(), x.end());
    std::reverse(y.begin(), y.end());

    return out;
}

// Multiply x and y, x*y using normal multiplication
vector<int> multiply_numbers(vector<int> &x, vector<int> &y){

    // Reverse the numbers to have efficient looping
    std::reverse(x.begin(), x.end());
    std::reverse(y.begin(), y.end());

    // Create dummy vectors for x and y with same size
    vector<int> copy_x ((x.size() >= y.size()? x.size(): y.size()), 0);
    vector<int> copy_y ((x.size() >= y.size()? x.size(): y.size()), 0);

    // Initialize the values with the vector values
    int i = 0;
    for(i = 0; i < x.size(); i++)
        copy_x[i] = x[i];

    int j = 0;
    for(j = 0; j < y.size(); j++)
        copy_y[j] = y[j];

    // Declare output vector which can be maximum 2 times the max of input vectors
    vector<int> out ((x.size() >= y.size()? x.size(): y.size()) * 2, 0);

    // Declare the carry
    int carry = 0;
    int intermediate_calc = 0;

    // Start from the end of the vector
    for(i = 0; i < copy_x.size(); i++){
        carry = 0;
        intermediate_calc = 0;
        for(j = 0; j < copy_y.size(); j++){
            // Multiply the elements and add the carry. Set the carry to a suitable value
            intermediate_calc = copy_x[i] * copy_y[j] + carry;
            carry = intermediate_calc/10;
            out[i+j] += intermediate_calc%10;

            // Take care of addition carry
            carry += out[i+j]/10;
            out[i+j] = out[i+j]%10;
        }
        // Take care of the last element 
        out[i+j] += carry;
    }

    // Recursivley pop the extra zeros from out
    while(!out.back())
        out.pop_back();

    // Reverse the out vector and input vectors
    std::reverse(out.begin(), out.end());
    std::reverse(x.begin(), x.end());
    std::reverse(y.begin(), y.end());

    return out;

}

// Multiply x and y, x*y using karatsubas multiplication
vector<int> karatsubas_multiplication(vector<int> &x, vector<int> &y){

    if((x.size() == 1) || (y.size() == 1))
        vector<int> out ((x.size() >= y.size()? x.size(): y.size()) + 1, 0);

        // Split input numbers into 2 roughly equal halves
        int split_a = x.size()/2; // x = a*N + b, N = 10^split_b
        int split_b = x.size() - split_a;

        int split_c = y.size()/2; // y = c*N + d, N = 10^split_d
        int split_d= y.size() - split_c;

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
        // cout << vec_x[i] << " " << vec_y[i] << endl;
    }

    // // Test add num
    // vector<int> sum_x (1,9);
    // vector<int> sum_y (1,9);
    // vector<int> sum_xy = add_numbers(sum_x, sum_y);
    // for(int i = 0; i < sum_xy.size(); i++)
    //     cout << sum_xy[i] << endl;

    // // Test sub num
    // vector<int> sub_x (1,6);
    // vector<int> sub_y (1,3);
    // vector<int> sub_xy = subtract_numbers(sub_x, sub_y);
    // for(int i = 0; i < sub_xy.size(); i++)
    //     cout << sub_xy[i] << endl;

    // Test mulitply num
    vector<int> mul_x (3,9);
    vector<int> mul_y (4,9);
    vector<int> mul_xy = multiply_numbers(mul_x, mul_y);
    for(int i = 0; i < mul_xy.size(); i++)
        cout << mul_xy[i] << endl;
     
    return 1;
}