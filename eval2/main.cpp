#include "Factory.h"
#include "Docs.h"


void printAllDocs(Document** d, int countDocs, Printer** p, int countPrinters)
{
    for (int i = 0; i < countDocs; i++)
    {
        for (int j = 0; j < countPrinters; j++)
        {
            d[i]->printOn(p[j]);
        }
    }
}

int main()
{
    PrinterFactory::init();

    //Printer singleton WITHOUT modify their code (Homework way)
    Printer* p[] = {
        PrinterFactory::getInstance(1),
        PrinterFactory::getInstance(2),
        PrinterFactory::getInstance(3),
        PrinterFactory::getInstance(4),
        PrinterFactory::getInstance(5)
    };

    //Document singleton MODIFYING the class code (Normal way)
    Document* d[] = {
        &PlainDocument::getInstance(),
        &RichDocument::getInstance(),
        &PresentationDocument::getInstance()
    };
    printAllDocs(d,3,p,5);
}
