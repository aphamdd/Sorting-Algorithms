#pragma once
#include "LLNode.h"

// handles linked list operations
class LinkedList {
public:
  LinkedList(sf::RenderWindow& win, sf::Text& text);
  ~LinkedList();
  void clear();

  void add();
  bool remove();
  void insert();

  LLNode* search(const sf::Vector2i mpos); // find what node im clicking
  void updatePrev(); // moves mPrev to the node behind mActive
  bool move(const sf::Vector2i mpos); // handles LLNode positioning
  bool isInBounds(const sf::Vector2i mpos) const; // checks if mouse is inside mActive Node
  bool findValue(const int val);
  void updateCursor();

  void draw() const;

private:
  bool findNodeBounds();
  void resetState();

 // TODO: composition, compose some of this stuff into structs or delegate to other classes
public:
  sf::CircleShape cursor;
  LLNode* mActive =  nullptr; // the active selected node
  sf::Clock delayClock;

private:
  std::vector<sf::FloatRect> nBounds; // vector of all node bounds

  // TODO: maybe make a vector of LLNode* head ptrs?
  LLNode* mHead = nullptr;
  LLNode* mPrev = nullptr; // handles the previous next pointer line

  LLNode* mLastActive = nullptr; // the last node active was on

  // LinkedList Operation Animation State Machine
  enum class LLState {
    ENTRY,
    HIGHLIGHT,
    WAIT,
    COMPARE,
    RESET
  };
  LLState state = LLState::ENTRY;
  LLState prevState = LLState::ENTRY;
  LLNode* mStatePtr = nullptr;


  sf::RenderWindow& window; // DI
  sf::Text LLText; // passes in text object into LLNode
};
