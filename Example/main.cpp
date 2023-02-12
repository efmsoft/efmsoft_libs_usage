#include <AllStat/AllStat.h>
#include <Logme/Logme.h>
#include <Syncme/CritSection.h>
#include <utf8/String.h>

CritSection Lock;

int main()
{
  // Do not look for meaning in the code below. 
  // We just referenced a function from each library

  auto guard = Lock.Lock();

  utf8::String u8("Hello");
  auto s = AllStat::Errno2Str(1);
  LogmeI("%s: %s", u8.c_str(), s.c_str());

  return 0;
}
