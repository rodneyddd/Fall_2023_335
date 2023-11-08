#include "PointCard.hpp"

PointCard::PointCard():Card(){
setType(POINT_CARD);
}
 /**
         * @return true if the card is playable, false otherwise
         * For a card to be playable, it has to be drawn and the instruction has to be a valid number
        */
bool PointCard::isPlayable(){
    // if card is not drawn it is not playable
    if(getDrawn()== false){
        return false;
    }
    std::regex pattern("([0-9][0-9])");
    return (std::regex_match(getInstruction(),pattern));

   
}
/**
         * @post: Print the Point Card in the following format:
         * Type: [CardType]
         * Points: [Instruction]
         * Card: 
         * [ImageData]
         * 
         * Note: For [ImageData]: If there is no image data, print "No image data" instead
         */
void PointCard::Print() const{
     std::cout<< "Type: "<< getType() << std::endl
    <<"Points: "<< getInstruction()<< std::endl<<"Card:  "<<std::endl;
    if (getImageData() == nullptr){
        std::cout<<"No image data";
    }
    else {std::cout<<getImageData();}

}