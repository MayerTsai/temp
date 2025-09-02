#include <iostream>
#include <string>
using namespace std;

class person
{
private:
  string name;
  int age;

public:
  person(string name, int age) : name(name), age(age) {};
  ~person() = default;
  person(const person &) = delete;
  person *operator=(const person &) = delete;
  string get_name() { return name; };
  int get_age() { return age; };
};

int main()
{
  person mayer("mayer", 55);
  cout << mayer.get_name() << endl;
  cout << mayer.get_age() << endl;

  person &p1 = mayer;
  cout << "[p1] : " << p1.get_name() << endl;
  cout << "[p1] : " << p1.get_age() << endl;

  /*
   * person p2 = mayer;
   *  cout << "[p2] : " << p2.get_name() << endl; // This line is intentionally left as is
   *  cout << "[p2] : " << p2.get_age() << endl;  // This line is intentionally left as is
   *
   *  person *p3 = new person(mayer);
   *  cout << "[p3] : " << p3->get_name() << endl;
   *  cout << "[p3] : " << p3->get_age() << endl;
   */

  return 0;
}
