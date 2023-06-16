// =========================================================
// File: operator.h
// Author: Ethan Luna Cadó
// Date: 03/06/2023
// Description: Clase del Operador
// =========================================================

#ifndef OPERATOR_H
#define OPERATOR_H

#include <string>
#include <sstream>
#include <iomanip>

typedef enum{VOX, INTERNET} OperatorType;

class Operator {
protected:
  int id, discountRate;
  double talkingCharge, messageCost, networkCharge, totalInternetUsage;
  int totalSpentTalkingTime, totalMessageSent;
  OperatorType type;

public:
  Operator(int id, double , double, double, int, OperatorType);
  Operator(const Operator&);

  inline int getId() const;
  inline int getDiscountRate() const;
  inline double getTalkingChage() const;
  inline double getMessageCost() const;
  inline double getNetworkCharge() const;
  inline int getTotalSpentTalkingTime() const;
  inline int getTotalMessageSent() const;
  inline double getTotalInternetUsage() const;
  inline OperatorType getType() const;


  void addTalkingTime(int);
  void addTotalMessageSent(int);
  void addTotalInternetUsage(double);

  std::string toString() const;

  virtual double calculateTalkingCost(int, int) = 0;
  virtual double calculateMessageCost(int, int, int) = 0;
  virtual double calculateNetworkCost(double) = 0;
};

Operator::Operator(int _id, double _costCall, double _costMsg, double _costNtwrk, int _discount, OperatorType _type){
  id = _id;
  discountRate = _discount;
  talkingCharge = _costCall;
  messageCost = _costMsg;
  networkCharge = _costNtwrk;
  type= _type;
  totalSpentTalkingTime = 0;
  totalMessageSent = 0;
  totalInternetUsage = 0;
};

Operator::Operator(const Operator& other){
  id = other.id;
  discountRate = other.discountRate;
  talkingCharge = other.talkingCharge;
  messageCost = other.messageCost;
  networkCharge = other.networkCharge;
  type = other.type;
  totalSpentTalkingTime = other.totalSpentTalkingTime;
  totalMessageSent = other.totalMessageSent;
  totalInternetUsage = other.totalInternetUsage;
};

int Operator::getId() const{
  return id;
}

int Operator::getDiscountRate() const{
  return discountRate;
}

double Operator::getTalkingChage() const{
  
  return talkingCharge;
}

double Operator::getMessageCost() const{
  return messageCost;
}

double Operator::getNetworkCharge() const{
  return networkCharge;
}

int Operator::getTotalSpentTalkingTime() const{
  return totalSpentTalkingTime;
}

int Operator::getTotalMessageSent() const{
  return totalMessageSent;
}

double Operator::getTotalInternetUsage() const{
  return totalInternetUsage;
}

OperatorType Operator::getType() const{
  return type;
}

void Operator::addTalkingTime(int minute){
  if (minute > 0){
     totalSpentTalkingTime += minute;
  }
};

void Operator::addTotalMessageSent(int num){
  if (num > 0){
     totalMessageSent += num;
  }
};

void Operator::addTotalInternetUsage(double amount){
  if (amount > 0.0){
     totalInternetUsage += amount;
  }

};

std::string Operator::toString() const{
 std::ostringstream str;
 str << "Operator #" << id <<" : " << std::fixed <<std::setprecision(2) <<totalSpentTalkingTime <<std::fixed <<std::setprecision(2)<< totalMessageSent << std::fixed <<std::setprecision(2) <<totalInternetUsage;
 return str.str(); 
};



#endif
