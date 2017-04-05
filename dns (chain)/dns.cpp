#include<iostream>
#include<string>
#include <sstream>

using namespace std;

class Server {
    Server * next;

    public:
    Server() {
        next = 0;
    }
    void setNext(Server * n) {
        next = n;
    }
    void add(Server * n) {
        if (next) next->add(n);
        else next = n;
    }

    virtual void handle(string ip) {
        next -> handle(ip);
    }
};

class Server1: public Server {
    string ips [10] = {"192.168.1.1", "192.168.1.2", "192.168.1.3", "192.168.1.4", "192.168.1.5",
                       "192.168.1.6", "192.168.1.7", "192.168.1.8", "192.168.1.9", "192.168.1.10" };
    public:
    void handle(string ip) {
        bool found = false;
        for (int i = 0; i < 10; i++)
            if (ips[i] == ip) found = true;

        if (found){
            cout << "   Aceptado en Google" << endl;
        }else{
            cout << "   Procesado Google" << endl;
            Server::handle(ip);
        }
    }
};

class Server2: public Server {
    string ips [10] = {"192.168.2.1", "192.168.2.2", "192.168.2.3", "192.168.2.4", "192.168.2.5",
                       "192.168.2.6", "192.168.2.7", "192.168.2.8", "192.168.2.9", "192.168.2.10" };
    public:
    void handle(string ip) {
        bool found = false;
        for (int i = 0; i < 10; i++)
            if (ips[i] == ip) found = true;

        if (found){
            cout << "   Aceptado en Yahoo" << endl;
        }else{
            cout << "   Procesado Yahoo" << endl;
            Server::handle(ip);
        }
    }
};

class Server3: public Server {
    string ips [10] = {"192.168.3.1", "192.168.3.2", "192.168.3.3", "192.168.3.4", "192.168.3.5",
                       "192.168.3.6", "192.168.3.7", "192.168.3.8", "192.168.3.9", "192.168.3.10" };
    public:
    void handle(string ip) {
        bool found = false;
        for (int i = 0; i < 10; i++)
            if (ips[i] == ip) found = true;

        if (found){
            cout << "   Aceptado en Uber" << endl;
        }else{
            cout << "   Procesado Uber" << endl;
            Server::handle(ip);
        }
    }
};

class Server4: public Server {
    string ips [10] = {"192.168.4.1", "192.168.4.2", "192.168.4.3", "192.168.4.4", "192.168.4.5",
                       "192.168.4.6", "192.168.4.7", "192.168.4.8", "192.168.4.9", "192.168.4.10"};
    public:
    void handle(string ip) {
        bool found = false;
        for (int i = 0; i < 10; i++)
            if (ips[i] == ip) found = true;

        if (found){
            cout << "   Aceptado en Arbnb" << endl;
        }else{
            cout << "   Procesado Arbnb" << endl;
            Server::handle(ip);
        }
    }
};

class Server5: public Server {
    string ips [10] = {"192.168.5.1", "192.168.5.2", "192.168.5.3", "192.168.5.4", "192.168.5.5",
                       "192.168.5.6", "192.168.5.7", "192.168.5.8", "192.168.5.9", "192.168.5.10"};
    public:
    void handle(string ip) {
        bool found = false;
        for (int i = 0; i < 10; i++)
            if (ips[i] == ip) found = true;

        if (found){
            cout << "   Aceptado en Maildots" << endl;
        }else{
            cout << "   Procesado Maildots" << endl;
            Server::handle(ip);
        }
    }
};




int main() {

    Server1 s1;
    Server2 s2;
    Server3 s3;
    Server4 s4;
    Server5 s5;

    s1.add(&s2);
    s2.add(&s3);
    s3.add(&s4);
    s4.add(&s5);

    s1.setNext(&s2);
    s2.setNext(&s3);
    s3.setNext(&s4);
    s4.setNext(&s5);

    for (int j = 1; j <= 10; j++) {
        for (int i = 1; i <= 5; i++){
            stringstream sstm;
            sstm << "192.168." << i << "." << j;
            string ip = sstm.str();
            cout << "IP: " << ip << endl;
            s1.handle(ip);
        }
    }

    return 0;
}
