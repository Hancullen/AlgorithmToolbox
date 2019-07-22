#include <iostream>

int get_change(int m) {
    int deno[] = {10 ,5 ,1};

    int c = 0;
    for(int i=0; i < 3; ++i){
      while(m >= deno[i]){
        m -= deno[i];
        c++;
      }
    }
  return c;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
