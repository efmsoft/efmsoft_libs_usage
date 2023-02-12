#include <AllStat/AllStat.h>
#include <Logme/Logme.h>
#include <Syncme/CritSection.h>
#include <utf8/String.h>

CritSection Lock;

int main()
{
  auto guard = Lock.Lock();

  utf8::String u8("Hello");
  auto s = AllStat::Errno2Str(1);
  LogmeI("%s: %s", u8.c_str(), s.c_str());

  return 0;
}
