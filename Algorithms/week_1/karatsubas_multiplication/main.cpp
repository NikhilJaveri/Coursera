#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

// Convert vector of ints to string
string vec2string(vector<int> &vec){
    
    string output;
    // Convert the vector to a string
    for(int i = 0; i < vec.size(); i++)
        output.append(to_string(vec[i]));
    
    return output;
}

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

    // Recursivley pop the extra zeros from out
    while(!out.back())
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

    // Recursivley pop the extra zeros from out
    while(!out.back())
        out.pop_back();

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

    if((x.size() + y.size()) < 5){
        cout << "In multiply numbers" << endl;
        return multiply_numbers(x, y);
    }
    else{
        // Split input numbers into 2 roughly equal halves
        int split_a = x.size()/2; // x = a*N + b, N = 10^split_b
        int split_c = y.size()/2; // y = c*N + d, N = 10^split_d

        // Construct the sub vectors
        vector<int> a_x (x.begin(), x.begin() + split_a); // a part of vector x
        vector<int> b_x (x.begin() + split_a, x.end()); // b part of vector x

        vector<int> c_y (y.begin(), y.begin() + split_c); // a part of vector x
        vector<int> d_y (y.begin() + split_c, y.end()); // b part of vector x

        cout << "a_x " << vec2string(a_x) << endl;
        cout << "b_x " << vec2string(b_x) << endl;
        cout << "c_y " << vec2string(c_y) << endl;
        cout << "d_y " << vec2string(d_y) << endl;

        // Construct the intermediate variables for mulitplication
        vector<int> z2 = karatsubas_multiplication(a_x, c_y);
        vector<int> z0 = karatsubas_multiplication(b_x, d_y);
        
        vector<int> a_plus_c = add_numbers(a_x, c_y);
        vector<int> b_plus_d = add_numbers(b_x, d_y);
        vector<int> a_plus_c_times_b_plus_d = karatsubas_multiplication(a_plus_c, b_plus_d);
        vector<int> sub_z2 = subtract_numbers(a_plus_c_times_b_plus_d, z2);
        vector<int> z1 = subtract_numbers(sub_z2, z0);

        // Construct the power factor
        vector<int> N (split_a, 0);
        N[0] = 1; // Power factor
        vector<int> N_squared = karatsubas_multiplication(N, N);
        
        // Combine the answers
        vector<int> z2_times_N_squared = karatsubas_multiplication(z2, N_squared);
        vector<int> z1_times_N = karatsubas_multiplication(z1, N);
        vector<int> intermediate_sum = add_numbers(z2_times_N_squared, z1_times_N);
        
        return add_numbers(intermediate_sum, z0);
    }
}

int main(){

    // Inputs to the program
    // string x = "3141592653589793238462643383279502884197169399375105820974944592";
    // string y = "2718281828459045235360287471352662497757247093699959574966967627";

    string x = "1234";
    string y = "6789";

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
    // vector<int> mul_x (4,2);
    // vector<int> mul_y (3,3);
    // vector<int> mul_xy = multiply_numbers(vec_x, vec_y);
     
    // Test karatsubas multiplication
    vector<int> karat_xy = karatsubas_multiplication(vec_x, vec_y);

    string output = vec2string(karat_xy);

    // cout << "The output is " << output << endl;

    return 1;
}