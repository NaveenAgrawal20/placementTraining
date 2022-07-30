#include <iostream>
#include <limits>

int main() {
    std::cout << std::numeric_limits<long long int>::max();
}

/*
Input 1
5 6
2 3
2 4
2 5
3 4
3 5
4 5

Output 1
NO

Input 2
6 4
2 3
3 4
4 5
5 6

Output 2
YES
Sample test case explanation
In the first example, you can't choose any x, y because for each such pair you can find a given pair where both numbers are different from chosen integers.In the second example, you can choose x=5 and y=3, because either x or y is present in all the pairs.
*/