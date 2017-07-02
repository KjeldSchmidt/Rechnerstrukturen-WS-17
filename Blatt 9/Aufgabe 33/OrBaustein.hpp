#ifndef ORBAUSTEIN_H
#define ORBAUSTEIN_H

#include "Schaltbaustein.hpp"
class OrBaustein : public Schaltbaustein {
    protected:
    private:
    public:
        virtual bool eval();
        virtual size_t getInputSize() const;
        virtual void setInput(size_t number,  std::shared_ptr<Schaltbaustein>  input);
        virtual std::shared_ptr<Schaltbaustein> getInput(size_t number);
        OrBaustein();
};
#endif
