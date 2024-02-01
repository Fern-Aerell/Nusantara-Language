#include <iostream>
#include <string>
#include <utils.h>
int main(int argc, char *argv[])
{
  if(argc > 1) {
    std::string content = utils::readFile(argv[1]);
    std::cout << content << "\n";
  }
  return 0;
}
