#include <SFML/Graphics.hpp>

#include "manager.h"

int main(int argc, char *argv[]) {
  Manager manager;
  manager.startKeyListenerThread();
  manager.mainLoop();

  return 0;
}
