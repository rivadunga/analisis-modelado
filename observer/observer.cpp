#include <iostream>
#include <string>
#include <vector>

class Observer;

class Subject {
  protected:
    std::vector < class Observer * > listObservers;
  int i;
  public:
    Subject() {
      i = 0;
    }

  void registerObserver(Observer * _observer) {
    listObservers.push_back(_observer);
  }
};

class Nieto: public Subject {
  public: Nieto() {}

    void notify(std::string news);
};

class Trump: public Subject {
  public: Trump() {}

    void notify(std::string news);

};

class Observer {
  protected:
    Subject subject;

  public:
    Observer() {}
  virtual void update(std::string news) = 0;
};

class Reforma: public Observer {
  protected:

    public: Reforma(Subject _subject) {
    this - > subject = _subject;
    this - > subject.registerObserver(this);
  }

    void update(std::string news) {
    std::cout << "Reforma: " << news << std::endl;
  }
};

class Televisa: public Observer {
  protected:

    public: Televisa(Subject _subject) {
    this - > subject = _subject;
    this - > subject.registerObserver(this);
  }

    void update(std::string news) {
    std::cout << "Televisa: " << news << std::endl;
  }
};

class NBC: public Observer {
  protected:

    public: NBC(Subject _subject) {
    this - > subject = _subject;
    this - > subject.registerObserver(this);
  }

    void update(std::string news) {
    std::cout << "NBC: " << news << std::endl;
  }
};

void Trump::notify(std::string news) {
  int i = 0;

  while (listObservers[i] != nullptr) {
    listObservers[i] - > update(news);
  }
}

void Nieto::notify(std::string news) {
  int i = 0;

  while (listObservers[i] != nullptr) {
    listObservers[i] - > update(news);
  }
}

int main() {

}
