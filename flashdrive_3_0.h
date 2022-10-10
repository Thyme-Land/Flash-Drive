#ifndef FLASHDRIVE_H
#define FLASHDRIVE_H
#include <iostream>

class FlashDrive
{
public:
  FlashDrive();
  FlashDrive(int capacity, int used, bool pluggedIn);
  
  void plugIn();
  void pullOut();
  void writeData(int amount);
  void eraseData(int amount);
  void formatDrive();

  int getCapacity();
  void setCapacity(int amount);
  int getUsed();
  void setUsed(int amount);
  bool isPluggedIn();

  /* Check for errors and print error messages */
  void checkForErrors(int new_Capacity, int new_StorageUsed);
  
  friend FlashDrive operator+(const FlashDrive& f1, const FlashDrive& f2);
  friend bool operator<(const FlashDrive& f1, const FlashDrive& f2);
  friend bool operator>(const FlashDrive& f1, const FlashDrive& f2);
  friend FlashDrive operator-(const FlashDrive& f1, const FlashDrive& f2);
  friend std::ostream& operator <<(std::ostream& out, const FlashDrive& f1);
  friend std::istream& operator >>(std::istream& in, FlashDrive& f1);
  
private:

  int my_StorageCapacity; // in kilobytes
  int my_StorageUsed;     // in kilobytes
  bool my_IsPluggedIn;    // am I attached to a computer?
};



#endif