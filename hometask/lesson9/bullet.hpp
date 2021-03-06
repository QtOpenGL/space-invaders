#pragma once

#include "settings.hpp"
#include "game_entity.hpp"

class Bullet: public GameEntity
{
public:
  // Operator <<
  friend std::ostream & operator << (std::ostream & os, Bullet const & obj);

  // Constructor
  Bullet(float x, float y, bool fromPlayer)
    : m_fromPlayer(fromPlayer)
  {
    // Dimensions
    m_width = Settings::bulletWidth;
    m_height = Settings::bulletHeight;
    // Coords
    if (fromPlayer)
      m_position = {x - m_width / 2, y - m_height};
    else
      m_position = {x - m_width / 2, y};
  }

  // Functionality
  void Move()
  {
    if (m_fromPlayer)
      GameEntity::Move(GameEntity::MOVE_UP);
    else
      GameEntity::Move(GameEntity::MOVE_DOWN);
  }

  bool m_fromPlayer;
};

inline std::ostream & operator << (std::ostream & os, Bullet const & obj)
{
  os << "Bullet" << ": {"
     << "Position: " << obj.m_position
     << ", Speed: " << obj.m_speed
     << ", FromPlayer: " << obj.m_fromPlayer
     << "}";
  return os;
}