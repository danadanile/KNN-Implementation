#include "VectorUnclassified.h"
//#include "VectorMap.h"

//#include "DefaultIO.h"

#include "sstream"
using namespace std;
int main() {
    try {
        std::string str = "5.4,3.9,1.7,0.4\n4.6,3.4,1.4,0.3\n5.0,3.4,1.5,0.2\n4.4,2.9,1.4,0.2\n4.9,3.1,1.5,0.1\n5.4,3.7,1.5,0.2\n4.8,3.4,1.6,0.2\n4.8,3.0,1.4,0.1\n";
        std::stringstream input_stream(str);
        VectorUnclassified my_vec(input_stream);
        cout<<"hi"<<endl;
    } catch (const invalid_argument &e) {
        cout << e.what() << endl;
    }
    return 0;
}
