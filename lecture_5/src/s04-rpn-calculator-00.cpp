/*
 * A reverse-polish notation calculator.
 */

#include "include/RPN_calculator.h"

#include <algorithm>
#include <iostream>
#include <iterator>
#include <stack>
#include <stdexcept>
#include <string>
#include <vector>
#include <cmath>


static auto pop_top(std::stack<double>& stack) -> double
{
    if (stack.empty()) {
        throw std::logic_error{"empty stack"};
    }
    auto element = std::move(stack.top());
    stack.pop();
    return element;
}


namespace student { namespace rpn_calculator {
Element::~Element()
{}

Literal::Literal(double const v) : value{v}
{}
auto Literal::evaluate(stack_type& stack) const -> void
{
    stack.push(value);
}

auto Print::evaluate(stack_type& stack) const -> void
{
    std::cout << stack.top() << "\n";
}

auto Addition::evaluate(stack_type& stack) const -> void
{
    if (stack.size() < 2) {
        throw std::logic_error{"not enough operands for +"};
    }
    auto const b = pop_top(stack);
    auto const a = pop_top(stack);
    stack.push(a + b);
}

auto Subtraction::evaluate(stack_type& stack) const -> void
{
    if (stack.size() < 2) {
        throw std::logic_error{"not enough operands for -"};
    }
    auto const b = pop_top(stack);
    auto const a = pop_top(stack);
    stack.push(a - b);
}

auto Multiplication::evaluate(stack_type& stack) const -> void
{
    if (stack.size() < 2) {
        throw std::logic_error{"not enough operands for *"};
    }
    auto const b = pop_top(stack);
    auto const a = pop_top(stack);
    stack.push(a * b);
}

auto Division::evaluate(stack_type& stack) const -> void
{
    if (stack.size() < 2) {
        throw std::logic_error{"not enough operands for /"};
    }
    auto const b = pop_top(stack);
    auto const a = pop_top(stack);
    stack.push(a / b);
}

auto DivisionWhole::evaluate(stack_type& stack) const -> void
{
    if (stack.size() < 2) {
        throw std::logic_error{"not enough operands for //"};
    }
    auto const b = (int) pop_top(stack);
    auto const a = (int) pop_top(stack);
    stack.push(a / b);
}

auto Remainder::evaluate(stack_type& stack) const -> void
{
    if (stack.size() < 2) {
        throw std::logic_error{"not enough operands for %"};
    }
    auto const b = (int) pop_top(stack);
    auto const a = (int) pop_top(stack);
    stack.push(a % b);
}

auto Exponentiation::evaluate(stack_type& stack) const -> void
{
    if (stack.size() < 2) {
        throw std::logic_error{"not enough operands for **"};
    }
    auto const b = pop_top(stack);
    auto const a = pop_top(stack);
    stack.push(pow(a, b));
}

auto SquareRoot::evaluate(stack_type& stack) const -> void
{
    if (stack.size() < 1) {
        throw std::logic_error{"not enough operands for sqrt"};
    }
    auto const a = pop_top(stack);
    stack.push(sqrt(a));
}

auto Factorial::evaluate(stack_type& stack) const -> void
{
    if (stack.size() < 1) {
        throw std::logic_error{"not enough operands for /"};
    }
    auto const a = (int) pop_top(stack);

	int factorial;
	if (a >= 0) {
		factorial = 1;
		for(int i = 1; i <= a; ++i) {
			factorial *= i;
		}
	}
    stack.push(factorial);
}

Calculator::Calculator(stack_type s) : stack{std::move(s)}
{}

auto Calculator::push(std::unique_ptr<Element> op) -> void
{
    ops.push(std::move(op));
}

auto Calculator::push(std::string arg) -> void
{
    if (arg == "p") {
		push(std::make_unique<Print>());
	} else if (arg == "+") {
		push(std::make_unique<Addition>());
	} else if (arg == "-") {
		push(std::make_unique<Subtraction>());
	} else if (arg == "*") {
		push(std::make_unique<Multiplication>());
	} else if (arg == "/") {
		push(std::make_unique<Division>());
	} else if (arg == "//") {
		push(std::make_unique<DivisionWhole>());
	} else if (arg == "%") {
		push(std::make_unique<Remainder>());
	} else if (arg == "**") {
		push(std::make_unique<Exponentiation>());
	} else if (arg == "sqrt") {
		push(std::make_unique<SquareRoot>());
	} else if (arg == "!") {
		push(std::make_unique<Factorial>());
	} else {
		push(std::make_unique<Literal>(std::stod(arg)));
	}
}

auto Calculator::evaluate() -> void
{
    while (not ops.empty()) {
        auto op = std::move(ops.front());
        ops.pop();

        op->evaluate(stack);
    }
}
}}  // namespace student::rpn_calculator


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
