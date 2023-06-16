// =========================================================
// File: bill.h
// Author: Ethan Luna Cadó
// Date: 30/05/2023
// Description: Clase Bill
// =========================================================

#ifndef BILL_H
#define BILL_H

class Bill {
private:
  double limitAmount, currentDebt, totalMoneySpent;

public:
  Bill();
  Bill(double);
  Bill(const Bill&);

  inline double getLimitAmount() const;
  inline double getCurrentDebt() const;
  inline double getTotalMoneySpent() const;

  void add(double);
  void pay(double);
  void changeTheLimit(double);
  bool check(double) const;
  
};

Bill::Bill() {
    limitAmount = 0;
    currentDebt = 0;
    totalMoneySpent = 0;
};

Bill::Bill(double _limitAmount){
    if(_limitAmount > 0.0){
        limitAmount = _limitAmount;
    }else{limitAmount = 0.0;}
    currentDebt = 0.0;
    totalMoneySpent = 0.0;
}; 

Bill::Bill(const Bill& other){   
  limitAmount = other.limitAmount;
  currentDebt = other.currentDebt;
  totalMoneySpent = other.totalMoneySpent;
}

double Bill::getLimitAmount() const{
    return limitAmount;
}

double Bill::getCurrentDebt() const{
    return currentDebt;
}

double Bill::getTotalMoneySpent() const{
    return totalMoneySpent;

}

void Bill::add(double addition){
    if (addition > 0){
        currentDebt += addition;
        //totalMoneySpent += addition;
    }  
};

void Bill::pay(double payment){
    if (payment > 0){
      if(payment >= currentDebt){
            payment = currentDebt; 
            currentDebt -= payment;
            totalMoneySpent += payment;
      } else{
          currentDebt -= payment;
          totalMoneySpent += payment;
      }
    }  
};

void Bill::changeTheLimit(double neoLimit){
    if(neoLimit > 0){
        limitAmount = neoLimit;
    }
};

bool Bill::check(double quantity) const{
    if((quantity + currentDebt)<limitAmount){
        return true;
    } else {
        return false;
    
    }
};



#endif
