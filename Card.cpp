#include "Card.hpp"

//destructor
Card::~Card(){
    delete[] bitmap_;
    instruction_ = "";
    drawn_ = false;
    cardType_ = POINT_CARD;
}

//copy constructor
Card::Card(const Card& rhs){
    bitmap_= new int{*rhs.bitmap_};
    cardType_ = rhs.cardType_;
    instruction_ = rhs.instruction_;
    drawn_= rhs.drawn_;
    

}//copy assignment operator
Card& Card::operator=(const Card& rhs){
    
    *bitmap_= *rhs.bitmap_;
    cardType_ = rhs.cardType_;
    instruction_ = rhs.instruction_;
    drawn_= rhs.drawn_;
    

    return *this;
}

Card::Card(Card&& rhs) : cardType_{std::move(rhs.cardType_)},instruction_{std::move(rhs.instruction_)},bitmap_{rhs.bitmap_},drawn_{std::move(rhs.drawn_)}{}


Card& Card::operator=(Card&& rhs){
    cardType_ = rhs.cardType_;
    bitmap_ = rhs.bitmap_;
    drawn_ = rhs.drawn_;
    instruction_ = rhs.instruction_;
   
   return *this;

}

Card::Card(){
    bitmap_ = nullptr;
    instruction_ = "";
    drawn_ = false;
    cardType_ = POINT_CARD;
}

std::string Card::getType() const{
    if (cardType_== POINT_CARD)
        return "POINT_CARD";
    else
        return "ACTION_CARD";
}

void Card::setType(const CardType& type){
    cardType_= type;
}

 const std::string& Card::getInstruction() const{
    return instruction_;
}

void Card::setInstruction(const std::string& instruction){
    instruction_= instruction;
}

const int* Card::getImageData() const{
    return bitmap_;
}

void Card::setImageData(int* data){
    bitmap_ = data;
}

bool Card::getDrawn() const{
    return drawn_;
}

void Card::setDrawn(const bool& drawn){
    drawn_ = drawn;
}
