#ifndef _AUCTION_H
#define _AUCTION_H


enum class Items{};

class auction
{
    
    public:
    Items getsellingitem(); 
    int getsellingprice();

};

class seller
{
    public:
    float amounttoseller();

};

class bidder
{
    public:
    bool willingnessforitem();
    int bidder_upperlimit();

};



#endif