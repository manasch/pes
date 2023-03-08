#include <iostream>
#include <set>
#include <string>
// TODO Execute this program
// TODO and you notice this
// TODO ordered set is unordered
// TODO do something to set this
// TODO in order

int main() {
    std::set<std::string*> ssp;
    ssp.insert(new std::string("Anteater"));
    ssp.insert(new std::string("Wombat"));
    ssp.insert(new std::string("Lemur"));
    ssp.insert(new std::string("Penguin"));
    for (std::set<std::string*>::const_iterator i = ssp.begin(); i != ssp.end(); ++i) {
        std::cout << **i << std::endl;
    }
    // TODO - dil mange more(majege)/buttermilk
    
    return 0;
}
