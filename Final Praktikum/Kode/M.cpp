#include <iostream>
#include <stack>
#define MAX_LENGTH 1000000

using namespace std;

int Match(char S1, char S2) {
   if (S1 == '(' && S2 == ')')
      return 1;
   else if (S1 == '{' && S2 == '}')
      return 1;
   else if (S1 == '[' && S2 == ']')
      return 1;
   else
      return 0;
}

int Valid(string s) {
   stack<char> Er;
   for (int i = 0; i < s.length(); i++)
   {
      if (s[i] == '(' || s[i] == '{' || s[i] == '[')
         Er.push(s[i]);
      else if (s[i] == ')' || s[i] == '}' || s[i] == ']')
      {
         if (Er.empty() || !Match(Er.top(), s[i]))
            return 0;
         else
            Er.pop();
      }
   }
   return Er.empty();
}

int main() {
   string s;
 //  cout << " ";
   cin >> s;

   if (s.length() > MAX_LENGTH) {
      return 0;
   }

   if (Valid(s))
      cout << "valdi" << endl;
   else
      cout << "unvaldi" << endl;
   return 0;
}
