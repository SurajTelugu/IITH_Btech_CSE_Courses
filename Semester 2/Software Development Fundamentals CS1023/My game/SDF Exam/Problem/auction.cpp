#include "auction.h"
#include <string>

/*
* Let there be 3 sellers each selling 3 different items
* 
* Minimum Amount for Item1  = 50
* Minimum Amount for Item2  = 80
* Minimum Amount for Item3  = 100
*
* Auction takes commission,40% of every item sold and remaining 30% is given to the Seller
*
* Bidder : Lets assume there are 2 bidders 
* Bidder  Budget  | Upper limit for Item1 | Upper limit for Item2 | Upper limit for Item3 |
* Bidder1   450   |       100             |        150            |       180             |
* Bidder2   550   |       110             |        170            |       230             |
*
* For Bidding:
* Minmum Threshold Item1 = 70 
* Minmum Threshold Item1 = 120
* Minmum Threshold Item1 = 140
* Bidding begins at : At least 10% of the threshold
*
*
*/

enum class Items {Item1,Item2,Item3};
enum class Bidder{Bidder1,Bidder2};

class auction
{
    Items SellingItem;
    int thresholdprice[3]={70,120,140};
    int sellingprice;

    public:
    Items getsellingitem() {return SellingItem;};
    int getsellingprice(){return sellingprice;};

  


};

class seller : public auction
{
    std::string seller1 = "Seller1"; 
    std::string seller2 = "Seller2"; 
    std::string seller3 = "Seller3"; 
    int MinItemcost[3] = {50,80,100};

    public:
    float amounttoseller()
    {
        return 0.6*auction::getsellingprice() ;
    }


};

class bidder
{
  Bidder B;
  Items  I;

  public:
  
  bidder bidder(Bidder _B,Items _I)  // working on constructor
  {
      _B = B;
      _I = I;
  }

  int Budget;
  int Upperlimit[3];
  int Selected_Upperlimit;

  int Bidder_Upper_Limit()
  {
  if(B==Bidder::Bidder1)
  {
      int Budget = 450;
      int Upperlimit[3] = {100,150,180} ;     
  }

  if(B==Bidder::Bidder1)
  {
      int Budget = 550;
      int Upperlimit[3] = {110,150,180};     
  }

   return Selected_Upperlimit;
  }

};