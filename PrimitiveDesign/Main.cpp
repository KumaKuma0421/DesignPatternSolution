//
// Main.cpp
//

#include <iostream>
#include "AbstractFactory.h"
#include "Builder.h"
#include "FactoryMethod.h"
#include "Prototype.h"
#include "Singleton.h"
#include "Adapter.h"
#include "Bridge.h"
#include "Composite.h"
#include "Decorator.h"
#include "Flywieght.h"
#include "Proxy.h"
#include "ChainOfResponsibility.h"
#include "Command.h"
#include "Iterator.h"
#include "Mediator.h"
#include "Memento.h"
#include "Observer.h"
#include "State.h"
#include "Strategy.h"
#include "TemplateMethod.h"
#include "Visitor.h"

int main(int argc, char** argv)
{
    // AbstractFactory
    {
        Primitive_AbstractFactory::AbstractFactory* myFactory = new Primitive_AbstractFactory::ConcreteFactory();
        Primitive_AbstractFactory::Product1* myProduct1 = myFactory->CreateProduct1();
        Primitive_AbstractFactory::Product2* myProduct2 = myFactory->CreateProduct2();
    }

    // Builder
    {
        Primitive_Builder::Builder* myBuilder = new Primitive_Builder::ConcreteBuilder();
        Primitive_Builder::Product* myProduct = myBuilder->Build();
    }

    // FactoryMethod
    {
        Primitive_FactoryMethod::Creator* myCreator = new Primitive_FactoryMethod::ConcreteCreator();
        Primitive_FactoryMethod::Product* myProduct = myCreator->CreateProduct();
    }

    // Prototype
    {
        Primitive_Prototype::Prototype* prototype1 = new Primitive_Prototype::ConcretePrototype();
        Primitive_Prototype::Prototype* prototype2 = prototype1->Clone();
    }

    // Singleton
    {
        Primitive_Singleton::Singleton* singleton1 = Primitive_Singleton::Singleton::Instance();
        Primitive_Singleton::Singleton* singleton2 = Primitive_Singleton::Singleton::Instance();
    }

    // Adapter
    {
        Primitive_Adapter::Adaptee* adaptee = new Primitive_Adapter::Adaptee();
        Primitive_Adapter::Adapter* adapter = new Primitive_Adapter::Adapter(adaptee);
        bool ret = adapter->DoAction();
    }

    // Bridge
    {
        Primitive_Bridge::ConcreteImprementer1* impl1 = new Primitive_Bridge::ConcreteImprementer1();
        Primitive_Bridge::ConcreteImprementer1* impl2 = new Primitive_Bridge::ConcreteImprementer1();
        Primitive_Bridge::AbstractBridge* bridge1 = new Primitive_Bridge::ConcreteBridge(impl1);
        Primitive_Bridge::AbstractBridge* bridge2 = new Primitive_Bridge::ConcreteBridge(impl2);
        bridge1->Action();
        bridge2->Action();
    }

    // Composite
    {
        Primitive_Composite::Composite* composite1 = new Primitive_Composite::Composite(1);
        
        Primitive_Composite::Leaf* leaf1 = new Primitive_Composite::Leaf(2);
        composite1->Add(leaf1);

        Primitive_Composite::Leaf* leaf2 = new Primitive_Composite::Leaf(3);
        composite1->Add(leaf1);

        Primitive_Composite::Composite* composite2 = new Primitive_Composite::Composite(4);
        composite1->Add(composite2);
    }

    // Decorator
    {
        Primitive_Decorator::ConcreteComponent* component = new Primitive_Decorator::ConcreteComponent();
        Primitive_Decorator::Decorator* decorator = new Primitive_Decorator::Decorator(component);

        decorator->Action();
    }

    // Facadeは飛ばします。

    // Flyweight
    {
        Primitive_Flyweight::FlyweightFactory* factory = new Primitive_Flyweight::FlyweightFactory();
        Primitive_Flyweight::Flyweight* flyweightA = factory->GetFlyweight(1);
        Primitive_Flyweight::Flyweight* flyweightB = factory->GetFlyweight(1);
        Primitive_Flyweight::Flyweight* flyweightC = factory->GetFlyweight(2);
        Primitive_Flyweight::Flyweight* flyweightD = factory->GetFlyweight(2);
    }

    // Proxy
    {
        Primitive_Proxy::Proxy* proxy = new Primitive_Proxy::Proxy();

        proxy->Action();
        proxy->HeavyAction();
    }

    // ChainOfResponsibility
    {
        Primitive_ChainOfResponsibility::ConcreteHandler3* handler3 = new Primitive_ChainOfResponsibility::ConcreteHandler3(nullptr);
        Primitive_ChainOfResponsibility::ConcreteHandler2* handler2 = new Primitive_ChainOfResponsibility::ConcreteHandler2(handler3);
        Primitive_ChainOfResponsibility::ConcreteHandler1* handler1 = new Primitive_ChainOfResponsibility::ConcreteHandler1(handler2);
        handler1->Request();
    }

    // Command
    {
        Primitive_Command::Invoker* invoker = new Primitive_Command::Invoker();
        Primitive_Command::Receiver* receiver = new Primitive_Command::Receiver();
        Primitive_Command::ConcreteCommand* command1 = new Primitive_Command::ConcreteCommand(receiver);
        invoker->Add(command1);
        Primitive_Command::ConcreteCommand* command2 = new Primitive_Command::ConcreteCommand(receiver);
        invoker->Add(command2);
        invoker->Action();
    }

    // Iteratorは後回し

    // Mediator
    {
        Primitive_Mediator::Mediator* mediator = new Primitive_Mediator::ConcreteMediator();
        Primitive_Mediator::Colleague* colleague1 = new Primitive_Mediator::ConcreteColleague1();
        Primitive_Mediator::Colleague* colleague2 = new Primitive_Mediator::ConcreteColleague2();
        mediator->Add(colleague1);
        mediator->Add(colleague2);
        colleague1->Set(mediator);
        colleague2->Set(mediator);
    }

    // Memento
    {
        Primitive_Memento::Caretaker* container = new Primitive_Memento::Caretaker();
        Primitive_Memento::Originator* controller = new Primitive_Memento::Originator();
        Primitive_Memento::Memento* memento = controller->CreateMemento();
        container->Set(1, memento);
        memento = container->Get(1);
        controller->SetMemento(memento);
    }

    // Observer
    {
        Primitive_Observer::ConcreteSubscriber subscriber;
        Primitive_Observer::ConcreteObserver1 observer1;
        Primitive_Observer::ConcreteObserver2 observer2;
        subscriber.Add(&observer1);
        subscriber.Add(&observer2);
        subscriber.Notify();
    }

    // State
    {
        Primitive_State::Invoker invoker;
        invoker.Action(0);
        invoker.Action(1);
    }

    // Strategy
    {
        Primitive_Strategy::Invoker invoker;
        invoker.Action(1);
        invoker.Action(2);
    }

    // TemplateMethod
    {
        Primitive_TemplateMethod::ConcreteMethod method;
        method.Action();
    }

    // Visitor
    {
        Primitive_Visitor::ConcreteAcceptor1 acceptor1;
        Primitive_Visitor::ConcreteAcceptor2 acceptor2;
        Primitive_Visitor::ConcreteVisitor1 visitor1;
        Primitive_Visitor::ConcreteVisitor1 visitor2;

        acceptor1.Accept(&visitor1);
        acceptor2.Accept(&visitor1);
        acceptor1.Accept(&visitor2);
        acceptor2.Accept(&visitor2);
    }

    std::cout << "Hello World!" << std::endl;
}