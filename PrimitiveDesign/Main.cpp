//
// Main.cpp
//

#include <iostream>
#include <map>
#include <functional>
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

namespace Primitive_AbstractFactory
{
    void Run_AbstractFactory()
    {
        AbstractFactory* myFactory = new ConcreteFactory();
        Product1* myProduct1 = myFactory->CreateProduct1();
        Product2* myProduct2 = myFactory->CreateProduct2();
    }
    auto run_ab = []() {};
}

namespace Primitive_Builder
{
    void Run_Builder()
    {
        Builder* myBuilder = new ConcreteBuilder();
        Product* myProduct = myBuilder->Build();
    }
}

namespace Primitive_FactoryMethod
{
    void Run_FactoryMethod()
    {
        Creator* myCreator = new ConcreteCreator();
        Product* myProduct = myCreator->CreateProduct();
    }
}

namespace Primitive_Prototype
{
    void Run_Prototype()
    {
        Prototype* prototype1 = new ConcretePrototype();
        Prototype* prototype2 = prototype1->Clone();
    }
}

namespace Primitive_Singleton
{
    void Run_Singleton()
    {
        Singleton* singleton1 = Singleton::Instance();
        Singleton* singleton2 = Singleton::Instance();
    }
}

namespace Primitive_Adapter
{
    void Run_Adapter()
    {
        Adaptee* adaptee = new Adaptee();
        Adapter* adapter = new Adapter(adaptee);
        bool ret = adapter->DoAction();
    }
}

namespace Primitive_Bridge
{
    void Run_Bridge()
    {
        ConcreteImprementer1* impl1 = new ConcreteImprementer1();
        ConcreteImprementer1* impl2 = new ConcreteImprementer1();
        AbstractBridge* bridge1 = new ConcreteBridge(impl1);
        AbstractBridge* bridge2 = new ConcreteBridge(impl2);
        bridge1->Action();
        bridge2->Action();
    }
}

namespace Primitive_Composite
{
    void Run_Composite()
    {
        Composite* composite1 = new Composite(1);

        Leaf* leaf1 = new Leaf(2);
        composite1->Add(leaf1);

        Leaf* leaf2 = new Leaf(3);
        composite1->Add(leaf1);

        Composite* composite2 = new Composite(4);
        composite1->Add(composite2);
    }
}

namespace Primitive_Decorator
{
    void Run_Decorator()
    {
        ConcreteComponent* component = new ConcreteComponent();
        Decorator* decorator = new Decorator(component);

        decorator->Action();
    }
}

namespace Primitive_Flyweight
{
    void Run_Flyweight()
    {
        FlyweightFactory* factory = new FlyweightFactory();
        Flyweight* flyweightA = factory->GetFlyweight(1);
        Flyweight* flyweightB = factory->GetFlyweight(1);
        Flyweight* flyweightC = factory->GetFlyweight(2);
        Flyweight* flyweightD = factory->GetFlyweight(2);
    }
}

namespace Primitive_Proxy
{
    void Run_Proxy()
    {
        Proxy* proxy = new Proxy();

        proxy->Action();
        proxy->HeavyAction();
    }
}

namespace Primitive_ChainOfResponsibility
{
    void Run_ChainOfResponsibility()
    {
        ConcreteHandler3* handler3 = new ConcreteHandler3(nullptr);
        ConcreteHandler2* handler2 = new ConcreteHandler2(handler3);
        ConcreteHandler1* handler1 = new ConcreteHandler1(handler2);
        handler1->Request();
    }
}

namespace Primitive_Command
{
    void Run_Command()
    {
        Invoker* invoker = new Invoker();
        Receiver* receiver = new Receiver();
        ConcreteCommand* command1 = new ConcreteCommand(receiver);
        invoker->Add(command1);
        ConcreteCommand* command2 = new ConcreteCommand(receiver);
        invoker->Add(command2);
        invoker->Action();
    }
}

namespace Primitive_Mediator
{
    void Run_Mediator()
    {
        Mediator* mediator = new ConcreteMediator();
        Colleague* colleague1 = new ConcreteColleague1();
        Colleague* colleague2 = new ConcreteColleague2();
        mediator->Add(colleague1);
        mediator->Add(colleague2);
        colleague1->Set(mediator);
        colleague2->Set(mediator);
    }
}
namespace Primitive_Memento
{
    void Run_Memento()
    {
        Caretaker* container = new Caretaker();
        Originator* controller = new Originator();
        Memento* memento = controller->CreateMemento();
        container->Set(1, memento);
        memento = container->Get(1);
        controller->SetMemento(memento);
    }
}

namespace Primitive_Observer
{
    void Run_Observer()
    {
        ConcreteSubscriber subscriber;
        ConcreteObserver1 observer1;
        ConcreteObserver2 observer2;
        subscriber.Add(&observer1);
        subscriber.Add(&observer2);
        subscriber.Notify();
    }
}

namespace Primitive_State
{
    void Run_State()
    {
        Invoker invoker;
        invoker.Action(0);
        invoker.Action(1);
    }
}

namespace Primitive_Strategy
{
    void Run_Strategy()
    {
        Invoker invoker;
        invoker.Action(1);
        invoker.Action(2);
    }
}

namespace Primitive_TemplateMethod
{
    void Run_TemplateMethod()
    {
        ConcreteMethod method;
        method.Action();
    }
}

namespace Primitive_Visitor
{
    void Run_Visitor()
    {
        ConcreteAcceptor1 acceptor1;
        ConcreteAcceptor2 acceptor2;
        ConcreteVisitor1 visitor1;
        ConcreteVisitor1 visitor2;

        acceptor1.Accept(&visitor1);
        acceptor2.Accept(&visitor1);
        acceptor1.Accept(&visitor2);
        acceptor2.Accept(&visitor2);
    }
}

int main(int argc, char** argv)
{
    enum class DesignPattern
    {
        AbstractFactory,
        Builder,
        FactoryMethod,
        Prototype,
        Singleton,
        Adapter,
        Bridge,
        Composite,
        Decorator,
        Facade, // まだ欠番
        Flyweight,
        Proxy,
        ChainOfResponsibility,
        Command,
        Iterator,
        Mediator,
        Memento,
        Observer,
        State,
        Strategy,
        TemplateMethod,
        Visitor,
    };

    std::map<DesignPattern, std::function<void()>> container;
    container[DesignPattern::AbstractFactory] = Primitive_AbstractFactory::Run_AbstractFactory;
    container[DesignPattern::Builder] = Primitive_Builder::Run_Builder;
    container[DesignPattern::FactoryMethod] = Primitive_FactoryMethod::Run_FactoryMethod;
    container[DesignPattern::Prototype] = Primitive_Prototype::Run_Prototype;
    container[DesignPattern::Singleton] = Primitive_Singleton::Run_Singleton;
    container[DesignPattern::Adapter] = Primitive_Adapter::Run_Adapter;
    container[DesignPattern::Bridge] = Primitive_Bridge::Run_Bridge;
    container[DesignPattern::Composite] = Primitive_Composite::Run_Composite;
    container[DesignPattern::Decorator] = Primitive_Decorator::Run_Decorator;
    // Facadeは飛ばします。
    container[DesignPattern::Flyweight] = Primitive_Flyweight::Run_Flyweight;
    container[DesignPattern::Prototype] = Primitive_Proxy::Run_Proxy;
    container[DesignPattern::ChainOfResponsibility] = Primitive_ChainOfResponsibility::Run_ChainOfResponsibility;
    container[DesignPattern::Command] = Primitive_Command::Run_Command;
    // Iteratorは後回し
    container[DesignPattern::Mediator] = Primitive_Mediator::Run_Mediator;
    container[DesignPattern::Memento] = Primitive_Memento::Run_Memento;
    container[DesignPattern::Observer] = Primitive_Observer::Run_Observer;
    container[DesignPattern::State] = Primitive_State::Run_State;
    container[DesignPattern::Strategy] = Primitive_Strategy::Run_Strategy;
    container[DesignPattern::TemplateMethod] = Primitive_TemplateMethod::Run_TemplateMethod;
    container[DesignPattern::Visitor] = Primitive_Visitor::Run_Visitor;

    // Action!
    container[DesignPattern::Strategy]();

    std::cout << "Done!" << std::endl;
}