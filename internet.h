// =========================================================
// File: internet.h
// Author: Ethan Luna
// Date: 4/06/2023
// Description: Este es la subclase de la clase Operator
// =========================================================

#ifndef InternetOperator_H
#define InternetOperator_H

#include "operator.h"

class InternetOperator : public Operator {
private:
  const double LIMITGB = 1.0;

public:
  InternetOperator(int, double, double, double, int, OperatorType);
  InternetOperator(const InternetOperator&);

  double calculateTalkingCost(int, int);
  double calculateMessageCost(int, int, int);
  double calculateNetworkCost(double);
};

InternetOperator::InternetOperator(int _id, double _costCall, double _costMsg, double _costNtwrk, int _discount, OperatorType _type):Operator(_id, _costCall, _costMsg, _costNtwrk, _discount, _type){};

InternetOperator::InternetOperator(const InternetOperator& other):Operator(other){}

double InternetOperator::calculateTalkingCost(int minute, int age){
  if (minute < 0 or age <0){
    return 0.0;
  }
  if(minute < 2){
    return (minute * talkingCharge) - (minute * talkingCharge)*(discountRate/100.0);
  }
  return minute*talkingCharge;
};

double InternetOperator::calculateMessageCost(int quantity, int thisOPId, int otherOpId){
  if (quantity <0){
    return 0.0;
  }
  double cost = quantity * messageCost;
  if(quantity < 3){
    cost -= cost * (discountRate/100.0);
    return cost;
  }else{
    return cost;
  }
};


double InternetOperator::calculateNetworkCost(double amount){
  if (amount <= 0){
    return 0.0;
  }

  if(amount > 1){
      return (amount-LIMITGB) * networkCharge;
  }else{
    return 0;
  }
}



#endif
