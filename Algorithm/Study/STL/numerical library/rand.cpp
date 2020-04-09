#include <cstdlib>
#include <ctime>
#include <iostream>

int main() {
    std::srand(std::time(nullptr)); // 以当前时间为随机生成器的种子
    int random_variable = std::rand();
    std::cout << "Random value on [0 " << RAND_MAX << "]: " << random_variable
              << '\n';

    // 扔 6 面色子 20 次
    for (int n = 0; n != 20; ++n) {
        int x = 7;
        while (x > 6)
            x = 1 + std::rand() /
                        ((RAND_MAX + 1u) / 6); // 注意： 1 + rand() % 6 有偏差！
        std::cout << x << ' ';
    }
}