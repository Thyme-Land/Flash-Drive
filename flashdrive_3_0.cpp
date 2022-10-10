  #include "flashdrive_3_0.h"
  #include <string>
  #include <stdexcept> 
  using namespace std;
  
  
  
  FlashDrive::FlashDrive()
  {
      my_StorageCapacity = 0;
      my_StorageUsed = 0;
      my_IsPluggedIn = false;
  }
  
  FlashDrive::FlashDrive(int capacity, int used, bool pluggedIn)
  {
      my_StorageCapacity = capacity;
      my_StorageUsed = used;
      my_IsPluggedIn = pluggedIn;
      
      if (my_StorageCapacity < 0)
        throw logic_error("error, can't have negitive number for Flashdrive capacity.");
      
      if (my_StorageUsed < 0)
        throw logic_error("error, can't have negitive number for storage used.");
    
  }
  
  void FlashDrive::plugIn()
  {
      my_IsPluggedIn = true;
  }
  
  void FlashDrive::pullOut()
  {
      my_IsPluggedIn = false;
  }
  
  void FlashDrive::writeData(int amount)
  {
      my_StorageUsed += amount;
      
      if(my_StorageUsed > my_StorageCapacity)
        throw logic_error("error, not enough storage capacity to write this much data.");
  }
  
  void FlashDrive::eraseData(int amount)
  {
      my_StorageUsed -= amount;
  }
  
  void FlashDrive::formatDrive()
  {
      my_StorageUsed = 0;
  }
  
  int FlashDrive::getCapacity()
  {
      return (my_StorageCapacity);
  }
  
  void FlashDrive::setCapacity(int amount)
  {
      my_StorageCapacity = amount;
      
      if (my_StorageCapacity < 0)
        throw logic_error("error, can't have negitive number for Flashdrive capacity.");
  }
  
  int FlashDrive::getUsed()
  {
      return (my_StorageUsed);
  }
  
  void FlashDrive::setUsed(int amount)
  {
      my_StorageUsed = amount;
      
      if (my_StorageUsed < 0)
        throw logic_error("error, can't have negitive number for storage used.");
  }
  
  bool FlashDrive::isPluggedIn()
  {
      return (my_IsPluggedIn);
  }
  
  /* Check for errors and print error messages */
  void FlashDrive::checkForErrors(int new_Capacity, int new_StorageUsed)
  {
      if (new_StorageUsed > new_Capacity)
      {
          cout << "error: capacity exceeded by " << new_StorageUsed - new_Capacity << " kilobytes\n";
      }
      if (new_Capacity < 0)
      {
          cout << "error: negative capacity (" << new_Capacity << ")\n";
      }
      if (new_StorageUsed < 0)
      {
          cout << "error: negative storage used (" << new_StorageUsed << ")\n";
      }
  }
   
  FlashDrive operator+(const FlashDrive& f1, const FlashDrive& f2){
    FlashDrive f3;
    
    f3.my_StorageUsed = f1.my_StorageUsed + f2.my_StorageUsed;
    
    if (f1.my_StorageCapacity > f2.my_StorageCapacity){
      f3.my_StorageCapacity = f1.my_StorageCapacity;
      
    }else {
      f3.my_StorageCapacity = f2.my_StorageCapacity;
    }
    
    return f3;
  
  }
  
   bool operator<(const FlashDrive& f1, const FlashDrive& f2){
    bool storageUsed = false;
    if (f1.my_StorageUsed < f2.my_StorageUsed){
      storageUsed = true;
    }
    return storageUsed;
  }
  
  bool operator>(const FlashDrive& f1, const FlashDrive& f2){
    bool storageUsed = false;
    if (f1.my_StorageUsed > f2.my_StorageUsed){
      storageUsed = true;
    }
    return storageUsed;
  }
  
  FlashDrive operator-(const FlashDrive& f1, const FlashDrive& f2){
    int error;
    FlashDrive f3;
    
    if (f1.my_StorageCapacity > f2.my_StorageCapacity){
      f3.my_StorageCapacity = f1.my_StorageCapacity;
      
    }else {
      f3.my_StorageCapacity = f2.my_StorageCapacity;
    }
    
    f3.my_StorageUsed = f1.my_StorageUsed - f2.my_StorageUsed;
    
    if(f3.my_StorageUsed < 0)
       throw logic_error("error in - operator causing negitive storage used.");
      
    if (f3.my_StorageCapacity < 0)
        throw logic_error("error in - operator causing negitive Flashdrive capacity.");  
    
    return f3;
  }
  
  ostream& operator <<(ostream& out, const FlashDrive& f1){
    return out << "StorageCapacity: " << f1.my_StorageCapacity << endl;
  }
  
  std::istream& operator >>(std::istream& in, FlashDrive& f1){
    return in >> f1.my_StorageCapacity;
  }
  

