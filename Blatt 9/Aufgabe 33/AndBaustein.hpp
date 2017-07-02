#ifndef ANDBAUSTEIN_H
#define ANDBAUSTEIN_H

#include "Schaltbaustein.hpp"
#include <vector>

class AndBaustein : public Schaltbaustein {
    protected:
    private:
        std::vector<std::shared_ptr<Schaltbaustein>> inputs;
    public:
        bool eval();
        size_t getInputSize() const;
        void setInput(size_t number,  std::shared_ptr<Schaltbaustein>  input);
        std::shared_ptr<Schaltbaustein> getInput(size_t number);
        AndBaustein();
};
#endif
