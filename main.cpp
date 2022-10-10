#include <iostream>
#include "flashdrive_3_0.h"
#include <stdexcept> 
using namespace std;


int main( )
{
  
  FlashDrive empty;
  FlashDrive drive1( 10, 0, false );
  FlashDrive drive2( 20, 0, false );
  
  drive1.plugIn( );
  drive1.formatDrive( );
  drive1.writeData( 5 );
  drive1.pullOut( );
  
  drive2.plugIn( );
  drive2.formatDrive( );
  drive2.writeData( 1 );
  drive2.pullOut( );
  
  // read in a FlashDrive... 
  // the class designer for FlashDrive (that's you!)
  // gets to decide which fields matter and should be read in

  cout << "Please enter the sample drives storage capacity:";
  FlashDrive sample;
  cin >> sample;
  
  // print out a FlashDrive...
  // the class designer for FlashDrive (that's you!)
  // gets to decide which fields matter and should be printed
  cout << sample << endl;

  
  FlashDrive combined = drive1 + drive2;
  cout << "this drive's filled to " << combined.getUsed( ) << endl;
  
  FlashDrive other = combined - drive1;
  cout << "the other cup's filled to " << other.getUsed( ) << endl;
  if (combined > other) {
    cout << "looks like combined is bigger..." << endl;
  }
  else {
    cout << "looks like other is bigger..." << endl;
  }
  
  if (drive2 > other) {
    cout << "looks like drive2 is bigger..." << endl;
  }
  else {
    cout << "looks like other is bigger..." << endl;
  }
  if (drive2 < drive1) {
    cout << "looks like drive2 is smaller..." << endl;
  }
  else {
    cout << "looks like drive1 is smaller..." << endl;
  }
  
  //-------------------------------------------------------------------------
  // let's throw some exceptions...
  try {
    empty = empty - combined;
    cout << "something not right here..." << endl;
  } catch(logic_error& e) {
  // an exception should get thrown... 
  // so the lines of code here should
  // be run, not the cout statement..
  cout << e.what() << endl;

  }
  
  try {
    drive2.writeData( 10000 );
    cout << "something not right here..." << endl;
  } catch( logic_error& e ) {
  // an exception should get thrown... 
  // so the lines of code here should
  // be run, not the cout statement...
  cerr << e.what() << endl;
  
  
  }
  
  try {
    FlashDrive f( -1, -1, false );
    cout << "something not right here..." << endl;
  } catch( logic_error& e ) {
  // an exception should get thrown... 
  // so the lines of code here should
  // be run, not the cout statement...
  
  cerr << e.what() << endl;
  }
}