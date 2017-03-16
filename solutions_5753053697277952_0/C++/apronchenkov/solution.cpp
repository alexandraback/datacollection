#include <iostream>
#include <string>
#include <vector>
#include <queue>

std::vector<std::string> MakeEvacuationPlan(const std::vector<int>& parties) {
    int total = 0;
    for (int c : parties) {
        total += c;
    }
    for (int c : parties) {
        if (2 * c > total) {
            throw std::logic_error("Invalid input.");
        }
    }

    std::vector<std::string> result;
    auto gen1 = [&](char a) {
        char tmp[2] = {a, '\0' };
        result.emplace_back(tmp);
    };
    auto gen2 = [&](char a, char b) {
        char tmp[3] = {a, b, '\0' };
        result.emplace_back(tmp);
    };

    using Party = std::pair<int, char>;
    std::priority_queue<Party> list;
    auto push = [&](Party party) {
        if (party.first > 0) {
            list.push(party);
        }
    };
    auto pop = [&] {
        if (list.empty()) {
            throw std::logic_error("Fail!");
        }
        auto result = list.top();
        list.pop();
        return result;
    };
    
    
    {
        char name = 'A';
        for (int number : parties) {
            push({number, name});
            ++name;
        }
    }

    auto alpha = pop();
    auto beta = pop();
    while (alpha.first >= beta.first + 2) {
        alpha.first -= 2;
        gen2(alpha.second, alpha.second);
    }
    if (alpha.first > beta.first) {
        alpha.first -= 1;
        if (list.empty()) {
            gen1(alpha.second);
        } else {
            auto tmp = pop();
            gen2(alpha.second, tmp.second);
            tmp.first--;
            push(tmp);
        }
    }

    while (!list.empty()) {
        auto tmp = pop();
        auto a = tmp.second;
        tmp.first--;
        push(tmp);
        if (list.empty()) {
            gen1(a);
        } else {
            tmp = pop();
            auto b = tmp.second;
            tmp.first--;
            push(tmp);
            gen2(a, b);
        }
    }

    while (alpha.first > 0) {
        gen2(alpha.second, beta.second);
        alpha.first--;
    }

    return result;
}

int main() {
    int number_of_cases;
    std::cin >> number_of_cases;
    for (int case_no = 0; case_no < number_of_cases; ++case_no) {
        int number_of_parties;
        std::cin >> number_of_parties;
        std::vector<int> parties(number_of_parties);
        for (auto& party : parties) {
            std::cin >> party;
        }
        std::cout << "Case #" << (case_no + 1) << ":";
        for (const auto& action : MakeEvacuationPlan(parties)) {
            std::cout << " " << action;
        }
        std::cout << "\n";
    }
    return 0;
}
