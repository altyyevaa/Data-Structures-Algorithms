//program that returns whether a string is balanced or not
  #include <iostream>
  #include <string>
  #include <stack>

  using namespace std;
  //checks if a symbol is in the string of "{[("
  bool inString(string symbol, string symbols){
      return symbols.find(symbol) != string::npos;
  }
  //function that returns a boolean value based on whether the strings match
  bool matches(string open, string close){
      string opens = "({[";
      string closers = ")]}";
      bool val = inString(open, opens) == inString(close, closers);
      return val;
  }

  bool parChecker(string symbolString){
      stack<string> s;
      bool balanced = true;
      int index = 0;
      int symbolLength = symbolString.length();

      while(index < symbolLength && balanced){
          string symbol;
          symbol = symbolString[index];
          string opens = "([{";
          string closes = "}])";
          if (inString(symbol, opens)){
              s.push(symbol);
          } else if(inString(symbol, closes)){
              if (s.empty()){
                  balanced = false;
              } else {
                  string top = s.top();
                  s.pop();
                  if (!matches(top, symbol)){
                      balanced = false;
                      break;
                  }
              }
          }
          index = index + 1;
      }
      if(balanced && s.empty()){
          return true;
      } else {
          return false;
      }
  }

  int main() {
      cout << parChecker("{}") << endl;
      cout << parChecker("[{()}]") << endl;
      return 0;
  }
