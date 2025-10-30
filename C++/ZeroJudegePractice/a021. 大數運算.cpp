#include<iostream>
#include<string>
std::string plus_sign(const std::string &a, const std::string &b);
std::string minus_sign(const std::string &a, const std::string &b);
std::string multiply_sign(const std::string &a, const std::string &b);
std::string divide_sign(const std::string &a, const std::string &b);
int main() {
    std::string operand1, operand2;
    char input_operator;
    while(std::cin>>operand1>>input_operator>>operand2) {
        switch(input_operator){
            case '+':
                std::cout << plus_sign(operand1, operand2) << std::endl;
                break;
            case '-':
                std::cout << minus_sign(operand1, operand2) << std::endl;
                break;
            case '*':
                std::cout << multiply_sign(operand1, operand2) << std::endl;
                break;
            case '/':
                std::cout << divide_sign(operand1, operand2) << std::endl;
                break;
            default:
                std::cout << "Invalid operator" << std::endl;
                break;
        }
    }
    return 0;
}
std::string plus_sign(const std::string &a, const std::string &b){
    std::reverse(a.begin(), a.end());
    std::reverse(b.begin(), b.end());
    std::string result;
    int carry = 0;
    int maxLength = std::max(a.length(), b.length());
    for (int i = 0; i < maxLength; ++i) {
        int digitA = (i < a.length()) ? a[i] - '0' : 0;
        int digitB = (i < b.length()) ? b[i] - '0' : 0;
        int sum = digitA + digitB + carry;
        carry = sum / 10;
        result.push_back((sum % 10) + '0');
    }
}
std::string minus_sign(const std::string &a, const std::string &b){
    std::reverse(a.begin(), a.end());
    std::reverse(b.begin(), b.end());
    std::string result;
    int borrow = 0;
    for (size_t i = 0; i < a.length(); ++i) {
        int digitA = a[i] - '0' - borrow;
        int digitB = (i < b.length()) ? b[i] - '0' : 0;
        if (digitA < digitB) {
            digitA += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        result.push_back((digitA - digitB) + '0');
}
std::string multiply_sign(const std::string &a, const std::string &b){
    
}
std::string divide_sign(const std::string &a, const std::string &b){

}