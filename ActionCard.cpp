#include "ActionCard.hpp"

ActionCard::ActionCard():
Card()
{
    setType(ACTION_CARD);

}
/**
         * @return true if the card is playable, false otherwise
         * For a card to be playable, it has to be drawn and the instruction has to be valid
         * Valid instructions:
         * DRAW x CARD(S) : assume x is a positive integer
         * PLAY x CARD(S) : assume x is a positive integer
         * REVERSE HAND : reverse the order of the cards in the hand
         * SWAP HAND WITH OPPONENT : swap the hand with the opponent
        */
bool ActionCard::isPlayable() {
    if (!getDrawn())
        return false;
    
    std::regex pattern("((PLAY|DRAW) [0-9][0-9] (CARD|CARDS))");
    if(getInstruction()== "REVERSE HAND" or getInstruction()== "SWAP HAND WITH OPPONENT" or std::regex_match(getInstruction(),pattern) )
        return true;
    
    else
        return true;

}

 /**
         * @post: Print the ActionCard in the following format:
         * Type: [CardType]
         * Instruction: [Instruction]
         * Card: 
         * [ImageData]
         * 
         * Note: For [ImageData]: If there is no image data, print "No image data" instead
         */
void ActionCard::Print() const{
    std::cout << "Type: "<< getType() << std::endl <<"Instruction: "<< getInstruction()<< std::endl<<"Card:  "<<std::endl;
    if (getImageData() == nullptr){
        std::cout<<"No image data";
    }
    else {std::cout<<getImageData();}
}