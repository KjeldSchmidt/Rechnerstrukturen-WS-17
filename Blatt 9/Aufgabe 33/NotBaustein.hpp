#ifndef NOTBAUSTEIN_H
#define NOTBAUSTEIN_H

#include "Schaltbaustein.hpp"
#include <vector>

class NotBaustein : public Schaltbaustein {
    protected:
    private:
        std::vector<std::shared_ptr<Schaltbaustein>> inputs;
    public:
        virtual bool eval();
        virtual size_t getInputSize() const;
        virtual void setInput(size_t number,  std::shared_ptr<Schaltbaustein>  input);
        virtual std::shared_ptr<Schaltbaustein> getInput(size_t number);
        NotBaustein();
};
#endif
