#ifndef CESAR
#define CESAR

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

namespace cifra{
    class Cesar
    {
        public: 
            Cesar();
            void encripte(string, string, int); 
    };
}
#endif