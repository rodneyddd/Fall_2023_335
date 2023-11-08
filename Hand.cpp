#include "Hand.hpp"

/**
    * @post: Construct a new Hand object
*/
Hand::Hand(){
}

/**
    * @post: Destroy the Hand object
*/
Hand::~Hand(){
}

 /**
    * Copy Constructor
    * @param: other Hand object
*/
Hand::Hand(const Hand& other){
    this->hand.clear();

    for(auto card : other.hand)
        this->hand.push_back(card);
}

/**
* Copy Assignment Operator
* @param: other Hand object
* @return this Hand
*/
Hand& Hand::operator=(const Hand& other){
    this->hand.clear();

    for(auto card : other.hand)
        this->hand.push_back(card);
    
    return *this;
}

/**
* Move Constructor
* @param: other Hand object
*/
Hand::Hand(Hand&& other){
    this->hand = std::move(other.hand);
}
/**
* Move assignment operator
* @param: other Hand object
* @return this Hand
*/
Hand& Hand::operator=(Hand&& other){
    this->hand = std::move(other.hand);
    return *this;
}

/**
* @return Hand
*/
const std::deque<PointCard>& Hand::getCards() const{
    return hand;
}

/**
* @post: Add a card to the hand
* @param PointCard object
*/
void Hand::addCard(PointCard&& card){
    this->hand.push_back(card);
}

/**
* @return true if hand is empty, false otherwise
*/
bool Hand::isEmpty() const{
    if(hand.size() == 0)
        return true;

    return false;
}

/**
* @post: Reverse the hand
*/
void Hand::Reverse(){
    std::reverse(hand.begin(), hand.end());
}

/**
* @post: Play the card at the front of the hand, removing it from the
hand
* Throws an exception if the hand is empty or the card is not playable
* If the card is not playable, the card is removed from the hand
* @return the points earned from playing the card
*/
int Hand::PlayCard(){
    int res = *hand[0].getImageData();
    hand.pop_front();
    return res;
}
