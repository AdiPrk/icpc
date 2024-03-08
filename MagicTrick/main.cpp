#include <iostream>
#include <vector>

enum Operation {
    ADD = 1,
    SUBTRACT,
    MULTIPLY,
    DIVIDE
};

struct Action {
    Operation op;
    int operand;
};

int main() {
    // apparently speeds up io operations //
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    // ---------------------------------- //

    int n;
    std::cin >> n;

    std::vector<Action> operations(n);
    operations.reserve(n);
    std::string op;
    int operand;

    // Read the operations
    for (int i = 0; i < n; ++i) {
        std::cin >> op >> operand;
        if (op == "ADD") operations.push_back({ ADD, operand });
        else if (op == "SUBTRACT") operations.push_back({ SUBTRACT, operand });
        else if (op == "MULTIPLY") operations.push_back({ MULTIPLY, operand });
        else if (op == "DIVIDE") operations.push_back({ DIVIDE, operand });
    }

    int count = 0;
    // Test each number from 1 to 100
    for (int k = 1; k <= 100; ++k) {
        int result = k;
        bool messedUp = false;

        // Apply each operation in order
        for (const Action& action : operations) {
            switch (action.op) {
            case ADD:
                result += action.operand;
                break;
            case SUBTRACT:
                result -= action.operand;
                if (result < 0) { // Check for negative result
                    messedUp = true;
                }
                break;
            case MULTIPLY:
                result *= action.operand;
                break;
            case DIVIDE:
                if (result % action.operand != 0) { // Check for fraction
                    messedUp = true;
                }
                else {
                    result /= action.operand;
                }
                break;
            }
            if (messedUp) {
                break; // No need to perform further operations
            }
        }

        if (messedUp) {
            count++;
        }
    }

    // Output the count of numbers that result in a negative number or a fraction
    std::cout << count;

    return 0;
}
