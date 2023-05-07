#include <iostream>
#include "Cpp17_NesteadNamespaces.hpp"

class Singleton
{
    inline static Singleton *m_instance{nullptr};
    inline static int m_someVariable{123};

public:
    static Singleton *getInstance()
    {
        if (!m_instance)
        {
            m_instance = new Singleton();
        }
        return m_instance;
    }
    void printSomething()
    {
        std::cout << "This is call of the singleton class\n";
    }
};
namespace first::second::third
{
    enum class ProductIDs
    {
        PRODUCT_A,
        PRODUCT_B,
        PRODUCT_C,
    };
    class IProduct
    {
    public:
        virtual void printSomething() = 0;
    };
    class ProductA : public IProduct
    {
        virtual void printSomething() override
        {
            std::cout << "This is the virtual function of the ProductA \n";
        }
    };
    class ProductB : public IProduct
    {
        virtual void printSomething() override
        {
            std::cout << "This is the virtual function of the ProductB \n";
        }
    };

    class Factory
    {
    public:
        IProduct *createProduct(ProductIDs productId)
        {
            IProduct *productPtr{nullptr};
            switch (productId)
            {
            case ProductIDs::PRODUCT_A:
            {
                productPtr = new ProductA();
                break;
            }
            case ProductIDs::PRODUCT_B:{
                productPtr = new ProductB();
                break;
            }
            default:
                std::cout << "Unsupported product\n";
            }
            return productPtr;
        }
    };
}

using factory = first::second::third::Factory;
using iproduct = first::second::third::IProduct;

void Cpp17_NesteadNamespaces::nestName_SimpleExample()
{
    Singleton::getInstance()->printSomething();
    std::unique_ptr<factory> factoryObjPtr = std::unique_ptr<factory>();
    iproduct* productA = factoryObjPtr->createProduct(first::second::third::ProductIDs::PRODUCT_A);
    iproduct* productB = factoryObjPtr->createProduct(first::second::third::ProductIDs::PRODUCT_B);
    productA->printSomething();
    productB->printSomething();
}