#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <set>
#include <fstream>
#include <chrono>

std::unordered_map<int, std::vector<std::string>> C_ncacheparentesis = {
    {0, {""}},
    {1, {"()"}},
    {2, {"()()", "(())"}}
};

std::vector<std::string> recursiva(int n) {
    if (n == 0) {
        return {""};
    } else if (n == 1) {
        return {"()"};
    } else if (n == 2) {
        return {"()()", "(())"};
    } else {
        if (C_ncacheparentesis.find(n) == C_ncacheparentesis.end()) {
            C_ncacheparentesis[n] = {};
            for (int m = 0; m < n; ++m) {
                for (const auto& p : recursiva(m)) {
                    for (const auto& q : recursiva(n - m)) {
                        C_ncacheparentesis[n].push_back(p + q);
                        C_ncacheparentesis[n].push_back(q + p);
                        C_ncacheparentesis[n].push_back(p.substr(0, p.length() / 2) + q + p.substr(p.length() / 2));
                    }
                }
            }
            std::set<std::string> unique_set(C_ncacheparentesis[n].begin(), C_ncacheparentesis[n].end());
            C_ncacheparentesis[n].assign(unique_set.begin(), unique_set.end());
        }
        return C_ncacheparentesis[n];
    }
}

int main() {
    auto start = std::chrono::high_resolution_clock::now();
    auto result = recursiva(12);
    auto end = std::chrono::high_resolution_clock::now();
    
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    
    // Escribir el resultado en /output/result_cpp.txt
    std::ofstream outfile("/output/result_cpp.txt");
    for (const auto& r : result) {
        output_file << r << "\n";
    }
    outfile.close();
    
    // Imprimir solo el tiempo de ejecución en ms
    std::cout << duration;
    
    return 0;
}
