#include <string>
using namespace std;

class Singleton
{
private:
   Singleton(){
   }
   string hour;


public:
   static Singleton& getInstance()
   {
      static Singleton instance;
      return instance;
   }
   void setHour(string hour){
		this->hour = hour;
   }

   string getHora(){
		return this->hour;
   }

};
