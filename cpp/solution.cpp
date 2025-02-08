#include <iostream>
#include <fstream>
#include <cmath>
#include <chrono>

bool isPrime(int n) {
    if(n < 2) return false;
    if(n == 2) return true;
    if(n % 2 == 0) return false;
    int r = std::sqrt(n) + 1;
    for (int i = 3; i < r; i += 2) {
        if(n % i == 0)
            return false;
    }
    return true;
}

long long sumFirstNPrimes(int n) {
    int count = 0;
    int num = 2;
    long long total = 0;
    while(count < n) {
        if(isPrime(num)) {
            total += num;
            count++;
        }
        num++;
    }
    return total;
}

int main() {
    auto start = std::chrono::high_resolution_clock::now();
    long long total = sumFirstNPrimes(10000);
    auto end = std::chrono::high_resolution_clock::now();
    
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    
    // Escribir el resultado en /output/result_cpp.txt
    std::ofstream outfile("/output/result_cpp.txt");
    outfile << total;
    outfile.close();
    
    // Imprimir solo el tiempo de ejecución en ms
    std::cout << duration;
    
    return 0;
}
