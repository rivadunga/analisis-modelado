#pragma once
#include<map>
#include"Docs.h"

class PrinterFactory
{

static map<int,Printer*>* dataSet;

public:
  static void init()
  {
    dataSet = new map<int,Printer*>;
  }
  static Printer* getInstance(int type)
  {
    //Map only one instance
    Printer* printer = (*dataSet)[type];
    //If it doesn't exist, create a new one
    if (printer == 0){
        switch(type){
          case 1:
            printer = new LaserPrinter;
            break;
          case 2:
            printer = new InjectionPrinter;
            break;
          case 3:
            printer = new PdfPrinter;
            break;
          case 4:
            printer = new PostscriptPrinter;
            break;
          case 5:
            printer = new PortablePrinter;
            break;
        }
        (*dataSet)[type] = printer;
    }
    return printer;
  }
};
map<int,Printer*>* PrinterFactory::dataSet = 0;
