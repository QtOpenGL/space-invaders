#pragma once

#include <unordered_map>
#include "settings.hpp"

class ActionManager
{
public:
  ActionManager()
  {
    m_keys[101] = KEY_UP;  // Up arrow / e
    m_keys[100] = KEY_LEFT;  // Left arrow / d
    m_keys[103] = KEY_DOWN;  // Down arrow / g
    m_keys[102] = KEY_RIGHT;  // Right arrow / f

    m_keys[32] = KEY_SHOOT;  // Space
    m_keys[13] = KEY_ENTER;  // Enter
    m_keys['P'] = KEY_PAUSE;
    m_keys['p'] = KEY_PAUSE;
    m_keys[27] = KEY_QUIT;  // Esc
    m_keys['Q'] = KEY_QUIT;
    m_keys['q'] = KEY_QUIT;
  }

  char GetActionByKey(char key)
  {
    auto it = m_keys.find(key);
    return it != m_keys.end() ? it->second : -1;
  }

  enum Keys {KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT, KEY_SHOOT, KEY_ENTER, KEY_PAUSE, KEY_QUIT};
private:
  std::unordered_map<char, char> m_keys;
};