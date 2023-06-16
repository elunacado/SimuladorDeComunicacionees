// =========================================================
// File: customer.h
// Author: Ethan Luna Cadó
// Date: 06/06/2023
// Description: Clase para el customer
// =========================================================
#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <sstream>
#include <iomanip>
#include "bill.h"
#include "operator.h"

class Customer {
private:
  int id, age, totalSpentTalkingTime, totalMessageSent, totalInternetUsage;
  std::string name;
  Operator* op;
  Bill *bill;

public:
  Customer(int, std::string, int, Operator*, double);
  Customer(const Customer&);
  ~Customer();

  inline int getId() const;
  inline int getAge() const;
  inline int getTotalSpentTalkingTime() const;
  inline int getTotalMessageSent() const;
  inline double getTotalInternetUsage() const;
  inline std::string getName() const;
  inline Operator* getOperator() const;
  inline Bill* getBill() const;

  inline void setOperator(Operator*);

  inline std::string toString() const;

  inline void talk (int, Customer&);
  inline void message(int, const Customer&);
  inline void connection(double);
  inline void pay(double);
};

Customer::Customer(int _id, std::string _name,int _age,Operator* _op,double _credit){
  id = _id;
  name = _name;
  age = _age;
  op = _op;
  bill=new Bill(_credit);

  totalInternetUsage = 0.0;
  totalMessageSent = 0.0;
  totalSpentTalkingTime = 0.0;

};

//Constructor de Copia
Customer::Customer(const Customer& other){
  id = other.id;
  name = other.name;
  age = other.age;
  op = other.op;
  bill=new Bill(*other.bill);

  totalInternetUsage = other.totalInternetUsage;
  totalMessageSent=other.totalMessageSent;
  totalSpentTalkingTime=other.totalSpentTalkingTime;
};

Customer::~Customer(){
  delete bill;
  op = nullptr;
  bill = nullptr;
}

int Customer::getId() const{
  return id;
}

int Customer::getAge() const{
  return age;
}

int Customer::getTotalSpentTalkingTime() const{
  return totalSpentTalkingTime;
}

int Customer::getTotalMessageSent() const{
  return totalMessageSent;
}

double Customer::getTotalInternetUsage() const{
  return totalInternetUsage;
}

std::string Customer::getName() const{
  return name;
}

Operator* Customer::getOperator() const{
  return op;
}

Bill* Customer::getBill() const {
  return bill;
}

void Customer::setOperator(Operator* _op){
  op = _op;

}


void Customer::talk(int minutes, Customer &other) {
  double cost;
  if(minutes <=0){
    return;
  }
  if (id !=  other.id) {
    cost = op->calculateTalkingCost(minutes, age);
    if((bill->check(cost)) == TRUE){
      bill->add(cost);
      totalSpentTalkingTime += minutes;
      op->addTalkingTime(minutes);
      other.totalSpentTalkingTime += minutes;
      if(op->getId() != other.op->getId()){
        other.op->addTalkingTime(minutes);
      }
    }
  }
}

void Customer::message(int num, const Customer &other){
  double cost;
  if(num <= 0){
    return;
  }
  if(id != other.id){
    cost = op->calculateMessageCost(num,op->getId(),other.op->getId());
    if(bill->check(cost) == TRUE){
      bill->add(cost);
      totalMessageSent += num;
      op->addTotalMessageSent(num);
    }
  }
}

void Customer::connection(double amount){
  if(amount > 0.0){
    double cost = op->calculateNetworkCost(amount);
    if(bill->check(cost)){
      bill->add(cost);
      totalInternetUsage += amount;
      op->addTotalInternetUsage(amount);
    }
  }
}


std::string Customer::toString() const{
  std::ostringstream str;
  str << "Customer #" << id <<" : " << std::fixed <<std::setprecision(2) <<bill->getTotalMoneySpent() <<std::fixed <<std::setprecision(2)<< bill->getCurrentDebt();
  return str.str(); 
} 


#endif
