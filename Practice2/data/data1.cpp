#include <bits/stdc++.h>

std::mt19937 random(std::time(0));

std::string generateRandomName() {
    std::string name;
    for (int i = 0; i < 10; i++) {
        char c = (char) (random() % 26 + (random() % 2 ? 'A' : 'a'));
        name += c;
    }
    return name;
}

void shuffleArray(std::vector<std::string>& arr) {
    for (int i = arr.size() - 1; i > 0; i--) {
        int j = random() % (i + 1);
        std::swap(arr[i], arr[j]);
    }
}

int main() {
    int n = 500;
    std::vector<std::string> boys(n);
    std::vector<std::string> girls(n);

    for (int i = 0; i < n; i++) {
        boys[i] = generateRandomName();
        girls[i] = generateRandomName();
    }

    std::ofstream writer("in.txt");
    if (writer.is_open()) {
        writer << n << std::endl;
        for (const auto& boy : boys) {
            writer << boy << " ";
        }
        writer << std::endl;
        for (const auto& girl : girls) {
            writer << girl << " ";
        }
        writer << std::endl;

        for (int i = 0; i < n; i++) {
            shuffleArray(girls);
            for (const auto& girl : girls) {
                writer << girl << " ";
            }
            writer << std::endl;
        }

        for (int i = 0; i < n; i++) {
            shuffleArray(boys);
            for (const auto& boy : boys) {
                writer << boy << " ";
            }
            writer << std::endl;
        }

        writer.close();
        std::cout << "Test case generated: in.txt" << std::endl;
    } else {
        std::cerr << "Failed to open file for writing." << std::endl;
    }

    return 0;
}