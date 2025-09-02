#include <string>
#include <vector>
#include <sstream> // Required for std::stringstream
#include <iostream>
#include <cstdlib>

std::vector<std::string> splitStringStream(const std::string &str, char delimiter)
{
  std::vector<std::string> tokens;
  std::stringstream ss(str);
  std::string token;
  while (std::getline(ss, token, delimiter))
  {
    tokens.push_back(token);
  }
  return tokens;
}

std::string getEnv(const std::string &name, char *envp[])
{
  std::string ret;
  for (int i = 0; envp[i] != NULL; i++)
  {
    std::string text = std::string(envp[i]);
    char delimiter = '=';
    std::vector<std::string> colors = splitStringStream(text, delimiter);
    if (colors[0] != name)
      continue;
    else
    {
      ret = colors[1];
      break;
    }
  }
  return ret;
}

int main(int argc, char const *argv[], char *envp[])
{
  std::string str = getEnv("PATH", envp);
  std::cout << "getENV:" << str << std::endl;

  str = getenv("PATH");
  std::cout << "getenv:" << str << std::endl;

  char delimiter = ':';
  std::vector<std::string> colors = splitStringStream(str, delimiter);
  for (const std::string &color : colors)
    std::cout << color << std::endl;

  return 0;
}
