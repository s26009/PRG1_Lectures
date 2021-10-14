#include <iostream>
#include <string>


int ask_user_for_integer ( std :: string prompt )
{
std :: cout << prompt << " int :";
auto n = std :: string {};
std :: getline ( std :: cin , n);
return std :: stoi (n);
}

int main ()
{
auto const a = ask_user_for_integer ("a = ");
auto const b = ask_user_for_integer ("b = ");
std :: cout << (a * b) << "\n";
return 0;
}

