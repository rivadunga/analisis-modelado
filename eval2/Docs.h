#pragma once
#include<iostream>
#include<map>

using namespace std;

class Printer;
class Document
{
protected:
    string type;
public:
    virtual void printOn(Printer*) = 0;
    string getType(){return type;}
};

class PlainDocument : public Document
{
private:
    string text;
    PlainDocument()
    {
        type = "plainDoc";
        text = "hola";
    }
public:
    static PlainDocument& getInstance()
    {
          static PlainDocument instance;
          return instance;
    }
    string getText(){return text;}
    void printOn(Printer* p);
};


class RichDocument : public Document
{
private:
    string image;
    string format;
    RichDocument()
    {
        type = "richDoc";
        image = "hola.png";
        format = "image/png";
    }
public:
    static RichDocument& getInstance()
    {
          static RichDocument instance;
          return instance;
    }
    string getImage(){return image;}
    string getFormat(){return format;}
    void printOn(Printer* p);
};

class PresentationDocument : public Document
{
private:
    string name;
    string phone;
    PresentationDocument()
    {
        type = "presentationDoc";
        name = "Erick";
        phone = "53123122";
    }
public:
    static PresentationDocument& getInstance()
    {
          static PresentationDocument instance;
          return instance;
    }
    string getName(){return name;}
    string getPhone(){return phone;}
    void printOn(Printer* p);
};

class Printer
{
public:
    virtual void print(PlainDocument*) = 0;
    virtual void print(RichDocument*) = 0;
    virtual void print(PresentationDocument*) = 0;
};

class LaserPrinter : public Printer
{
public:
    void print(PlainDocument* d)
    {
        cout << "Laser:: " << d->getType() << " -> " << d->getText() << endl;
    }
    void print(RichDocument* d)
    {
        cout << "Laser:: " << d->getType() << " -> " << d->getImage() << endl;
    }
    void print(PresentationDocument* d)
    {
        cout << "Laser:: " << d->getType() << " -> " << d->getName() << endl;
    }
};

class InjectionPrinter : public Printer
{
public:
    void print(PlainDocument* d)
    {
        cout << "Injection:: " << d->getType() << " -> " << d->getText() << endl;
    }
    void print(RichDocument* d)
    {
        cout << "Injection:: " << d->getType() << " -> " << d->getImage() << endl;
    }
    void print(PresentationDocument* d)
    {
        cout << "Injection:: " << d->getType() << " -> " << d->getName() << endl;
    }
};

class PdfPrinter : public Printer
{
public:
    void print(PlainDocument* d)
    {
        cout << "Pdf:: " << d->getType() << " -> " << d->getText() << endl;
    }
    void print(RichDocument* d)
    {
        cout << "Pdf:: " << d->getType() << " -> " << d->getImage() << endl;
    }
    void print(PresentationDocument* d)
    {
        cout << "Pdf:: " << d->getType() << " -> " << d->getName() << endl;
    }
};


class PostscriptPrinter : public Printer
{
public:
    void print(PlainDocument* d)
    {
        cout << "Postscript:: " << d->getType() << " -> " << d->getText() << endl;
    }
    void print(RichDocument* d)
    {
        cout << "Postscript:: " << d->getType() << " -> " << d->getImage() << endl;
    }
    void print(PresentationDocument* d)
    {
        cout << "Postscript:: " << d->getType() << " -> " << d->getName() << endl;
    }
};

class PortablePrinter : public Printer
{
public:
    void print(PlainDocument* d)
    {
        cout << "Portable:: " << d->getType() << " -> " << d->getText() << endl;
    }
    void print(RichDocument* d)
    {
        cout << "Portable:: " << d->getType() << " -> " << d->getImage() << endl;
    }
    void print(PresentationDocument* d)
    {
        cout << "Portable:: " << d->getType() << " -> " << d->getName() << endl;
    }
};


void PlainDocument::printOn(Printer* p){ p->print(this); }
void RichDocument::printOn
(Printer* p){ p->print(this); }
void PresentationDocument::printOn(Printer* p){ p->print(this); }
