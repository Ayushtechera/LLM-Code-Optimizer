
#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <chrono>

// Function to perform the calculation
double calculate(int iterations, double param1, double param2) {
    double result = 1.0;
    // Using double for loop counter as well for consistency in calculations
    for (double i = 1.0; i <= static_cast<double>(iterations); ++i) {
        double j1 = i * param1 - param2;
        result -= (1.0 / j1);
        double j2 = i * param1 + param2;
        result += (1.0 / j2);
    }
    return result;
}

int main() {
    // Record start time
    auto start_time = std::chrono::high_resolution_clock::now();

    // Perform the calculation
    // Using double for parameters directly to avoid implicit conversions
    double result = calculate(1000000, 4.0, 1.0) * 4.0;

    // Record end time
    auto end_time = std::chrono::high_resolution_clock::now();

    // Calculate duration
    std::chrono::duration<double> elapsed_time = end_time - start_time;

    // Print the result with specified precision
    std::cout << std::fixed << std::setprecision(12) << "Result: " << result << std::endl;

    // Print the execution time with specified precision
    std::cout << std::fixed << std::setprecision(6) << "Execution Time: " << elapsed_time.count() << " seconds" << std::endl;

    return 0;
}
