#include <algorithm>
#include <iostream>
#include <iterator>
#include <stack>
#include <stdexcept>
#include <string>
#include <vector>
#include <cmath>

auto make_args(int argc, char* argv[], bool const with_exec = false)
    -> std::vector<std::string>
{
    auto args         = std::vector<std::string>{};
    auto const offset = static_cast<size_t>(not with_exec);
    std::copy_n(argv + offset, argc - offset, std::back_inserter(args));
    return args;
}

auto main(int argc, char* argv[]) -> int
{
    using student::rpn_calculator::Calculator;
    auto calculator = Calculator{};

    for (auto const& each : make_args(argc, argv)) {
        try {
			calculator.push(each);
        } catch (std::logic_error const& e) {
            std::cerr << "error: " << each << ": " << e.what() << "\n";
        }
    }

    try {
        calculator.evaluate();
    } catch (std::logic_error const& e) {
        std::cerr << "error: during evaluation: " << e.what() << "\n";
    }

    return 0;
}
