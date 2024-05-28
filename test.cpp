#include <iostream>
#include <vector>
using namespace std;
class general {
public:
    general() : y(0) {};
virtual int getX(){return 0;};
protected:
int x;
    int y;
};

class derive1 : public general { // Change access specifier to public
public:
    derive1() : x(10) {}
    derive1(int _x) : x(_x) {}
int getX() override{return this->x;};

int x;
protected:
    
};

class derive2 : public general { // Change access specifier to public
public:
    derive2(int _x) : x(_x) {};
int getX() override{return this->x;};

int x;
protected:
    
};

int main() {
    std::vector<general*> v;
    for (int i = 0; i < 5; i++) {
        v.push_back(new derive1(12));
        v.push_back(new derive2(24));
    }


    // Clean up memory by deleting the objects
   
    for (general* entity : v) {
            
                
                
                if (derive1* e = dynamic_cast<derive1*>(entity)) {
                    cout << "success";
                }else{
                    cout << "false";
                }
            }
        

    return 0;
}