#include <bits/stdc++.h>

const int N = 1000;
const int NAME_LENGTH = 10;
const std::string CHARACTERS = "ABCDEFGHIJKLMNOPQRSTUVWXYZqwertyuiopasdfghjklzxcvbnm1234567890";

std::vector<std::string> generateUniqueNames(int count) {
    std::unordered_set<std::string> uniqueNames;
    std::mt19937 random(std::time(0));
    std::uniform_int_distribution<int> dist(0, CHARACTERS.length() - 1);

    while (uniqueNames.size() < count) {
        std::string name;
        for (int i = 0; i < NAME_LENGTH; i++) {
            name += CHARACTERS[dist(random)];
        }
        uniqueNames.insert(name);
    }

    return std::vector<std::string>(uniqueNames.begin(), uniqueNames.end());
}

int main() {
    std::vector<std::string> men = generateUniqueNames(N);
    std::vector<std::string> women = generateUniqueNames(N);

    std::ofstream writer("in.txt");
    if (writer.is_open()) {
        writer << N << "\n";
        for (const auto& name : men) {
            writer << name << " ";
        }
        writer << "\n";
        for (const auto& name : women) {
            writer << name << " ";
        }
        writer << "\n";

        for (int i = 0; i < N; i++) {
            for (const auto& name : women) {
                writer << name << " ";
            }
            writer << "\n";
        }

        for (int i = 0; i < N; i++) {
            std::reverse(men.begin(), men.end());
            for (const auto& name : men) {
                writer << name << " ";
            }
            writer << "\n";
        }

        writer.close();
        std::cout << "Test case generated: in.txt" << std::endl;
    } else {
        std::cerr << "Failed to open file for writing." << std::endl;
    }

    return 0;
}