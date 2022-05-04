#ifndef INTERPRETATOR_H
#define INTERPRETATOR_H
struct Var
{
    std::string name{};
    int value{};
};
struct Str
{
    std::string name{};
    std::string value{};
};
struct Alg
{
    std::string name{};
    bool value{};
};
Str str_definition(std::string str);
Var var_definition(std::string str);
Alg alg_definition(std::string str);
std::string string_operation(Str strs[] , std::string name_test , std::string str);
bool if_statement(std::string str , Var numbers[]);
void data_output(std::string str, Var numbers[] , Str strs[] , Alg algs[]);
int math_operation (Var numbers[] , std::string name_test, std::string str);
#endif