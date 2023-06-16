// =========================================================
// File: vox.h
// Author: Ethan Luna
// Date: 4/06/2023
// Description: Este es la subclase de la clase Operator
// =========================================================

#ifndef VOXOPERATOR_H
#define VOXOPERATOR_H

#include "operator.h"

class VoxOperator : public Operator {
public:
  VoxOperator(int, double, double, double, int, OperatorType);
  VoxOperator(const VoxOperator&);

  inline double calculateTalkingCost(int, int);
  inline double calculateMessageCost(int, int, int);
  inline double calculateNetworkCost(double);
};

VoxOperator::VoxOperator(int _id, double _costCall, double _costMsg, double _costNtwrk, int _discount, OperatorType _type)
:Operator(_id, _costCall, _costMsg, _costNtwrk, _discount, _type){
};

VoxOperator::VoxOperator(const VoxOperator& other)
  :Operator(other){
};

double VoxOperator::calculateTalkingCost(int minute, int age){
  if (minute < 0 or age <0){
    return 0.0;
  }
  double cost = minute * talkingCharge;
  if(age < 18 or age > 65){
    cost -= cost * (discountRate/100.0);
  }
  return cost;
};

double VoxOperator::calculateMessageCost(int quantity, int thisOPId, int otherOpId){
  if (quantity <= 0){
    return 0.0;
  }
  double cost = quantity * messageCost;
  if(id == otherOpId){
    cost -= cost * (discountRate/100.0);
  }
  return cost;
};

double VoxOperator::calculateNetworkCost(double amount){
  if (amount <0){
    return 0.0;
  }
  return amount * networkCharge;
}

#endif
